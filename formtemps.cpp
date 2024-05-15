#include "formtemps.h"
#include "ui_formtemps.h"

#include "result.h"

#include <QVBoxLayout>
#include <QListWidget> // For displaying the list of participants
#include <QSpinBox>

FormTemps::FormTemps(QWidget *parent,Course* rallye) :
    QMainWindow(parent),
    ui(new Ui::FormTemps),
    rallye(rallye)
{
    ui->setupUi(this);
    this->setWindowTitle("RALLYE - Enregistrement des temps");

    //select des speciaux
    comboBoxSpecials = new QComboBox(this);
    comboBoxSpecials->setObjectName("comboBoxSpecials");
    comboBoxSpecials->addItem("Select Special");
    foreach(Special* special, rallye->speciaux) {
        comboBoxSpecials->addItem(special->nom, special->id);
    }
    ui->verticalLayout->addWidget(comboBoxSpecials);

    // Dynamically create layouts for each participant
    foreach(Inscrit* inscrit, rallye->inscrits) {
        QHBoxLayout* layout2 = new QHBoxLayout;
        QLabel* nameLabel = new QLabel(inscrit->getNom());
        layout2->addWidget(nameLabel);

        QSpinBox* spinBox1 = new QSpinBox;
        spinBox1->setObjectName("spinBox1_" + QString::number(inscrit->getId()));
        QLabel* label1 = new QLabel("'");
        layout2->addWidget(spinBox1);
        layout2->addWidget(label1);

        QSpinBox* spinBox2 = new QSpinBox;
        spinBox2->setObjectName("spinBox2_" + QString::number(inscrit->getId()));
        QLabel* label2 = new QLabel("''");
        layout2->addWidget(spinBox2);
        layout2->addWidget(label2);

        QSpinBox* spinBox3 = new QSpinBox;
        spinBox3->setObjectName("spinBox3_" + QString::number(inscrit->getId()));
        QLabel* label3 = new QLabel("'''");
        layout2->addWidget(spinBox3);
        layout2->addWidget(label3);

        QWidget* participantWidget = new QWidget;
        participantWidget->setLayout(layout2);
        ui->layout->addWidget(participantWidget);
        spinBoxes["spinBox1_" + QString::number(inscrit->getId())] = spinBox1;
        spinBoxes["spinBox2_" + QString::number(inscrit->getId())] = spinBox2;
        spinBoxes["spinBox3_" + QString::number(inscrit->getId())] = spinBox3;

        connect(spinBox1, &QSpinBox::valueChanged, this, [this, inscrit](int value) { onUpdateTemps(inscrit); });
        connect(spinBox2, &QSpinBox::valueChanged, this, [this, inscrit](int value) { onUpdateTemps(inscrit); });
        connect(spinBox3, &QSpinBox::valueChanged, this, [this, inscrit](int value) { onUpdateTemps(inscrit); });
    }
    connect(ui->saveButton, &QPushButton::clicked, this, &FormTemps::onButtonSaveClicked);
    connect(ui->resultButton, &QCommandLinkButton::clicked, this, &FormTemps::onResultButtonClicked);
}

void FormTemps::onUpdateTemps(Inscrit* inscrit)
{
    qDebug() << "spinBox Changed";
    Special* selectedSpecial = nullptr;
    for (const auto& special : rallye->speciaux) {
        if (special->id == comboBoxSpecials->currentData().toInt()) {
            selectedSpecial = special;
            break;
        }
    }

    if (!selectedSpecial) {
        qDebug() << "No Special selected";
        return;
    }

    // Extract values from the spin boxes
    QSpinBox* spinBox1 = spinBoxes["spinBox1_" + QString::number(inscrit->getId())];
    QSpinBox* spinBox2 = spinBoxes["spinBox2_" + QString::number(inscrit->getId())];
    QSpinBox* spinBox3 = spinBoxes["spinBox3_" + QString::number(inscrit->getId())];

    int minute = spinBox1->value();
    int second = spinBox2->value();
    int millisecond = spinBox3->value();
    qDebug() << "minute:" << minute;
    qDebug() << "seconde:" << second;
    qDebug() << "milliseconde:" << millisecond;

    // Find or create a Temps object
    bool found = false;
    for (auto& temps : selectedSpecial->resultats) {
        if (temps.idSpecial == selectedSpecial->id && temps.idInscrit == inscrit->getId()) {
            // Update the existing Temps object
            temps.minute = minute;
            temps.seconde = second;
            temps.milliseconde = millisecond;
            found = true;
            break;
        }
    }

    if (!found) {
        // Create a new Temps object and add it to the vector
        Temps newTemps;
        newTemps.idSpecial = selectedSpecial->id;
        newTemps.idInscrit = inscrit->getId();
        newTemps.minute = minute;
        newTemps.seconde = second;
        newTemps.milliseconde = millisecond;
        selectedSpecial->resultats.append(newTemps);
    }
}

void FormTemps::onButtonSaveClicked()
{
    foreach(Special* special, rallye->speciaux) {
        foreach(Temps temps,special->resultats)
        {
            qDebug() << "saveTemps called";
            temps.saveTemps();
        }
    }
}

void FormTemps::onResultButtonClicked()
{
    Result *result=new Result(this, rallye);
    result->show();
}

FormTemps::~FormTemps()
{
    delete ui;
}
