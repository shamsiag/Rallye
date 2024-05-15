#ifndef INSCRIT_H
#define INSCRIT_H

#include <QObject>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

class Inscrit : public QObject
{
public:
    int id;
    QString nom;
    int idGroupe;

    explicit Inscrit(QObject *parent = nullptr);
    explicit Inscrit(int nid, const QString nnom, int nidGroupe, QObject *parent = nullptr);

    int getId() const { return id; }
    void setId(int nid) { id = nid; }

    QString getNom() const { return nom; }
    void setNom(const QString &nnom) { nom = nnom; }

    int getIdGroupe() const { return idGroupe; }
    void setIdGroupe(int nidGroupe) { idGroupe = nidGroupe; }

    // Method to get a specific Inscrit by ID
    static Inscrit* getInscrit(int id);

    // Method to get all Inscrits
    static QVector<Inscrit*> getAllInscrits();
    void changeGroupe(int nidGroupe);

};

#endif // INSCRIT_H
