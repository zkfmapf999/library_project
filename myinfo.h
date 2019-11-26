#ifndef MYINFO_H
#define MYINFO_H

#include <QWidget>
#include "mysql.h"
#include "main_view.h"

namespace Ui {
class myinfo;
}

class myinfo : public QWidget
{
    Q_OBJECT

public:
    explicit myinfo(QWidget *parent = 0);
    ~myinfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::myinfo *ui;
};

#endif // MYINFO_H
