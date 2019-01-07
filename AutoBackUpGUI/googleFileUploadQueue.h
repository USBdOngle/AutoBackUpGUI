#pragma once

#include <QObject>
#include <QQueue>

class googleFileUploadQueue : public QObject
{
	Q_OBJECT

public:
	googleFileUploadQueue(QObject *parent);
	~googleFileUploadQueue();

private:
	QQueue<QString> fileQueue;

public slots:
	void slotAddFileToQueue(const QString &filePath);
	void slotShouldSendNextFile();

signals:
	void nextFileToUpload(const QString);
};
