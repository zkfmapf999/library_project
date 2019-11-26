#ifndef SEEBOARDWRITE_H
#define SEEBOARDWRITE_H

#include <QWidget>
#include "seeboard.h"
#include "mysql.h"
#include "header.h"

namespace Ui {
class seeboardWrite;
}

class seeboardWrite : public QWidget
{
    Q_OBJECT

public:
    explicit seeboardWrite(QString order);
    ~seeboardWrite();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::seeboardWrite *ui;
    QString stuName;
    QString orderText;
    QString orderTitle;

};

#endif // SEEBOARDWRITE_H
