#ifndef COURSE_H
#define COURSE_H

#include <QObject>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include "inscrit.h"
#include "special.h"

class Course
{
public:
    Course();
    Course (QVector<Inscrit*> ninscrits, QVector<Special*> nspeciaux): inscrits(ninscrits), speciaux(nspeciaux){}
    Course (int nid, QVector<Inscrit*> ninscrits, QVector<Special*> nspeciaux): id(nid),inscrits(ninscrits), speciaux(nspeciaux){}

    int id;
    QVector<Inscrit*> inscrits;
    QVector<Special*> speciaux;

    static int insertNewCourse();
};

#endif // COURSE_H
