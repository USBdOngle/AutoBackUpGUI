#pragma once

//whole purpose of this class is to override callback() so it returns the redirect URI I want for the google OAuth2 instead of defaulting to localhost 

#include <QOAuthHttpServerReplyHandler>

class QOAuthReplyHandler : public QOAuthHttpServerReplyHandler
{
	Q_OBJECT

public:
	QOAuthReplyHandler(QObject *parent);
	~QOAuthReplyHandler();

private:
	QString callback() const override;
};
