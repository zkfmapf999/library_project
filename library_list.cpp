#include "library_list.h"
#include "ui_library_list.h"
#include "main_view.h"
#include "mysql.h"

Library_list::Library_list(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Library_list)
{
    ui->setupUi(this);

    setFixedSize(800,674);


}

Library_list::~Library_list()
{
    delete ui;
}

void Library_list::on_radioButton_1_clicked() //가나다 순
{
    QMessageBox::information(this,"Notcie","가나다순 정렬");

    mysql my;
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("SELECT name, source, location, separate,favorite,reserv FROM book order by name asc");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("출판사"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("위치"));
    my.mModel->setHeaderData(3,Qt::Horizontal,tr("분류"));
    my.mModel->setHeaderData(4,Qt::Horizontal,tr("예약건수"));
    my.mModel->setHeaderData(5,Qt::Horizontal,tr("예매"));
    ui->tableView->setModel(my.mModel);

}

void Library_list::on_radioButton_2_clicked() //영어 순
{
    QMessageBox::information(this,"Notcie","숫자 순 정렬");

    mysql my;
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("select name, source, location, separate,favorite,reserv from book order by name");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("출판사"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("위치"));
    my.mModel->setHeaderData(3,Qt::Horizontal,tr("분류"));
    my.mModel->setHeaderData(4,Qt::Horizontal,tr("예약건수"));
    my.mModel->setHeaderData(5,Qt::Horizontal,tr("예매"));
    ui->tableView->setModel(my.mModel);
}

void Library_list::on_radioButton_3_clicked() //출판연월 순
{
    QMessageBox::information(this,"Notcie","출판연월 정렬");

    mysql my;
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("select name, source, location, separate,favorite,reserv from book order by Year desc");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("출판사"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("위치"));
    my.mModel->setHeaderData(3,Qt::Horizontal,tr("분류"));
    my.mModel->setHeaderData(4,Qt::Horizontal,tr("예약건수"));
    my.mModel->setHeaderData(5,Qt::Horizontal,tr("예매"));
    ui->tableView->setModel(my.mModel);
}

void Library_list::on_radioButton_4_clicked() //책 위치순
{
    QMessageBox::information(this,"Notcie","책 위치 순");

    mysql my;
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("select name, source, location, separate,favorite,reserv from book order by location asc");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("출판사"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("위치"));
    my.mModel->setHeaderData(3,Qt::Horizontal,tr("분류"));
    my.mModel->setHeaderData(4,Qt::Horizontal,tr("예약건수"));
    my.mModel->setHeaderData(5,Qt::Horizontal,tr("예매"));
    ui->tableView->setModel(my.mModel);
}

void Library_list::on_radioButton_5_clicked() // 책 분류순
{
    QMessageBox::information(this,"Notcie","책 분류 순");

    mysql my;
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("select name, source, location, separate,favorite,reserv from book order by separate asc");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("출판사"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("위치"));
    my.mModel->setHeaderData(3,Qt::Horizontal,tr("분류"));
    my.mModel->setHeaderData(4,Qt::Horizontal,tr("예약건수"));
    my.mModel->setHeaderData(5,Qt::Horizontal,tr("예매"));
    ui->tableView->setModel(my.mModel);
}

void Library_list::on_pushButton_clicked() //종료하기
{
    Main_View *main = new Main_View();
    main->show();
    close();
}

void Library_list::on_pushButton_2_clicked() //도움말
{
    QMessageBox msg;
    msg.setText("---가나다 순 : 가나다 순으로 목록을 표시합니다.\n"
                "---알파벳 순 : 알파벳 ABC 순으로 목록을 표시합니다.\n"
                "---출판연 순 : 최근의 나온 책 순으로 목록을 표시합니다.\n"
                "---책위치 순 : 책이 놓인 위치 순대로 목록을 표시합니다.\n"
                "---책분류 순 : 분류순서대로 목록을 표시합니다.\n");
    msg.exec();
}
