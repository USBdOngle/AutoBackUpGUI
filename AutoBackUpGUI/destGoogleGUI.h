#pragma once

#include <QWidget>
#include <QLabel>
#include "ui_destGoogleGUI.h"

class destGoogleGUI : public QWidget
{
	Q_OBJECT

public:
	destGoogleGUI(QWidget *parent, const int x, const int y, const int w, const int h, QFont &fontSubTitle);
	~destGoogleGUI();

private:
	Ui::destGoogleGUI ui;

	QLabel *title; //holds title for google destination area
	QLabel *status; //holds current status whether we are connected or not to google drive

public slots:
	void slotSetDisconnected();
	void slotSetConnected();
};
