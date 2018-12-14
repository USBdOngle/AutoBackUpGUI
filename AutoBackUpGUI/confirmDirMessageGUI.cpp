#include "confirmDirMessageGUI.h"

confirmDirMessageGUI::confirmDirMessageGUI(QWidget *parent) : QMessageBox(parent){
	ui.setupUi(this);

	setWindowTitle("Confirm Choice");
	setText("Are you sure you want to add this directory?");
	setInformativeText("AutoBackUp will modify this directory while running.");
	setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	setDefaultButton(QMessageBox::Ok);
}

confirmDirMessageGUI::~confirmDirMessageGUI() {}

void
confirmDirMessageGUI::slotOpenConfirmMessage() {
	if (exec() == QMessageBox::Ok) {
		emit okSelected();
	}
}
