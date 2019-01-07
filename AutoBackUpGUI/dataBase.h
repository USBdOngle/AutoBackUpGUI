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
	void slotAddNewDestToDB(const QString &path); //adds destination to database, replaces current dest with newest one
	void slotAddRefreshTokenToDB(const QString &token); //adds refresh token for Google drive API to db and replaces current one if it exists, removes it if it receives empty string

signals:
	//all these signals handle emitting data from the DB when it is opened
	void dirsLoadedFromDB(const QStringList &paths); 
	void destLoadedFromDB(const QString &path);
	void refreshTokenLoadedFromDB(const QString &token);
};