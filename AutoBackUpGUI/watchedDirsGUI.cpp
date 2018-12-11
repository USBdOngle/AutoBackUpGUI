#include "watchedDirsGUI.h"

watchedDirsGUI::watchedDirsGUI(QWidget *parent, const int x, const int y, const int w, const int h, QFont &fontScroll, QFont &fontTitle) : QLabel(parent){
	ui.setupUi(this);
	
	move(x, y);
	setMinimumSize(w, h);
	setFont(fontScroll);
	setAlignment(Qt::AlignTop | Qt::AlignLeft);
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

	scroll = new QScrollArea(parent);
	scroll->move(x, y);
	scroll->resize(w, h);
	scroll->setWidget(this);

	title = new QLabel(parent);
	title->move(x + 5, y - 30);
	title->resize(w, 30);
	title->setText("Watched Directories");
	title->setFont(fontTitle);
}

watchedDirsGUI::~watchedDirsGUI() {}

void
watchedDirsGUI::slotInitDirs(const QStringList &dirs) {
	for (QString s : dirs) {
		watchedDirs.append(s + '\n');
	}
	setText(watchedDirs);
}
