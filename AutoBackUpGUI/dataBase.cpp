#include "dataBase.h"
//lambda to output error to console
auto ERROR = [](auto &dbObject) { qDebug() << "Database Error " << dbObject.lastError().text(); };

dataBase::dataBase(QObject *parent) : QObject(parent) {
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("savedDirectories.db"); //database to open, creates it if it doesn't exist

	if (!db.open()) {
		ERROR(db);
	}

	//create tables in db for watched directories
	QSqlQuery query("CREATE TABLE IF NOT EXISTS watchedDirs (path ABSOLUTE PATH)", db);

	if (!query.exec()) {
		ERROR(query);
	}
	//create table for destination directories
	query.clear();
	query.prepare("CREATE TABLE IF NOT EXISTS destinationDir (path ABSOLUTE PATH)");

	if (!query.exec()) {
		ERROR(query);
	}
	db.close();
}

dataBase::~dataBase() {}

void
dataBase::slotAddNewDirToDB(const QString &path) {
	if (db.open()) {
		QSqlQuery query(db);

		if (!query.prepare("INSERT INTO watchedDirs VALUES(:path)")) {
			ERROR(query);
		}
		query.bindValue(":path", path);

		if (!query.exec()) {
			ERROR(query);
		}
		db.commit(); //commit changes to database
		db.close();
	}
	else {
		ERROR(db);
	}
}

void
dataBase::slotRemoveFromDB(const QString &path) {
	if (db.open()) {
		QSqlQuery query(db);

		if (!query.prepare("DELETE FROM watchedDirs WHERE path = :path")) {
			ERROR(query);
		}
		query.bindValue(":path", path);

		if (!query.exec()) {
			ERROR(query);
		}
		db.commit();
		db.close();
	}
	else {
		ERROR(db);
	}
}

void
dataBase::slotAddNewDestToDB(const QString &path) {
	if (db.open()) {
		QSqlQuery query(db);

		if (!query.prepare("INSERT INTO destinationDir VALUES(:path)")) {
			ERROR(query);
		}
		query.bindValue(":path", path);

		if (!query.exec()) {
			ERROR(query);
		}
		db.commit(); //commit changes to database
		db.close();
	}
	else {
		ERROR(db);
	}
}

void
dataBase::slotRemoveDestFromDB(const QString &path) {
	if (db.open()) {
		QSqlQuery query(db);

		if (!query.prepare("DELETE FROM destinationDir WHERE path = :path")) {
			ERROR(query);
		}
		query.bindValue(":path", path);

		if (!query.exec()) {
			ERROR(query);
		}
		db.commit();
		db.close();
	}
	else {
		ERROR(db);
	}
}

void
dataBase::emitData() {
	if (db.open()) {
		QSqlQuery query(db);
		query.prepare("SELECT path FROM watchedDirs"); //get data from path column in table directories in database

		if (!query.exec()) {
			ERROR(query);
		}

		QStringList pathList;
		while (query.next()) { //get each row which contains directories and add to list
			pathList.append(query.value(0).toString());
		}

		query.clear();
		query.prepare("SELECT path FROM destinationDir");

		if (!query.exec()) {
			ERROR(query);
		}
		query.next();
		QString dest = query.value(0).toString();

		db.close();

		emit dirsLoadedFromDB(pathList); // emit list of paths loaded from database
		//emit destLoadedFromDB(dest);
	}
	else {
		ERROR(db);
	}
}
