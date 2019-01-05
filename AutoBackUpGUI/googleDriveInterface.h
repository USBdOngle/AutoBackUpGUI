#pragma once
#include <QtNetworkAuth>
#include <QObject>
#include <QDesktopServices>
#include <QJsonDocument>
#include <QDebug>
#include <fileCopyHandler.h>

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
	
	QOAuth2AuthorizationCodeFlow *google;
	QString authToken;
	QString refreshToken;
	QNetworkAccessManager *networkManager;
	QNetworkReply *networkReply;
	QHttpMultiPart *multiPart;


private slots:
	void slotSetAuthToken(); //slot to save the token when the granted signal is emitted after authorizing user
	void testSlot(); //just for testing
	void testSlot1();//
};
