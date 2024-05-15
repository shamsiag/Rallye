/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *boutonValider;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelForParticipants;
    QLabel *labelForNbreInput;
    QSpinBox *spinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(486, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        boutonValider = new QPushButton(centralwidget);
        boutonValider->setObjectName("boutonValider");
        boutonValider->setGeometry(QRect(270, 470, 136, 32));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(230, 70, 171, 143));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(layoutWidget);
        layoutWidget1->setObjectName("layoutWidget1");
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");

        gridLayout->addWidget(layoutWidget1, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");

        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        labelForParticipants = new QLabel(centralwidget);
        labelForParticipants->setObjectName("labelForParticipants");
        labelForParticipants->setGeometry(QRect(30, 140, 145, 41));
        labelForParticipants->setScaledContents(true);
        labelForParticipants->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelForParticipants->setMargin(0);
        labelForParticipants->setIndent(0);
        labelForNbreInput = new QLabel(centralwidget);
        labelForNbreInput->setObjectName("labelForNbreInput");
        labelForNbreInput->setGeometry(QRect(30, 70, 167, 35));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(30, 100, 167, 21));
        spinBox->setMaximum(999);
        spinBox->setDisplayIntegerBase(10);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 486, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        boutonValider->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        labelForParticipants->setText(QCoreApplication::translate("MainWindow", "Liste des participants:", nullptr));
        labelForNbreInput->setText(QCoreApplication::translate("MainWindow", "Nombre de sp\303\251cial:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
