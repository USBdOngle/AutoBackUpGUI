#include "noneButtonGUI.h"

noneButtonGUI::noneButtonGUI(QWidget *parent, const int x, const int y, const int w, const int h, QString text, QFont &font) : buttonGUI(parent, x, y, w, h, text, font){
	//ui.setup(this) removed since it would override positioning & sizing done by inherited buttonGUI

	QObject::connect(this, SIGNAL(clicked()), this, SLOT(getClick()));
}

noneButtonGUI::~noneButtonGUI() {}

void
noneButtonGUI::getClick() {
	QString empty;
	emit noneClicked(empty);
}

