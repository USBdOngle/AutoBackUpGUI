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
watchedDirsListGUI::slotInitDirs(const QStringList &dirs) {
	addItems(dirs);
}

void
watchedDirsListGUI::slotAddNewDir(const QString &dir) {	
	addItem(dir);
}