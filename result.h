#ifndef RESULT_H
#define RESULT_H

#include <QMainWindow>

#include "course.h"

namespace Ui {
class Result;
}

class Result : public QMainWindow
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr, Course* rallye = nullptr);
    ~Result();

private:
    Ui::Result *ui;
    Course* rallye;
};

#endif // RESULT_H
