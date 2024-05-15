#include "inscrit.h"

Inscrit::Inscrit(QObject *parent) : QObject(parent) {}

Inscrit::Inscrit(int nid, const QString nnom, int nidGroupe, QObject *parent)
    : QObject(parent), id(nid), nom(nnom), idGroupe(nidGroupe) {}

void Inscrit::changeGroupe(int nidGroupe)
{
    idGroupe=nidGroupe;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/Users/macbookpro/rallye.db";
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }
    QSqlQuery query;
    query.prepare("UPDATE Inscrit SET idGroupe=:nidGroupe WHERE id=:cid");
    query.bindValue(":nidGroupe", idGroupe);
    query.bindValue(":cid",id);

    if (!query.exec()) {
        qDebug() << "Error inserting group: " << query.lastError();
    } else {
        qDebug() << "Group inserted successfully";
    }
    db.close();
}

Inscrit* Inscrit::getInscrit(int id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/Users/macbookpro/rallye.db";
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return nullptr; // Return nullptr or handle the error appropriately
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Inscrit WHERE id=:cid");
    query.bindValue(":cid", id);

    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError();
        return nullptr; // Return nullptr or handle the error appropriately
    }

    if (!query.next()) {
        qDebug() << "No Inscrit found with ID:" << id;
        return nullptr; // Return nullptr or handle the error appropriately
    }

    int nid = query.value(0).toInt();
    QString nnom = query.value(1).toString();
    int nidGroupe = query.value(2).toInt();
    Inscrit* result = new Inscrit(nid, nnom, nidGroupe);
    db.close();
    return result;
}

QVector<Inscrit*> Inscrit::getAllInscrits(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/Users/macbookpro/rallye.db";
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return QList<Inscrit*>();
    }
    Inscrit temp;
    QSqlQuery query;
    query.exec("SELECT * FROM Inscrit");

    QVector<Inscrit*> inscrits;
    while (query.next()) {
        int nid = query.value(0).toInt();
        QString nnom = query.value(1).toString();
        int nidGroupe = query.value(2).toInt();
        inscrits.append(new Inscrit(nid, nnom, nidGroupe));
    }
    db.close();
    return inscrits;
}
