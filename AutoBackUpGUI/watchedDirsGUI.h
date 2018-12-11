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
	QScrollArea *scroll; //adds scrolling capability

	QString watchedDirs; //contains dirs that we can scroll through

public slots:
	void slotInitDirs(const QStringList &dirs); //receives list of dirs being watched and converts them to a single string then displays them
};
