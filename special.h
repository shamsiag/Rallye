#ifndef SPECIAL_H
#define SPECIAL_H

#include <QObject>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include "temps.h"

class Special {
public:
    int id;
    QString nom;
    int idCourse;
    QVector<Temps> resultats;

    // Constructor
    Special(){}
    Special(int nid, const QString nnom, int nidCourse, QVector<Temps> nresultats) : id(nid), nom(nnom), idCourse(nidCourse), resultats(nresultats) {}
    Special(const QString nnom, int nidCourse) : nom(nnom), idCourse(nidCourse) {}
    Special(const QString nnom) : nom(nnom){}
    Special(int nid, const QString nnom, int nidCourse) : id(nid), nom(nnom), idCourse(nidCourse){}
    bool insertIntoDatabase();
    // Method declarations

private:
         // Private members and methods if any
};

#endif // SPECIAL_H
