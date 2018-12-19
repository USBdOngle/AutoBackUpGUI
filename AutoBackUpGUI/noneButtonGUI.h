#pragma once

#include "buttonGUI.h"
#include "ui_noneButtonGUI.h"

class noneButtonGUI : public buttonGUI
{
	Q_OBJECT

public:
	noneButtonGUI(QWidget *parent, const int x, const int y, const int w, const int h, QString text, QFont &font);
	~noneButtonGUI();

private:
	Ui::noneButtonGUI ui;

private slots:
	void getClick();

signals:
	void noneClicked(const QString);
};
