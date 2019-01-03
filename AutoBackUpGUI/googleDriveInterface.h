#pragma once
#include <QtNetworkAuth>
#include <QObject>
#include <QDesktopServices>
#include <QJsonDocument>
#include <QDebug>
#include "QOAuthReplyHandler.h"

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
	/*const QString jsonData = '{
								"client_id":"1069420317549-m8lqlu4nkm3j45vhbr7329iu7scokjpp.apps.googleusercontent.com",
								"project_id" : "autobackup-227219",
								"auth_uri" : "https://accounts.google.com/o/oauth2/auth",
								"token_uri" : "https://www.googleapis.com/oauth2/v3/token",
								"auth_provider_x509_cert_url" : "https://www.googleapis.com/oauth2/v1/certs",
								"client_secret" : "gv8ViAv04bWS5BipUh4uyF1j",
								"redirect_uris" : ["urn:ietf:wg:oauth:2.0:oob", "http://localhost"]
							  }';*/
};
