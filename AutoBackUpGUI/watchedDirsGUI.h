#pragma once

#include <QtWidgets>
#include "ui_watchedDirsGUI.h"

class watchedDirsGUI : public QLabel
{
	Q_OBJECT

public:
	watchedDirsGUI(QWidget *parent, const int x, const int y, const int w, const int h, QFont &fontScroll, QFont &fontTitle);
	~watchedDirsGUI();

private:
	Ui::watchedDirsGUI ui;

	QLabel *title;
	QScrollArea *scroll;
};
