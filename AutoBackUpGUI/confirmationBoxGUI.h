#pragma once

#include <QWidget>
#include "ui_confirmationBoxGUI.h"

class confirmationBoxGUI : public QWidget
{
	Q_OBJECT

public:
	confirmationBoxGUI(QWidget *parent = Q_NULLPTR);
	~confirmationBoxGUI();

private:
	Ui::confirmationBoxGUI ui;
};
