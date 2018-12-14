#pragma once

#include <QMessageBox>
#include "ui_confirmDirMessageGUI.h"

class confirmDirMessageGUI : public QMessageBox
{
	Q_OBJECT

public:
	confirmDirMessageGUI(QWidget *parent = Q_NULLPTR);
	~confirmDirMessageGUI();

private:
	Ui::confirmDirMessageGUI ui;

public slots:
	void slotOpenConfirmMessage();

signals:
	void okSelected();
};
