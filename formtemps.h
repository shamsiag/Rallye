#ifndef FORMTEMPS_H
#define FORMTEMPS_H

#include <QMainWindow>
#include <QComboBox>
#include <QListWidget>
#include <QSpinBox>

#include "course.h"

namespace Ui {
class FormTemps;
}

class FormTemps : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormTemps(QWidget *parent = nullptr, Course* rallye = nullptr);
    ~FormTemps();
    void onUpdateTemps(Inscrit* inscrit);
    void onButtonSaveClicked();
    void onResultButtonClicked();
private:
    Ui::FormTemps *ui;
    Course* rallye;
    QComboBox* comboBoxSpecials;
    QMap<QString, QSpinBox*> spinBoxes;

};

#endif // FORMTEMPS_H
