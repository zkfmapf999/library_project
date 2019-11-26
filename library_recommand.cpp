#include "library_recommand.h"
#include "ui_library_recommand.h"

library_recommand::library_recommand(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::library_recommand)
{
    ui->setupUi(this);

    mysql my;

    //좋아하는 책 리스트
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("SELECT name,favorite FROM book "
                        "order by favorite desc limit 10");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("책 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("예약건수"));

    ui->tableView->setModel(my.mModel);

    //신작 리스트 새로들어온 10개까지
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("SELECT name,year from book "
                        "order by year desc limit 10");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("책 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("출시연월"));

    ui->tableView_2->setModel(my.mModel);

}

library_recommand::~library_recommand()
{
    delete ui;
}
