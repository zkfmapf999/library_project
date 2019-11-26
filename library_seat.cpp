#include "library_seat.h"
#include "ui_library_seat.h"
#include "secound_floor.h"
#include "thrid_floor.h"

library_seat::library_seat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::library_seat)
{
    ui->setupUi(this);

    mysql my;
    QSqlQuery query;

    //2층
    query.prepare("select count(occupy) from reservseat");
    query.exec();
    query.next();
    int maxInt = 164; //전체좌석

    int data = query.value(0).toInt();

    QString max = QString::number(maxInt);
    QString result = QString::number(maxInt - data);

    qDebug()<<data;

    //3층


    ui->label_2->setText("전체 : " + max + " / 잔여 : " + result);
    ui->label_3->setText(" ");
}

library_seat::~library_seat()
{
    delete ui;
}

void library_seat::on_pushButton_clicked()
{
    secound_Floor *secound = new secound_Floor();
    secound->show();
    close();
}

void library_seat::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Notice","서비스 준비 중 입니다.");
}

void library_seat::on_pushButton_3_clicked()
{
    Main_View *main = new Main_View();
    main->show();
    close();
}

void library_seat::on_pushButton_4_clicked()
{
    QMessageBox::information(this,"Notice","서비스 준비 중 입니다.");
}
