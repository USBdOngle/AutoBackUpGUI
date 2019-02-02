#include "destGoogleGUI.h"

destGoogleGUI::destGoogleGUI(QWidget *parent, const int x, const int y, const int w, const int h, QFont &fontSubTitle) : QWidget(parent){
	ui.setupUi(this);
	
	title = new QLabel(parent);
	title->setFont(fontSubTitle);
	title->setText("Google Drive");
	title->resize(w, 30);
	title->move(x, y + 100);

	status = new QLabel(parent);
	status->setFont(fontSubTitle);
	status->setText("Disconnected...");
	status->resize(w, 30);
	status->move(x, y + 160);
	status->setStyleSheet("QLabel {color : red}");
}

destGoogleGUI::~destGoogleGUI(){
	delete title;
	delete status;
}

void
destGoogleGUI::slotSetDisconnected() {
	status->setText("Disconnected...");
	status->setStyleSheet("QLabel {color : red}");
}

void
destGoogleGUI::slotSetConnected() {
	status->setText("Connected!");
	status->setStyleSheet("QLabel {color : green}");
}