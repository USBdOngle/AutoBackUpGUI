#include "AutoBackUpGUI.h"

AutoBackUpGUI::AutoBackUpGUI(QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);
	this->setFixedSize(480, 300);
	this->setWindowTitle("AutoBackUp");

	setupWatchedDirs();
	setupWatchedDirsButtons();
}

void
AutoBackUpGUI::setupWatchedDirs() {
	watchedTitleLabel = new QLabel(this);
	watchedTitleLabel->move(watchedX+5, watchedY-30);
	watchedTitleLabel->resize(watchedW, 30);
	watchedTitleLabel->setText("Watched Directories");
	watchedTitleLabel->setFont(*fontTitle);

	
	watchedLabel = new QLabel(this);
	watchedScroll = new QScrollArea(this);

	watchedLabel->move(watchedX, watchedY);
	watchedScroll->move(watchedX, watchedY);
	
	watchedLabel->resize(watchedW, watchedH);
	watchedScroll->resize(watchedW, watchedH);
	
	watchedLabel->setText("test \n test \n test");
	watchedLabel->setFont(*fontScroll);
	
	
	watchedScroll->setWidget(watchedLabel);
}

void
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
	
}