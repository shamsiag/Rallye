#include "groupe.h"

#include <QDebug>
#include <QVector>
#include <QSqlError>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>

void Groupe::insertGroupe() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/Users/macbookpro/rallye.db";
    db.setDatabaseName(path);
        if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }
    QSqlQuery query;
    query.prepare("INSERT INTO Groupe (name) VALUES (:nom)");
    query.bindValue(":nom", nom);

    if (!query.exec()) {
        qDebug() << "Error inserting group: " << query.lastError();
    } else {
        qDebug() << "Group inserted successfully";
    }
    db.close();
}

void Groupe::getGroupe(int groupId) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/Users/macbookpro/rallye.db";
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM Groupe WHERE id = :id");
    query.bindValue(":id", groupId);

    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError();
        return;
    }

    if (query.next()) {
        id = query.value("id").toInt();
        nom = query.value("name").toString();
        qDebug() << "Group retrieved successfully";
    } else {
        qDebug() << "No group found with id: " << groupId;
    }
    db.close();
}

void Groupe::setId(int newId) {
    id = newId;
}

void Groupe::setNom(const QString &newNom) {
    nom = newNom;
}

int Groupe::getId() const {
    return id;
}

QString Groupe::getNom() const {
    return nom;
}

QVector<Groupe> Groupe::getAllGroups() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/Users/macbookpro/rallye.db";
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM Groupe");
    QVector<Groupe> groups;

    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError();
        return QVector<Groupe>();
    }

    while (query.next()) {
        Groupe group(query.value("id").toInt(), query.value("name").toString());
        qDebug() << "ID:" << query.value("id").toString() << "Name:" << query.value("name").toString();        // Correctly initializing Groupe
        groups.append(group);
    }
    qDebug() << "Retrieved all groups successfully";
    db.close();
    return groups;
}
