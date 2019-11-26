#ifndef SEEPLUS_H
#define SEEPLUS_H

#include <QWidget>
#include "seeboard.h"
#include "header.h"
#include "mysql.h"

namespace Ui {
class seeplus;
}

class seeplus : public QWidget
{
    Q_OBJECT

public:
    explicit seeplus(QString name,QString Title, QString txt);
    ~seeplus();

private slots:
    void on_pushButton_clicked();

private:
    Ui::seeplus *ui;
};

#endif // SEEPLUS_H
