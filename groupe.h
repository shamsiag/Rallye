#ifndef GROUPE_H
#define GROUPE_H

#include <QObject>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class Groupe {
public:
    int id;
    QString nom;

    // Constructor
    Groupe(int id, const QString &nom) : id(id), nom(nom) {}

    // Method declarations
    void insertGroupe();
    void getGroupe(int groupId);
    void setId(int newId);
    void setNom(const QString &newNom);
    int getId() const;
    QString getNom() const;
    static QVector<Groupe> getAllGroups(); // Corrected return type to QVector<Groupe>

private:
         // Private members and methods if any
};

#endif // GROUPE_H
