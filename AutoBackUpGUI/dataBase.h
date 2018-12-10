#pragma once

#include <QObject>
#include <QtSql/qtsqlglobal.h>
#include <QtSql/qsqldatabase.h>
#include <QDebug>
#include <qsqlerror.h>
#include <qsqlquery.h>
#include <QStringList>

class dataBase : public QObject
{
	Q_OBJECT

public:
	dataBase(QObject *parent);
	~dataBase();

	void emitData(); //emits all directories read in from the databaase

private:
	QSqlDatabase db;

public slots:
	void slotAddNewDirToDB(const QString &path); //handles adding new directory to database
	void slotRemoveFromDB(const QString &path); //handles removing directory from database
	void slotAddNewDestToDB(const QString &path); //adds destination to database
	void slotRemoveDestFromDB(const QString &path); //removes saved destination from database

signals:
	void dirsLoadedFromDB(const QStringList &paths); //signal that is emitted from emitData
	void destLoadedFromDB(const QString &path);
};