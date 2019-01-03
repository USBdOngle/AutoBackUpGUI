#include "QOAuthReplyHandler.h"

QOAuthReplyHandler::QOAuthReplyHandler(QObject *parent) : QOAuthHttpServerReplyHandler(parent) {}


QOAuthReplyHandler::~QOAuthReplyHandler() {}

QString
QOAuthReplyHandler::callback() const {
	return "urn:ietf:wg:oauth:2.0:oob";
}
