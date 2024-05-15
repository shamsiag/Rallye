#include "special.h"

#include <QDebug>
#include <QVector>
#include <QSqlError>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>

bool Special::insertIntoDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/Users/macbookpro/rallye.db";
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }
    QSqlQuery query;
    query.prepare("INSERT INTO Special VALUES (null, :nom, :idCourse)");
    query.bindValue(":nom", this->nom);
    query.bindValue(":idCourse", this->idCourse);

    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        db.close();
        return false;
    }

    query.prepare("SELECT id FROM special ORDER BY id DESC LIMIT 1;");
    if (!query.exec()) {
        qDebug() << "Error for select special: " << query.lastError();
        db.close();
        return false;
    }
    if (query.next()) {
        this->id=query.value("id").toInt();
        qDebug() << "special retrieved successfully";
    } else {
        qDebug() << "Select special unsuccessful:" << query.lastError();
        db.close();
        return false;
    }
    db.close();
    return true;
}
