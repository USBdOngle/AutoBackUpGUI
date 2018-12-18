#pragma once

#include <QtWidgets>
#include "ui_destLocalGUI.h"

class destLocalGUI : public QListWidget
{
	Q_OBJECT

public:
	destLocalGUI(QWidget *parent, const int x, const int y, const int w, const int h, QFont &fontTitle, QFont &fontText, QFont &fontSubTitle);
	~destLocalGUI();

private:
	Ui::destLocalGUI ui;

	QLabel *titleMain;
	QLabel *titleLocal;

	const QString defaultText = "No local directory currently selected.";

public slots:
	void slotUpdateDest(const QString &dest);
};
