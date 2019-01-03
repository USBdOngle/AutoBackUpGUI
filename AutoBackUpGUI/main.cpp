#include "AutoBackUpGUI.h"
#include <QtWidgets/QApplication>
#include <QString>
#include "fileToCopyDetector.h"
#include "testClass.h"
#include "fileCopyHandler.h"
#include "dataBase.h"
#include "googleDriveInterface.h"

int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);
	
	/*
	QString path = "C:/Users/Chris/Desktop/testA";
	QString path2 = "C:/Users/Chris/Desktop/testA/CMPT127-Lab Instructions";
	QString path3 = "C:/Users/Chris/Desktop/testA/CMPT127-Lab Instructions/New folder";
	QString dest = "C:/Users/Chris/Desktop/testB";
	QString dest1 = "D:/dest";
	QString path4 = "D:/test";
	QStringList paths = { path };

	//testClass test(&a);

	//QObject::connect(&detectorTest, SIGNAL(newFileToTransfer(const QString)), &test, SLOT(testSlot(const QString)));

	//test.addPathToWatch(path2);




	fileToCopyDetector* detectTest = new fileToCopyDetector(&a);
	dataBase* dbTest = new dataBase(&a);
	fileCopyHandler* copyTest = new fileCopyHandler(dest, &a);

	QObject::connect(detectTest, SIGNAL(newFileToTransfer(const QString)), copyTest, SLOT(slotFileToCopy(const QString)));
	QObject::connect(copyTest, SIGNAL(newDirToWatch(const QString)), detectTest, SLOT(slotWatchNewDir(const QString)));
	QObject::connect(copyTest, SIGNAL(newDirToWatch(const QString)), dbTest, SLOT(slotAddNewDirToDB(const QString)));
	QObject::connect(dbTest, SIGNAL(dirsLoadedFromDB(const QStringList)), detectTest, SLOT(slotWatchNewDir(const QStringList)));
	QObject::connect(detectTest, SIGNAL(dirRemoved(const QString)), dbTest, SLOT(slotRemoveFromDB(const QString)));
	QObject::connect(copyTest, SIGNAL(testDestination(const QString)), dbTest, SLOT(slotAddNewDestToDB(const QString)));
	QObject::connect(dbTest, SIGNAL(destLoadedFromDB(const QString)), copyTest, SLOT(slotNewDestDir(const QString)));
	QObject::connect(dbTest, SIGNAL(destLoadedFromDB(const QString)), detectTest, SLOT(slotDestinationSet(const QString)));
	//copyTest->testemit();
	

	AutoBackUpGUI w;
	w.setupExternalConnections(dbTest, detectTest, copyTest);
	w.show();

	dbTest->emitData();
	*/

	googleDriveInterface test(&a);
	test.getAuthentication();

	return a.exec();
}