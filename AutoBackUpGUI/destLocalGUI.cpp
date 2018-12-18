#include "destLocalGUI.h"

destLocalGUI::destLocalGUI(QWidget *parent, const int x, const int y, const int w, const int h, QFont &fontTitle, QFont &fontText, QFont &fontSubTitle) : QListWidget(parent){
	ui.setupUi(this);

	move(x, y + 20);
	resize(w, 40);
	setFont(fontText);
	addItem(defaultText);
	
	titleLocal = new QLabel(parent);
	titleLocal->move(x, y-10);
	titleLocal->resize(w, 30);
	titleLocal->setText("Local Directory");
	titleLocal->setFont(fontSubTitle);

	titleMain = new QLabel(parent);
	titleMain->move(x, y - 30);
	titleMain->resize(w, 30);
	titleMain->setText("Backup Destination");
	titleMain->setFont(fontTitle);
}

destLocalGUI::~destLocalGUI(){
	delete titleLocal;
	delete titleMain;
}

void
destLocalGUI::slotUpdateDest(const QString &dest) {
	//get current widget in list and delete it since we only want one destination
	QListWidgetItem *currItem = item(0);
	delete currItem;
	
	//add and display the new destination
	if (!dest.isEmpty()) {
		addItem(dest);
	}
	else {
		addItem(defaultText);
	}
}