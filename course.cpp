#include "course.h"

#include "inscrit.h"

#include <QDebug>
#include <QVector>
#include <QSqlError>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>

Course::Course() {}

int Course::insertNewCourse(){
    int idValue;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/Users/macbookpro/rallye.db";
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }
    QSqlQuery query;
    query.prepare("INSERT INTO Course VALUES (null)");
    if (!query.exec()) {
        qDebug() << "Error inserting course: " << query.lastError();
    } else {
        qDebug() << "Course inserted successfully";
    }

    query.prepare("SELECT id FROM course ORDER BY id DESC LIMIT 1;");
    if (!query.exec()) {
        qDebug() << "Error for select course: " << query.lastError();
    }
    if (query.next()) {
        idValue = query.value("id").toInt();
        qDebug() << "Course retrieved successfully";
    } else {
        qDebug() << "Select course unsuccessful:" << query.lastError();
    }
    db.close();
    return idValue;
}

