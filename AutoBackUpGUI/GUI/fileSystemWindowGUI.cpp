#include "fileSystemWindowGUI.h"

fileSystemWindowGUI::fileSystemWindowGUI(QWidget *parent) : QDialog(parent){
	ui.setupUi(this);
	
	setFixedSize(w, h);
	setWindowTitle("File Explorer");
	
	dirModel = new QFileSystemModel(this);
	dirModel->setRootPath(QDir::homePath());
	
	view = new QTreeView(this);
	view->resize(w, h);
	view->setModel(dirModel);
	view->header()->hideSection(3); //hides date modified column
	view->header()->hideSection(1); //hides size column
	view->setColumnWidth(0, 240);

	QObject::connect(view, SIGNAL(doubleClicked(const QModelIndex)), this, SLOT(slotGetDoubleClick(const QModelIndex))); 
}

fileSystemWindowGUI::~fileSystemWindowGUI(){
	delete dirModel;
	delete view;
}

void
fileSystemWindowGUI::slotOpenWindow() {
	show();
}

void
fileSystemWindowGUI::slotGetDoubleClick(const QModelIndex &index) {
	//check to see if path at index is a directory otherwise we don't want user to select a file
	QString possibleDir = dirModel->filePath(index);
	QDir dirCheck(possibleDir);
	if (dirCheck.exists()){
		clickedDir = possibleDir;
		emit openConfirmMessage();
	}
}

void
fileSystemWindowGUI::slotGetConfirmMessageResult() {
	emit newDirToWatch(clickedDir);
}