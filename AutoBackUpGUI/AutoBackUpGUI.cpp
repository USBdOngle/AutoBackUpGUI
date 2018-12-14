#include "AutoBackUpGUI.h"

AutoBackUpGUI::AutoBackUpGUI(QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);
	this->setFixedSize(480, 300);
	this->setWindowTitle("AutoBackUp");
	
	watchedDirs = new watchedDirsListGUI(this, watchedX, watchedY, watchedW, watchedH, *fontScroll, *fontTitle);
	addButton = new buttonGUI(this, watchedX, watchedY + 200, watchedW / 2, 30, "Add", *fontButton);
	removeButton = new buttonGUI(this, watchedX + watchedH / 2, watchedY + 200, watchedW / 2, 30, "Remove", *fontButton);
	fileSystemWindow = new fileSystemWindowGUI();
	confirmDirMessage = new confirmDirMessageGUI();
	
	QObject::connect(addButton, SIGNAL(clicked()), fileSystemWindow, SLOT(slotOpenWindow()));
	QObject::connect(fileSystemWindow, SIGNAL(openConfirmMessage()), confirmDirMessage, SLOT(slotOpenConfirmMessage()));
	QObject::connect(confirmDirMessage, SIGNAL(okSelected()), fileSystemWindow, SLOT(slotGetConfirmMessageResult()));
	QObject::connect(fileSystemWindow, SIGNAL(newDirToWatch(const QString)), watchedDirs, SLOT(slotAddNewDir(const QString)));
}

AutoBackUpGUI::~AutoBackUpGUI() {
	delete watchedDirs;
	delete addButton;
	delete removeButton;
}

void
AutoBackUpGUI::setupExternalConnections(dataBase *db, fileToCopyDetector *detector) {
	QObject::connect(db, SIGNAL(dirsLoadedFromDB(const QStringList)), watchedDirs, SLOT(slotInitDirs(const QStringList)));
	QObject::connect(fileSystemWindow, SIGNAL(newDirToWatch(const QString)), db, SLOT(slotAddNewDirToDB(const QString)));
	QObject::connect(fileSystemWindow, SIGNAL(newDirToWatch(const QString)), detector, SLOT(slotWatchNewDir(const QString)));
}