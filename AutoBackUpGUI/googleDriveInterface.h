#pragma once
#include <QtNetworkAuth>
#include <QObject>
#include <QDesktopServices>
#include <QJsonDocument>
#include <QDebug>
#include <fileCopyHandler.h>
#include "googleFileUploadQueue.h"

class googleDriveInterface : public QObject
{
	Q_OBJECT

public:
	googleDriveInterface(QObject *parent);
	~googleDriveInterface();
	void getAuthentication(); //here for testing

private:
	//void getAuthentication(); //get OAuth2 authentication token from google
	QJsonDocument getCredentials(const QString fileName); //returns QJsonDocument read in from fileName
	void uploadFile(const QString &filePath);
	void refreshAuthentication(); //refreshes access token and updates it locally
	
	QNetworkAccessManager *networkManager;
	QNetworkReply *networkReply;
	QOAuth2AuthorizationCodeFlow *google;
	QString authToken;
	QString refreshToken;
	QHttpMultiPart *multiPart;

	QString currFileToUpload; //used to hold the file currently being uploaded incase we need to retry the upload process
	googleFileUploadQueue* fileQueue;

public slots:
	void slotSetRefreshToken(const QString &token); //receives signal from DB containing saved refresh token if it exists
	void slotUploadFileToDrive(const QString &filePath); //receives signal containing the absolute path to a file that is to be uploaded

private slots:
	void slotSetAuthToken(); //slot to save the token when the granted signal is emitted after authorizing use
	void slotUploadResult(); //handles the http request result when uploading a file
	void slotAccessTokenRefreshed(); //receives signal when we make an access token refresh request
	void slotUploadFile(const QString &filePath); //internal slot for uploading files

	void testSlot(QNetworkReply::NetworkError);

signals:
	void newDriveApiRefreshToken(const QString &token); //signal emitted when a new refresh token is received
	void readyForNextUpload(); //internal signal emitted when ready to handle next upload
	void addFileToQueue(const QString &filePath); //internal signal to add file to queue to be uploaded
};
