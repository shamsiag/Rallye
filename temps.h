#ifndef TEMPS_H
#define TEMPS_H

#include <QObject>

class Temps
{
public:
    Temps();
    Temps(int nidSpecial,int nidGroupe, int nidInscrit,int nminute, int nseconde, int nmilliseconde) :
        idSpecial(nidSpecial), idInscrit(nidInscrit), minute(nminute), seconde(nseconde), milliseconde(nmilliseconde) {};
    int id;
    int idSpecial;
    int idInscrit;
    int minute;
    int seconde;
    int milliseconde;
    void addTemps(int nminute,int nseconde,int nmilliseconde);
    bool saveTemps();
};

#endif // TEMPS_H
