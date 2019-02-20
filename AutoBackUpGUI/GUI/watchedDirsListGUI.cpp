#include "watchedDirsListGUI.h"

watchedDirsListGUI::watchedDirsListGUI(QWidget *parent, const int x, const int y, const int w, const int h, QFont &fontList, QFont &fontTitle) : QListWidget(parent){
	ui.setupUi(this);
	//adjusting list widget
	move(x, y);
	resize(w, h);
	setFont(fontList);

	//setup title
	title = new QLabel(parent);
	title->move(x + 5, y - 30);
	title->resize(w, 30);
	title->setText("Watched Directories");
	title->setFont(fontTitle);
}

watchedDirsListGUI::~watchedDirsListGUI() {
	delete title;
}

void
watchedDirsListGUI::slotAddNewDir(const QStringList &dirs) {
	addItems(dirs);
}

void
watchedDirsListGUI::slotAddNewDir(const QString &dir) {	
	addItem(dir);
}

void
watchedDirsListGUI::slotRemoveCurrentDir() {
	QListWidgetItem* dirItem = currentItem(); //get currently selected item from displayed list of watched dirs
	//either list is empty or nothing is selected
	if (dirItem != NULL) {
		QListWidgetItem* dirItem = currentItem(); //get currently selected item from displayed list of watched dirs
		QString dirString = dirItem->text();
		emit currentDirRemoved(dirString); //emit the direcotry that was removed so rest of program can handle changes
	}
	delete dirItem; //this removes the widget from the QListWidget
}