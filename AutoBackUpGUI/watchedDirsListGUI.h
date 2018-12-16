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
	void slotAddNewDir(const QStringList &dirs); //receives list of dirs being watched and converts them to a single string then displays them
	void slotAddNewDir(const QString &dir); //overload of preceeding function that acceptts just one string
	void slotRemoveCurrentDir(); //receives signal that delete button has been clicked and removes currently selected in list. Emits currendDirRemoved signal

signals:
	void currentDirRemoved(const QString &dir); //emits directory that has been removed 
};
