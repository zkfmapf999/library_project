#ifndef LIBRARY_SEAT_H
#define LIBRARY_SEAT_H

#include "main_view.h"
#include <QWidget>

namespace Ui {
class library_seat;
}

class library_seat : public QWidget
{
    Q_OBJECT

public:
    explicit library_seat(QWidget *parent = 0);
    ~library_seat();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::library_seat *ui;
};

#endif // LIBRARY_SEAT_H
