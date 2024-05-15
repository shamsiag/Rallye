#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "groupe.h"

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSpinBox>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayGroups();
    QVector<Groupe> getAllGroups();
    void onRadioButtonSelected(const QString &name);

private slots:
    void onBoutonValiderClicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
    QVector<Groupe> groups;
    QSpinBox *spinBox;
    QMap<int,QCheckBox*> radioButtonsMap;
};
#endif // MAINWINDOW_H
