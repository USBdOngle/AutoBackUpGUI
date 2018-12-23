#pragma once
#include <QFileSystemWatcher>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QHash>
#include <QStringList>

class fileToCopyDetector : public QFileSystemWatcher
{
	Q_OBJECT

public:
	fileToCopyDetector(QObject *parent); //base constructor initialized without any directories
	fileToCopyDetector(const QStringList &paths, QObject *parent); //constructor that accepts a list of directories to watch - used for testing
	~fileToCopyDetector();

	bool addPathToWatch(const QString &path); //add a path to directory to watch, used for testing

private:
	QHash<QString, QHash<QString, int>> dirsAndFilesHash; //hash table that contains directory path as key, and another hash table as the element that contains it the directories contents as keys and an int as a placeholder
	bool isDestinationSet = false; //keeps track whether there is currently a set destination, if not nothing will happen

	//void removeFiles(QStringList &files, const QString &path); //handles the case when a file is removed from a directory being watched

public slots:
	void slotWatchNewDir(const QString &dirPath); //receives signal that a new directory needs to be watched
	void slotWatchNewDir(const QStringList &paths); //receives signal of multiple directories to be watched, overloads preceding function
	void slotStopWatchingDir(const QString &dirPath); //receives signal that we no longer need to watch a certain directory
	void slotDestinationSet(const QString &destPath); //receives signal of a new destination and determines if it is valid so fileToCopyDetector can begin working

private slots:
	//void slotDirChanged(const QString &path); //internal slot that recieves signal that a watched directory was modified

signals:
	void newFileToTransfer(const QString &filePath); //emits path to newly inserted file in directory
	void dirRemoved(const QString &path); //emits path of directory that was removed
};
