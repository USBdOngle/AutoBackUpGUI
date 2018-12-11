#pragma once

#include <QtWidgets>
#include "ui_buttonGUI.h"

class buttonGUI : public QPushButton
{
	Q_OBJECT

public:
	buttonGUI(QWidget *parent, const int x, const int y, const int w, const int h, QString text, QFont &font);
	~buttonGUI();

private:
	Ui::buttonGUI ui;
};
