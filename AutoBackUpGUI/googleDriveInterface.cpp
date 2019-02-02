#include "googleDriveInterface.h"

googleDriveInterface::googleDriveInterface(QObject *parent) : QObject(parent){
	networkManager = new QNetworkAccessManager(this);
}

googleDriveInterface::~googleDriveInterface() {
}

void
googleDriveInterface::getAuthentication() {
	qDebug() << "Getting authentication for Goolge Drive";
	//setup authorization flow
	google = new QOAuth2AuthorizationCodeFlow(this);
	google->setScope("https://www.googleapis.com/auth/drive"); //scope to give full access to google drive

	QJsonDocument credentials = getCredentials("googleDriveCredentials.json"); //json file data is loaded into credentials

	//parse JSON
	const auto object = credentials.object();
	const auto settingsObject = object["installed"].toObject();
	const QUrl authUri(settingsObject["auth_uri"].toString());
	const auto clientID = settingsObject["client_id"].toString();
	const QUrl tokenUri(settingsObject["token_uri"].toString());
	const auto clientSecret(settingsObject["client_secret"].toString());
	const auto redirectUris = settingsObject["redirect_uris"].toArray();
	const QUrl redirectUri(redirectUris[0].toString()); //get first URI
	const auto port = static_cast<quint16>(redirectUri.port()); // port needed to for QOAuthHttpServerReplyHandler

	google->setAuthorizationUrl(authUri);
	google->setClientIdentifier(clientID);
	google->setAccessTokenUrl(tokenUri);
	google->setClientIdentifierSharedKey(clientSecret);

	auto replyHandler = new QOAuthHttpServerReplyHandler(port, this);
	google->setReplyHandler(replyHandler);
	
	QObject::connect(google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl); //this connection opens authorization URL in user's default browser
	QObject::connect(google, SIGNAL(granted()), this, SLOT(slotSetAuthToken())); //save token when access is granted

	google->grant(); //start authorization process
}

QJsonDocument
googleDriveInterface::getCredentials(const QString fileName) {
	QFile loadFile(fileName);

	if (!loadFile.open(QIODevice::ReadOnly)) {
		qDebug() << "unable to open JSON file:" << loadFile.errorString();
	}

	QByteArray credentialsData = loadFile.readAll();
	QJsonDocument credentialsDoc(QJsonDocument::fromJson(credentialsData));
	loadFile.close();
	return credentialsDoc;
}

void
googleDriveInterface::refreshAuthentication() {
	qDebug() << "Refreshing access token";
	QJsonDocument credentials = getCredentials("googleDriveCredentials.json"); //json file data is loaded into credentials
	const auto object = credentials.object();
	const auto settingsObject = object["installed"].toObject();
	const auto clientID = settingsObject["client_id"].toString();
	const auto clientSecret(settingsObject["client_secret"].toString());

	QJsonValue JClientID(clientID);
	QJsonValue JClientSecret(clientSecret);
	QJsonValue JRefreshToken(refreshToken);
	QJsonValue JGrantType("refresh_token");

	QJsonObject body;
	body.insert("client_id", JClientID);
	body.insert("client_secret", JClientSecret);
	body.insert("refresh_token", JRefreshToken);
	body.insert("grant_type", JGrantType);

	QByteArray bodyJSON(QJsonDocument(body).toJson());

	QUrl refreshURL("https://www.googleapis.com/oauth2/v4/token");
	QNetworkRequest request(refreshURL);
	request.setRawHeader("Content-Type", "application/json; charset=UTF-8");
	
	networkReply = networkManager->post(request, bodyJSON);
	QObject::connect(networkReply, SIGNAL(finished()), this, SLOT(slotAccessTokenRefreshed())); //save token when access is granted
}

void
googleDriveInterface::slotSetAuthToken() {
	qDebug() << "Received access and refresh Token";
	authToken = google->token();
	refreshToken = google->refreshToken();
	delete google;
	emit newDriveApiRefreshToken(refreshToken); //emit refresh token so it can be saved in DB
}

