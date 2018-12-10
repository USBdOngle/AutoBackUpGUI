#pragma once
#include <QDebug>
#include <QObject>

class testClass : public QObject
{
	Q_OBJECT

public:
	testClass(QObject *parent);
	~testClass();

public slots:
	void testSlot(const QString &path);
};
