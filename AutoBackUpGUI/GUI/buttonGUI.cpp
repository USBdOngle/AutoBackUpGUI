#include "buttonGUI.h"

buttonGUI::buttonGUI(QWidget *parent, const int x, const int y, const int w, const int h, QString text, QFont &font) : QPushButton(parent){
	ui.setupUi(this);
	move(x, y);
	resize(w, h);
	setText(text);
	setFont(font);
}

buttonGUI::~buttonGUI()
{
}
