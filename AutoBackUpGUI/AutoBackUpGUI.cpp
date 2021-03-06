#include "AutoBackUpGUI.h"

AutoBackUpGUI::AutoBackUpGUI(QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);
	this->setFixedSize(480, 300);
	this->setWindowTitle("AutoBackUp");
	
	//widgets that relate to watched directories portion of GUI
	watchedDirs = new watchedDirsListGUI(this, watchedX, watchedY, watchedW, watchedH, *fontScroll, *fontTitle);
	addButton = new buttonGUI(this, watchedX, watchedY + 200, watchedW / 2, 30, "Add", *fontButton);
	removeButton = new buttonGUI(this, watchedX + watchedH / 2, watchedY + 200, watchedW / 2, 30, "Remove", *fontButton);
	fileSysWindowWatched = new fileSystemWindowGUI();
	confirmMessageWatched = new confirmDirMessageGUI();

	//widgets that relate to destination portion of GUI
	fileSysWindowDest = new fileSystemWindowGUI();
	localBackupDest = new destLocalGUI(this, watchedX + 240, watchedY, watchedW, watchedH, *fontTitle, *fontScroll, *fontSubTitle);
	confirmMessageDest = new confirmDirMessageGUI();
	newButton = new buttonGUI(this, watchedX + 240, watchedY + 60, watchedW / 2, 30, "New", *fontButton);
	noneButton = new noneButtonGUI(this, watchedX + 240 + watchedH / 2, watchedY + 60, watchedW / 2, 30, "None", *fontButton);
	
	//establish connections
	QObject::connect(addButton, SIGNAL(clicked()), fileSysWindowWatched, SLOT(slotOpenWindow()));
	QObject::connect(fileSysWindowWatched, SIGNAL(openConfirmMessage()), confirmMessageWatched, SLOT(slotOpenConfirmMessage()));
	QObject::connect(confirmMessageWatched, SIGNAL(okSelected()), fileSysWindowWatched, SLOT(slotGetConfirmMessageResult()));
	QObject::connect(fileSysWindowWatched, SIGNAL(newDirToWatch(const QString)), watchedDirs, SLOT(slotAddNewDir(const QString)));
	QObject::connect(removeButton, SIGNAL(clicked()), watchedDirs, SLOT(slotRemoveCurrentDir()));
	QObject::connect(newButton, SIGNAL(clicked()), fileSysWindowDest, SLOT(slotOpenWindow()));
	QObject::connect(fileSysWindowDest, SIGNAL(openConfirmMessage()), confirmMessageDest, SLOT(slotOpenConfirmMessage()));
	QObject::connect(confirmMessageDest, SIGNAL(okSelected()), fileSysWindowDest, SLOT(slotGetConfirmMessageResult()));
	QObject::connect(fileSysWindowDest, SIGNAL(newDirToWatch(const QString)), localBackupDest, SLOT(slotUpdateDest(const QString)));
	QObject::connect(noneButton, SIGNAL(noneClicked(const QString)), localBackupDest, SLOT(slotUpdateDest(const QString)));
}

AutoBackUpGUI::~AutoBackUpGUI() {
	delete watchedDirs;
	delete addButton;
	delete removeButton;
	delete fontScroll;
	delete fontTitle;
	delete fontButton;
	delete localBackupDest;
	delete newButton;
	delete noneButton;
	delete fileSysWindowDest;
}

void
AutoBackUpGUI::setupExternalConnections(dataBase *db, fileToCopyDetector *detector, fileCopyHandler *copyHandler) {
	QObject::connect(db, SIGNAL(dirsLoadedFromDB(const QStringList)), watchedDirs, SLOT(slotAddNewDir(const QStringList)));
	QObject::connect(fileSysWindowWatched, SIGNAL(newDirToWatch(const QString)), db, SLOT(slotAddNewDirToDB(const QString)));
	QObject::connect(fileSysWindowWatched, SIGNAL(newDirToWatch(const QString)), detector, SLOT(slotWatchNewDir(const QString)));
	QObject::connect(watchedDirs, SIGNAL(currentDirRemoved(const QString)), db, SLOT(slotRemoveFromDB(const QString)));
	QObject::connect(watchedDirs, SIGNAL(currentDirRemoved(const QString)), detector, SLOT(slotStopWatchingDir(const QString)));
	QObject::connect(fileSysWindowDest, SIGNAL(newDirToWatch(const QString)), db, SLOT(slotAddNewDestToDB(const QString)));
	QObject::connect(fileSysWindowDest, SIGNAL(newDirToWatch(const QString)), detector, SLOT(slotDestinationSet(const QString)));
	QObject::connect(fileSysWindowDest, SIGNAL(newDirToWatch(const QString)), copyHandler, SLOT(slotNewDestDir(const QString)));
	QObject::connect(db, SIGNAL(destLoadedFromDB(const QString)), localBackupDest, SLOT(slotUpdateDest(const QString)));
	QObject::connect(noneButton, SIGNAL(noneClicked(const QString)), detector, SLOT(slotDestinationSet(const QString)));
	QObject::connect(noneButton, SIGNAL(noneClicked(const QString)), db, SLOT(slotAddNewDestToDB(const QString)));
}