#include "testClass.h"

testClass::testClass(QObject *parent)
	: QObject(parent)
{
}

testClass::~testClass()
{
}

void
testClass::testSlot(const QString &path) {
	qDebug() << path;
}

