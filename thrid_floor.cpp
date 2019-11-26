#include "thrid_floor.h"
#include "ui_thrid_floor.h"
#include "library_seat.h"

thrid_floor::thrid_floor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thrid_floor)
{
    ui->setupUi(this);
    setFixedSize(1094,814);
}

thrid_floor::~thrid_floor()
{
    delete ui;
}

void thrid_floor::on_pushButton_clicked()
{
    library_seat *seat = new library_seat();
    seat->show();
    close();
}
