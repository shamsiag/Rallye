/********************************************************************************
** Form generated from reading UI file 'formtemps.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTEMPS_H
#define UI_FORMTEMPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormTemps
{
public:
    QWidget *centralwidget;
    QPushButton *saveButton;
    QCommandLinkButton *resultButton;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FormTemps)
    {
        if (FormTemps->objectName().isEmpty())
            FormTemps->setObjectName("FormTemps");
        FormTemps->resize(744, 727);
        centralwidget = new QWidget(FormTemps);
        centralwidget->setObjectName("centralwidget");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(580, 580, 100, 32));
        resultButton = new QCommandLinkButton(centralwidget);
        resultButton->setObjectName("resultButton");
        resultButton->setGeometry(QRect(540, 610, 168, 41));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 32, 161, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 120, 171, 16));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 150, 331, 491));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 331, 481));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setObjectName("layout");
        layout->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 60, 163, 55));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FormTemps->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FormTemps);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 744, 24));
        FormTemps->setMenuBar(menubar);
        statusbar = new QStatusBar(FormTemps);
        statusbar->setObjectName("statusbar");
        FormTemps->setStatusBar(statusbar);

        retranslateUi(FormTemps);

        QMetaObject::connectSlotsByName(FormTemps);
    } // setupUi

    void retranslateUi(QMainWindow *FormTemps)
    {
        FormTemps->setWindowTitle(QCoreApplication::translate("FormTemps", "MainWindow", nullptr));
        saveButton->setText(QCoreApplication::translate("FormTemps", "Enregistrer", nullptr));
        resultButton->setText(QCoreApplication::translate("FormTemps", "Passer aux r\303\251sultats", nullptr));
        label->setText(QCoreApplication::translate("FormTemps", "Veuillez choisir un sp\303\251cial:", nullptr));
        label_2->setText(QCoreApplication::translate("FormTemps", "Renseignez les temps:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTemps: public Ui_FormTemps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTEMPS_H
