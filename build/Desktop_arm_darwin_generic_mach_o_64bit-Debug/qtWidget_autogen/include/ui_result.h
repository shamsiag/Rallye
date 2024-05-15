/********************************************************************************
** Form generated from reading UI file 'result.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULT_H
#define UI_RESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Result
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QTableView *tableView_2;
    QTableView *tableView_3;
    QTableView *tableView_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Result)
    {
        if (Result->objectName().isEmpty())
            Result->setObjectName("Result");
        Result->resize(844, 901);
        centralwidget = new QWidget(Result);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 30, 441, 481));
        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(500, 60, 321, 192));
        tableView_3 = new QTableView(centralwidget);
        tableView_3->setObjectName("tableView_3");
        tableView_3->setGeometry(QRect(500, 320, 321, 192));
        tableView_4 = new QTableView(centralwidget);
        tableView_4->setObjectName("tableView_4");
        tableView_4->setGeometry(QRect(500, 580, 321, 192));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(500, 30, 171, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(500, 290, 171, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(500, 550, 171, 16));
        Result->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Result);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 844, 24));
        Result->setMenuBar(menubar);
        statusbar = new QStatusBar(Result);
        statusbar->setObjectName("statusbar");
        Result->setStatusBar(statusbar);

        retranslateUi(Result);

        QMetaObject::connectSlotsByName(Result);
    } // setupUi

    void retranslateUi(QMainWindow *Result)
    {
        Result->setWindowTitle(QCoreApplication::translate("Result", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Result", "Groupe A", nullptr));
        label_2->setText(QCoreApplication::translate("Result", "Groupe B", nullptr));
        label_3->setText(QCoreApplication::translate("Result", "Groupe C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Result: public Ui_Result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_H
