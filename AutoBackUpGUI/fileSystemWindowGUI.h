#pragma once

#include <QtWidgets>
#include <QDialog>
#include "ui_fileSystemWindowGUI.h"

class fileSystemWindowGUI : public QDialog
{
	Q_OBJECT

public:
	fileSystemWindowGUI(QWidget *parent = Q_NULLPTR);
	~fileSystemWindowGUI();

private:
	Ui::fileSystemWindowGUI ui;
	const int w = 440;
	const int h = 260;
	
	QFileSystemModel *dirModel;
	QTreeView *view;

public slots:
	void openWindowSlot(); //accepts signal from QPushButton to open window

private slots:
	void getFileAtIndexSlot(const QModelIndex &index); //gets the path to directory at index and emits it

signals:
	void pathToWatch(const QString &path);
};
