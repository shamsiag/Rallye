#include "temps.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

Temps::Temps() {
    id = 0;
    idSpecial = 0;
    idInscrit = 0;
    minute = 0;
    seconde = 0;
    milliseconde = 0;
}
void Temps::addTemps(int nminute,int nseconde,int nmilliseconde)
{
    while(nminute>0 && nseconde>0 && nmilliseconde>0)
    {
        if(nmilliseconde+milliseconde>100)
        {
            milliseconde=0.0;
            seconde++;
            nmilliseconde=0.0;
        }
        else
        {
            milliseconde+=nmilliseconde;
            nmilliseconde=0.0;
        }
        if(nseconde+seconde>60)
        {
            minute++;
            nseconde=0.0;

        }
    }
}
bool Temps::saveTemps()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/Users/macbookpro/rallye.db";
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }
    QSqlQuery query;

    if (this->idInscrit!= 0 && this->idSpecial!= 0) { // Check if idInscrit and idSpecial are not zero
        // Attempt to select the ID of a row with the matching idInscrit and idSpecial
        query.prepare("SELECT id FROM temps WHERE idInscrit = :idI AND idSpecial = :idS");
        query.bindValue(":idI", idInscrit);
        query.bindValue(":idS", idSpecial);
        if (query.exec() && query.next()) {
            // If a matching ID is found, update the values
            int existingId = query.value(0).toInt();
            query.prepare("UPDATE temps SET mn = :mn, s = :s, ms = :ms WHERE id = :id");
            query.bindValue(":mn", minute);
            query.bindValue(":s", seconde);
            query.bindValue(":ms", milliseconde);
            query.bindValue(":id", existingId);
            if (!query.exec()) {
                qDebug() << "Error updating record:" << query.lastError();
                return false;
            }
        } else {
            // If no matching ID is found, insert a new row
            query.prepare("INSERT INTO temps (id,idInscrit, idSpecial, mn, s, ms) VALUES (null,:idI, :idS, :mn, :s, :ms)");
            query.bindValue(":idI", idInscrit);
            query.bindValue(":idS", idSpecial);
            query.bindValue(":mn", minute);
            query.bindValue(":s", seconde);
            query.bindValue(":ms", milliseconde);
            if (!query.exec()) {
                qDebug() << "Error inserting record:" << query.lastError();
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}
