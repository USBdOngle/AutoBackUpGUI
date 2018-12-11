#pragma once
#include <QtWidgets>
#include <QtWidgets/QMainWindow>
#include "ui_AutoBackUpGUI.h"
#include "watchedDirsGUI.h"
#include "buttonGUI.h"

class AutoBackUpGUI : public QMainWindow
{
	Q_OBJECT

public:
	AutoBackUpGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::AutoBackUpGUIClass ui;

	watchedDirsGUI *watchedDirs;

	buttonGUI *addButton; //button widget to add new directories to watch
	buttonGUI *removeButton; //button widget to remove directories from being watched

	QFont *fontScroll = new QFont("Arial", 12); //font for items in scroll area
	QFont *fontButton = new QFont("Arial", 13, QFont::Bold); //font for buttons
	QFont *fontTitle = new QFont("Arial", 14, QFont::Bold); //font for titles

	const int watchedX = 20; //x-pos for watchedLabel
	const int watchedY = 50; //y-pos for watchedLabel
	const int watchedH = 200; //Height of watchedLabel
	const int watchedW = 200; //width of watchedLabel

};
