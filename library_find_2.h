#ifndef LIBRARY_FIND_2_H
#define LIBRARY_FIND_2_H

#include <QWidget>
#include "library_find_2.h"
#include "header.h"
#include "mysql.h"

namespace Ui {
class library_find_2;
}

class library_find_2 : public QWidget
{
    Q_OBJECT

public:
     explicit library_find_2(QString str);
    ~library_find_2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public:
    Ui::library_find_2 *ui;

    QString BookName;
    QString name;
    QString source;
    QString author;
    QString position;
    QString separate;
    QString reserv;
};

#endif // LIBRARY_FIND_2_H
