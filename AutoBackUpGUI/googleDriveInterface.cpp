#include "googleDriveInterface.h"

googleDriveInterface::googleDriveInterface(QObject *parent) : QObject(parent){
	networkManager = new QNetworkAccessManager(this);
}

googleDriveInterface::~googleDriveInterface() {
	delete google;
	delete networkManager;
	delete networkManager;
}

void
googleDriveInterface::getAuthentication() {
	google = new QOAuth2AuthorizationCodeFlow;
	google->setScope("https://www.googleapis.com/auth/drive");
	QObject::connect(google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl); //this connection opens authorization URL in user's default browser

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
	
	QObject::connect(google, SIGNAL(granted()), this, SLOT(slotSetAuthToken())); //save token when access is granted
	QObject::connect(google, SIGNAL(granted()), this, SLOT(testSlot()));
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
googleDriveInterface::slotSetAuthToken() {
	authToken = google->token();
	refreshToken = google->refreshToken();
}

void
googleDriveInterface::uploadFile(const QString &filePath) {

	/*QUrl uploadURL("https://www.googleapis.com/upload/drive/v3/files?uploadType=resumable");
	QNetworkRequest request(uploadURL);

	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly)) {
		qDebug() << "unable to open: " << filePath << " for upload:" << file.errorString();
		return;
	}

	//get size of file and save as qbytearray for request header
	QByteArray fileSize;
	fileSize.setNum(file.size());

	//get MIME type of file
	QMimeDatabase mimeDB; //contains a database of all MIME types
	QMimeType mime = mimeDB.mimeTypeForFile(filePath);
	QByteArray mimeType = mime.name().toUtf8();

	QByteArray test = authToken.toUtf8();
	//set headers
	request.setRawHeader("Authorization", "Bearer " + authToken.toUtf8()); //convert authToken to QByteArray when we set header;
	request.setRawHeader("Content-Type", "application/json; charset=UTF-8");
	request.setRawHeader("Content-Length", fileSize);
	request.setRawHeader("X-Upload-Content-Type", mimeType);

	//make json body for request
	QJsonObject jsonBody;
	QJsonValue JFile(fileCopyHandler::extractName(filePath)); //extract name of file from filePath
	QJsonValue JMime(mime.name()); //mime type of file
	QJsonValue JData(QString::fromUtf8(file.readAll()));
	file.close();
	jsonBody.insert("name", JFile);
	jsonBody.insert("mimeType", JMime);
	jsonBody.insert("description", "File uploaded by AutoBackUp.");
	jsonBody.insert("media", JData);

	networkReply = networkManager->post(request, QJsonDocument(jsonBody).toJson());
	
	*/
	
	//get MIME type of file
	QMimeDatabase mimeDB; //contains a database of all MIME types
	QMimeType mime = mimeDB.mimeTypeForFile(filePath);
	QByteArray mimeType = mime.name().toUtf8();
	
	multiPart = new QHttpMultiPart(); //contains our multipart upload
	
	//part 1 - metadata
	QHttpPart metaData; 
	metaData.setRawHeader("Content-Type", "application/json; charset=UTF-8");
	QJsonObject metaBody; //body containing metadata
	QJsonValue JName(fileCopyHandler::extractName(filePath));
	QJsonValue JMime(mime.name());
	metaBody.insert("name", JName);
	metaBody.insert("mimeType", JMime);
	metaBody.insert("Description", "Uploaded by AutoBackup.");
	QByteArray metaBodyJson(QJsonDocument(metaBody).toJson());
	metaData.setBody(metaBodyJson);

	//part 2 - media data
	QHttpPart mediaData; 
	mediaData.setRawHeader("Content-Type", mimeType);
	QFile *file = new QFile(filePath);
	file->open(QIODevice::ReadOnly);
	mediaData.setBodyDevice(file);
	file->setParent(multiPart); //delete file when multiPart is deleted

	multiPart->append(metaData);
	multiPart->append(mediaData);
	QByteArray bodySize;
	bodySize.setNum(file->size() + metaBodyJson.size()); //number of bytes in entire request body

	//setup rest of the request
	QUrl uploadURL("https://www.googleapis.com/upload/drive/v3/files?uploadType=multipart");
	QNetworkRequest request(uploadURL);
	request.setRawHeader("Authorization", "Bearer " + authToken.toUtf8()); //convert authToken to QByteArray when we set header;
	request.setRawHeader("Content-Type", "multipart/related; boundary=" + multiPart->boundary());
	request.setRawHeader("Content-Length", bodySize);

	networkReply = networkManager->post(request, multiPart);

	QObject::connect(networkReply, SIGNAL(metaDataChanged()), this, SLOT(testSlot1()));
}

void
googleDriveInterface::testSlot() {
	uploadFile("C:/Users/Chris/Desktop/saveData.txt");
}

void 
googleDriveInterface::testSlot1() {
	QVariant statusCode = networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	
}