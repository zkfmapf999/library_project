#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include <QDialog>
//////////////library view header //////////
#include "library_list.h"
#include "library_find.h"
#include "library_seat.h"
#include "mysql.h"
#include "myinfo.h"
#include "seeboard.h"
#include "alertbook.h"
#include "library_recommand.h"
#include "library_admin.h"

namespace Ui {
class Main_View;
}

class Main_View : public QDialog
{
    Q_OBJECT

public:
    explicit Main_View(QWidget *parent = 0);
    ~Main_View();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Main_View *ui;
};

#endif // MAIN_VIEW_H
