#include "AutoBackUpGUI.h"

AutoBackUpGUI::AutoBackUpGUI(QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);
	this->setFixedSize(480, 300);
	this->setWindowTitle("AutoBackUp");
	
	watchedDirs = new watchedDirsGUI(this, watchedX, watchedY, watchedW, watchedH, *fontScroll, *fontTitle);
	addButton = new buttonGUI(this, watchedX, watchedY + 200, watchedW / 2, 30, "Add", *fontButton);
	removeButton = new buttonGUI(this, watchedX + watchedH / 2, watchedY + 200, watchedW / 2, 30, "Remove", *fontButton);

}
/*void
AutoBackUpGUI::setupWatchedDirsButtons() {
	int h = 30;
	
	addButton = new QPushButton(this);
	removeButton = new QPushButton(this);

	addButton->move(watchedX, watchedY + 200);
	removeButton->move(watchedX + watchedH/2, watchedY + 200);

	addButton->resize(watchedW/2, h);
	removeButton->resize(watchedW/2, h);

	addButton->setText("Add");
	addButton->setFont(*fontButton);
	removeButton->setText("Remove");
	removeButton->setFont(*fontButton);
}*/