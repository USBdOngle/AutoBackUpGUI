#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AutoBackUpGUI.h"

class AutoBackUpGUI : public QMainWindow
{
	Q_OBJECT

public:
	AutoBackUpGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::AutoBackUpGUIClass ui;
};
