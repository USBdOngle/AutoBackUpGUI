#include "fileSystemWindowGUI.h"

fileSystemWindowGUI::fileSystemWindowGUI(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(w, h);
	
	dirModel = new QFileSystemModel(this);
	dirModel->setRootPath(QDir::homePath());
	
	view = new QTreeView(this);
	view->resize(w, h);
	view->setModel(dirModel);
	view->header()->hideSection(3); //hides date modified column
	view->header()->hideSection(1); //hides size column
	view->setColumnWidth(0, 240);
}

fileSystemWindowGUI::~fileSystemWindowGUI() {
	delete dirModel;
	delete view;
}

void
fileSystemWindowGUI::openWindowSlot() {
	show();
}

void 
fileSystemWindowGUI::getFileAtIndexSlot(const QModelIndex &index) {

}