void
googleDriveInterface::uploadFile(const QString &filePath) {
	qDebug() << "trying to upload " << filePath << " to Google Drive";
	currFileToUpload = filePath; //save filePath incase we need to retry current upload
	
	//get MIME type of file
	QMimeDatabase mimeDB; //contains a database of all MIME types
	QMimeType mime = mimeDB.mimeTypeForFile(filePath);
	QByteArray mimeType = mime.name().toUtf8();
	
	multiPart = new QHttpMultiPart(QHttpMultiPart::RelatedType); //contains our multipart upload
	
	//part 1 - metadata
	QHttpPart metaData; 
	metaData.setRawHeader("Content-Type", "application/json; charset=UTF-8");
	QJsonObject metaBody; //body containing metadata
	QString fileName = fileCopyHandler::extractName(filePath).remove(0,1); //extract name of file from filePath - remove first character as it is a '/'
	QJsonValue JName(fileName);
	QJsonValue JMime(mime.name());
	metaBody.insert("name", JName);
	metaBody.insert("mimeType", JMime);
	metaBody.insert("description", "Uploaded by AutoBackup.");
	QByteArray metaBodyJson(QJsonDocument(metaBody).toJson());
	metaData.setBody(metaBodyJson);

	//part 2 - media data
	QHttpPart mediaData; 
	mediaData.setRawHeader("Content-Type", "application/octet-stream");
	QFile *file = new QFile(filePath);
	file->open(QIODevice::ReadOnly);
	mediaData.setBodyDevice(file);
	file->setParent(multiPart); //delete file when multiPart is deleted
	//add parts to multipart
	multiPart->append(metaData);
	multiPart->append(mediaData);
	
	//setup rest of the request
	QUrl uploadURL("https://www.googleapis.com/upload/drive/v3/files?uploadType=multipart");
	QNetworkRequest request(uploadURL);
	request.setRawHeader("Authorization", "Bearer " + authToken.toUtf8()); //convert authToken to QByteArray when we set header;
	request.setRawHeader("Content-Type", "multipart/related; boundary=" + multiPart->boundary());

	QNetworkAccessManager *uploadManager = new QNetworkAccessManager();
	uploadManager->post(request, multiPart); //send request
	
	QObject::connect(uploadManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(slotUploadResult(QNetworkReply *)));
}

void 
googleDriveInterface::slotUploadResult(QNetworkReply *uploadReply) {
	int statusCode = uploadReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(); //we need to convert to int so we can use it with switch/case
	delete uploadReply;
	delete multiPart;
	QObject *uploadManager = sender();
	delete uploadManager;

	switch (statusCode) {
	case 200: //nothing to do, file succesfully uploaded
		qDebug() << "file succuessfully uploaded to Google Drive";
		emit readyForNextUpload(); //let program now we are ready for next file 
		break;
	case 401: //access token needs to be refreshed
		qDebug() << "Error 401: Refreshing Access Token"; 
		refreshAuthentication();
		break;
	case 500: //internal server error
	case 502: //bad gateway
	case 503: //service unavailable
	case 504: //gateway timeout
		qDebug() << "5xx error: server side, retry upload";
		uploadFile(currFileToUpload);
		break;
	case 403: //rate limit error		-- all cases retry upload
		qDebug() << "403 error: rate limit hit, retry upload";
		uploadFile(currFileToUpload);
		break;
	}
}

void
googleDriveInterface::slotAccessTokenRefreshed() {
	QVariant statusCode = networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	
	//refreshing access token failed, restart authentication process to get new refresh/access token
	if (statusCode != "200") {
		qDebug() << "unable to refresh access token";
		delete networkReply;
		getAuthentication();
	}
	else {
		QByteArray result = networkReply->readAll();
		delete networkReply;
		//extract access token from networkReply response
		QString resultString(result);
		QString token = resultString.section('"', 3, 3); //this is portion of result containing access token
		authToken = token; //update saved token
		qDebug() << "Access token successfully refreshed";
	}
}

void 
googleDriveInterface::slotSetRefreshToken(const QString &token) {
	qDebug() << "refresh token set from database";
	refreshToken = token;
	refreshAuthentication(); //get access token with refresh token for API
}

void 
googleDriveInterface::slotUploadFileToDrive(const QString &filePath){
	QFileInfo file(filePath);
	if (file.isDir() || file.size() > 52428800) {
		qDebug() << "unable to upload: " << filePath << "either >50mb or a directory";
		emit readyForNextUpload(); //get next file to upload
	}
	else {
		uploadFile(filePath);
	}
}

void
googleDriveInterface::testSlot(QNetworkReply::NetworkError error) {

}