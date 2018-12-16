#include "fileToCopyDetector.h"

fileToCopyDetector::fileToCopyDetector(QObject *parent) : QFileSystemWatcher(parent) {

	QObject::connect(this, SIGNAL(directoryChanged(const QString)), this, SLOT(slotDirChanged(const QString)));
}

fileToCopyDetector::fileToCopyDetector(const QStringList &paths, QObject *parent) : QFileSystemWatcher(paths, parent) {

	for (QString path : paths) {
		addPathToWatch(path);
	}

	QObject::connect(this, SIGNAL(directoryChanged(const QString)), this, SLOT(slotDirChanged(const QString)));
}

fileToCopyDetector::~fileToCopyDetector() {}

bool
fileToCopyDetector::addPathToWatch(const QString &path) {

	QDir newDir(path);
	if (!newDir.exists()) {
		emit dirRemoved(path); //either directory being never existed or if it was removed at some point we need to notify dataBase
		qDebug() << "Directory does not exist: " << path;
		return false;
	}

	QStringList files = newDir.entryList(); //get a list of files in the new directory
	for (int i = 0; i < files.size(); i++) {
		dirsAndFilesMap.insert(path, files[i]);
	}

	addPath(path); //add path to inherited QFileSystemWatcher so we are notified of changes
	qDebug() << "Watching Path " << path;
	return true;
}

void
fileToCopyDetector::slotDirChanged(const QString &path) {

	QDir newDir(path);
	QStringList files = newDir.entryList();
	QMultiMap<QString, QString> temp = dirsAndFilesMap; //create copy of map containing current entries
	bool fileRemoved = true;

	//iterate over files list and emit path to file if it is not contained in the dirsAndFilesMap
	//if they are in map, remove them from a temp copy to check if a file was removed
	//if a file's path is emitted, that means it was the file just added to the directory

	for (QString &file : files) {
		if (!dirsAndFilesMap.contains(path, file)) {
			dirsAndFilesMap.insert(path, file);
			emit newFileToTransfer(newDir.absoluteFilePath(file)); //create absolute path to file and emit
			fileRemoved = false;
		}
		else {
			temp.remove(path, file); //file is already in path
		}
	}

	if (fileRemoved) {
		QStringList deletedFiles = temp.values(path); //files that were removed from the directory
		removeFiles(deletedFiles, path);
	}
}

void
fileToCopyDetector::removeFiles(QStringList &files, const QString &path) {
	QString possibleDir;
	QStringList dirs = directories(); //list of directories being watched by inherited QFileSystemWatcher

	for (QString &file : files) {
		dirsAndFilesMap.remove(path, file);
		possibleDir = path + '/' + file;
		//handles case where file being removed is a sub-directory being watched
		for (QString &dir : dirs) {
			if (dir.contains(possibleDir)) { //compare all directories being watched to each file that was removed
				dirsAndFilesMap.remove(dir);
				removePath(dir);	//remove path from being watched by QFileSystemWatcher
				emit dirRemoved(dir);
				qDebug() << "No longer watching " << dir;
			}
		}
	}
}

void
fileToCopyDetector::slotWatchNewDir(const QString &dirPath) {
	addPathToWatch(dirPath);
}

void
fileToCopyDetector::slotWatchNewDir(const QStringList &paths) {
	for (QString path : paths) {
		addPathToWatch(path);
	}
}

void
fileToCopyDetector::slotStopWatchingDir(const QString &dirPath) {
	removePath(dirPath);
}