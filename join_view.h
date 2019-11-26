#ifndef JOIN_VIEW_H
#define JOIN_VIEW_H

#include <QDialog>
#include "header.h"
#include "mysql.h"

namespace Ui {
class Join_view;
}

class Join_view : public QDialog
{
    Q_OBJECT

public:
    explicit Join_view(QWidget *parent = 0);
    ~Join_view();

private slots:
    void on_btn_complete_clicked();

    void on_btn_cancel_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Join_view *ui;

};

#endif // JOIN_VIEW_H
