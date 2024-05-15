#include "result.h"
#include "ui_result.h"
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QStandardItem>

Result::Result(QWidget *parent,Course* rallye)
    : QMainWindow(parent),
    ui(new Ui::Result),
    rallye(rallye)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT * FROM v_resultatParCourse WHERE course_id = :id");
    query.bindValue(":id", rallye->id);
    query.exec();
    qDebug() << "id result=" << rallye->id;

    // Créez un QStandardItemModel
    QStandardItemModel *model = new QStandardItemModel(this);
    model->setRowCount(query.size());
    model->setColumnCount(4); // Ajustez selon le nombre de colonnes que vous souhaitez afficher

    // Ajoutez les colonnes souhaitées
    model->setHeaderData(0, Qt::Horizontal, tr("Participant"));
    model->setHeaderData(1, Qt::Horizontal, tr("Minute"));
    model->setHeaderData(2, Qt::Horizontal, tr("Seconde"));
    model->setHeaderData(3, Qt::Horizontal, tr("Milliseconde"));

    // Remplissez le modèle avec les données de la requête
    int row = 0;
    while (query.next()) {
        qDebug() << "result not empty";
        model->setItem(row, 0, new QStandardItem(query.value("inscrit_name").toString()));
        model->setItem(row, 1, new QStandardItem(query.value("total_minutes").toString()));
        model->setItem(row, 2, new QStandardItem(query.value("total_seconds").toString()));
        model->setItem(row, 3, new QStandardItem(query.value("total_milliseconds").toString()));
        row++;
    }
    // Ajoutez le modèle à un QTableView dans votre interface utilisateur
    int index=0;
    int i=0;
    int test;
    while(i<3)
    {
        qDebug() << "in boucle result groupe";
        index=i+1;
        query.prepare("SELECT * FROM v_resultatParGroupe WHERE course_id = :id AND groupe_id= :gId");
        query.bindValue(":id", rallye->id);
        query.bindValue(":gId", index);
        query.exec();
        //test= query.size() + 1;
        //qDebug() << "test query size + 1:" << test;
        // Créez un QStandardItemModel
        QStandardItemModel *model2 = new QStandardItemModel(this);
        model2->setRowCount(query.size());
        model2->setColumnCount(4); // Ajustez selon le nombre de colonnes que vous souhaitez afficher
        //qDebug() << "result groupe size:" << query.size();
        // Ajoutez les colonnes souhaitées
        model2->setHeaderData(0, Qt::Horizontal, tr("Participant"));
        model2->setHeaderData(1, Qt::Horizontal, tr("Minute"));
        model2->setHeaderData(2, Qt::Horizontal, tr("Seconde"));
        model2->setHeaderData(3, Qt::Horizontal, tr("Milliseconde"));

        // Remplissez le modèle avec les données de la requête
        row = 0;
        while (query.next()) {
            model2->setItem(row, 0, new QStandardItem(query.value("inscrit_name").toString()));
            model2->setItem(row, 1, new QStandardItem(query.value("total_minutes").toString()));
            model2->setItem(row, 2, new QStandardItem(query.value("total_seconds").toString()));
            model2->setItem(row, 3, new QStandardItem(query.value("total_milliseconds").toString()));
            row++;
        }
        // Ajoutez le modèle à un QTableView dans votre interface utilisateur
        if(i==0)
        {
            ui->tableView_2->setModel(model2);
            /*if(query.size()<=1)
            {
                ui->tableView_2->setHidden(true);
                ui->label->setHidden(true);
            }*/

        }
        else if(i==1)
        {
            ui->tableView_3->setModel(model2);
            /*if(query.size()<=1)
            {
                ui->tableView_3->setHidden(true);
                ui->label_2->setHidden(true);
            }*/
        }
        else if (i==2)
        {
            ui->tableView_4->setModel(model2);
            /*if(query.size()<=1)
            {
                ui->tableView_4->setHidden(true);
                ui->label_3->setHidden(true);
            }*/

        }
        i++;
    }
    ui->tableView->setModel(model);
}
Result::~Result()
{
    delete ui;
}
