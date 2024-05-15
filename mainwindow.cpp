#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "groupe.h"
#include "inscrit.h"
#include "course.h"
#include "formtemps.h"
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QDebug>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("RALLYE - Nouvelle course");
    spinBox = ui->spinBox;
    // Display of inscrits radios
    QVector<Inscrit*> allInscrits = Inscrit::getAllInscrits();

    // Directly add radio buttons to the existing layout of layoutWidget
    foreach (Inscrit* inscrit, allInscrits) {
        QCheckBox *checkBox = new QCheckBox(inscrit->getNom());
        checkBox->setObjectName(QString::number(inscrit->getId()));
        checkBox->setChecked(false); // Uncheck initially
        ui->layoutWidget->layout()->addWidget(checkBox); // Add checkbox to the existing layout

        // Store the checkbox in the map
        radioButtonsMap[inscrit->getId()] = checkBox;

        // Connect the checkbox's toggled signal to a slot that handles selection
        connect(checkBox, &QCheckBox::stateChanged, this, [this, checkBox]() {
            if (checkBox->isChecked()) {
                qDebug() << "Checkbox selected: " << checkBox->text();
                // Perform your action here
            } else {
                qDebug() << "Checkbox deselected: " << checkBox->text();
                // Optionally, handle deselection
            }
        });
    }

    connect(ui->boutonValider, &QPushButton::clicked, this, &MainWindow::onBoutonValiderClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBoutonValiderClicked()
{
    int numberofSpecials= spinBox->value();
    //nouvelle course
    Course* rallye=new Course();
    int idCourse=rallye->insertNewCourse();
    //retrieve checked inscrits
    QVector<Inscrit*> allInscrits = Inscrit::getAllInscrits();
    int temoin=0;
    QVector<Inscrit*> checkedInscrits;
    foreach (Inscrit* inscrit, allInscrits) {
        if (radioButtonsMap[inscrit->getId()]->isChecked()) {
            /*if(temoin==0)
            {
                inscrit->setIdGroupe(1);
                inscrit->changeGroupe(temoin+1);
                temoin++;
            }
            else if(temoin==1)
            {
                inscrit->setIdGroupe(2);
                inscrit->changeGroupe(temoin+1);
                temoin++;
            }
            else if(temoin==2)
            {
                inscrit->setIdGroupe(3);
                inscrit->changeGroupe(temoin+1);
                temoin=0;
            }*/
            checkedInscrits.append(inscrit);
        }
    }

    //tableau de special
    QVector<Special*> specials;
    for (int i = 0; i < numberofSpecials ; ++i) {
        Special* special = new Special();
        special->nom = "S" + QString::number(i + 1);
        special->idCourse=idCourse;
        specials.append(special);
        special->insertIntoDatabase();
    }
    //initialisation de la course
    rallye->id=idCourse;
    rallye->inscrits=checkedInscrits;
    rallye->speciaux=specials;

    //nouvelle fenetre
    FormTemps *formTemps = new FormTemps(this, rallye);
    formTemps->show();
}
