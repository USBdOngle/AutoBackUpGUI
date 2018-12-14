#pragma once

#include <QDir>
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

	QString clickedDir;

public slots:
	void slotOpenWindow(); //accepts signal from QPushButton to open window
	void slotGetConfirmMessageResult(); //accepts signal from confirmDirMessageGUI only when user selectse 'Ok' - then will emit directory path

private slots:
	void slotGetDoubleClick(const QModelIndex &index); //connects to doubleClicked signal from view so we can emit it externally and save directory that was clicked

signals:
	void newDirToWatch(const QString &path);
	void openConfirmMessage();
};
