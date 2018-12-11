#pragma once

#include <QWidget>
#include "ui_FileExplorerGUI.h"

class FileExplorerGUI : public QWidget
{
	Q_OBJECT

public:
	FileExplorerGUI(QWidget *parent = Q_NULLPTR);
	~FileExplorerGUI();

private:
	Ui::FileExplorerGUI ui;
};
