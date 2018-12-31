#include "fileCopyHandler.h"
#include <QIODevice> // testing with errorString()

fileCopyHandler::fileCopyHandler(QObject *parent) : QFile(parent) {}

fileCopyHandler::fileCopyHandler(const QString &path, QObject *parent) : QFile(parent) {
	destPath = path;
}

fileCopyHandler::~fileCopyHandler() {}

void
fileCopyHandler::slotFileToCopy(const QString &filePath) {
	bool result = copyFile(filePath, updateDest(filePath));
	qDebug() << "copying " << filePath << "returned " << result;
}

void
fileCopyHandler::slotNewDestDir(const QString &path) {
	destPath = path;
}

bool
fileCopyHandler::copyFile(const QString &filePath, QString destination) {
	QDir *dirCheck = new QDir(filePath); //we want to check whether the path points to a file or a directory
	QString newItem = destination + extractName(filePath); //new absolute path to item in destination directory

	if (dirCheck->exists()) {
		qDebug() << "path is folder";
		dirCheck->mkpath(newItem); //create new directory with same name as current one in destination
		QStringList names = dirCheck->entryList(); //names of every item in current directory
		bool result = true;

		for (int i = 2; i < names.size(); i++) { //files[0] = "." and files[1] = ".." for some reason
			result &= copyFile(dirCheck->absoluteFilePath(names[i]), newItem); //copy each file from current directory into mirrored sub directory in destination
		}

		emit newDirToWatch(filePath); //emit new directory so FileToCopyDetector can watch for changes in it
		delete dirCheck;
		return result;
	}
	else {
		if (QFile::remove(newItem)) { //if newItem already exists in destination, remove it so it can be updated by the newest version of it
			qDebug() << newItem << " is being replaced by newest version.";
		}
		if (copy(filePath, newItem)) {
			qDebug() << "file copy succesfull";
			return true;
		}
		else
			qDebug() << "unable to copy " << filePath << " to " << newItem << " error: " << errorString();
		return false;
	}
}

QString
fileCopyHandler::extractName(const QString &filePath) {
	int pos = filePath.lastIndexOf('/'); //filename is contained after this

	std::string path = filePath.toStdString();
	std::string temp(&path[pos], &path[pos] + filePath.size() - pos); //create new string that contains end portion of file path "/filename"
	
	QString name = QString::fromStdString(temp);		 
	return name;
}

QString
fileCopyHandler::updateDest(const QString &filePath) {
	QString newDest;
	int end = filePath.count('/') - 1; //only filename is contained after this
	int start = end; //keeps track of portion of filePath that could be a possible directory

	for (int i = start; i >= 1; i--) {
		newDest = filePath.section('/', start, end); //portion of filePath to check if it has a corresponding sub directory in destination
		QString fullDest = destPath + '/' + newDest;
		QDir testDest(fullDest);

		if (testDest.exists()) { //check if path containing destination and possible sub directory exists
			return fullDest;
		}
		start--;
	}
	return destPath; //file is not from sub directory in a directory being watched so just return original destination
}

void
fileCopyHandler::testemit() {
	emit testDestination(destPath);
}