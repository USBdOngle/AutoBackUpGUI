#pragma once
#include <QFile>
#include <QObject>
#include <QString>
#include <qDebug>
#include <qDir>

class fileCopyHandler : public QFile
{
	Q_OBJECT

public:
	fileCopyHandler(QObject *parent);
	fileCopyHandler(const QString &path, QObject *parent);
	~fileCopyHandler();
	void testemit(); //TESTING - delete later

private:
	QString destPath; //path to destination for file copy

	bool copyFile(const QString &filePath, QString destination); //copies file to specified directory
	QString extractName(const QString &filePath); //extracts name of file from its source path in format "/filename"
	QString updateDest(const QString &filePath); //if new file was inserted into sub directory of path being watched, it should be inserted into corresponding sub directory in the destination
												 //returns portion of path which needs to be appended to the destination path

public slots:
	void slotFileToCopy(const QString &filePath); //slot to receive path of file to copy
	void slotNewDestDir(const QString &path); //slot to receive path to the destination directory

signals:
	void newDirToWatch(const QString &dirPath); //emits when we create a new directory in the destination, this means a folder was placed in a watched directory and we want to watch it for changes
	void testDestination(const QString &path); //testing for storage and retrieval of destination from database - delete later
};