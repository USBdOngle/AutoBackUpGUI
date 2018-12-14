#pragma once

#include <QtWidgets>
#include "ui_watchedDirsListGUI.h"

class watchedDirsListGUI : public QListWidget
{
	Q_OBJECT

public:
	watchedDirsListGUI(QWidget *parent, const int x, const int y, const int w, const int h, QFont &fontTitle, QFont &fontList);
	~watchedDirsListGUI();

private:
	Ui::watchedDirsListGUI ui;
	
	QLabel *title;

public slots:
	void slotInitDirs(const QStringList &dirs); //receives list of dirs being watched and converts them to a single string then displays them
	void slotAddNewDir(const QString &dir); //receives a signal dir to add to list being displayed
};
