#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QMainWindow>
#include "header.h"
#include "mysql.h"
#include "main_view_2.h"

namespace Ui {
class Sign_up;
}

class Sign_up : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sign_up(QWidget *parent = 0);
    ~Sign_up();

private slots:
    void on_btn_login_clicked();

    void on_btn_join_clicked();

private:
    Ui::Sign_up *ui;
};

#endif // SIGN_UP_H
