#include "library_admin.h"
#include "ui_library_admin.h"

library_admin::library_admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::library_admin)
{
    ui->setupUi(this);

    mysql my;
    QSqlQuery query;

    //학생정보
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("select name, num, major, campus from student");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("학생 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("학번"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("학과"));
    my.mModel->setHeaderData(3,Qt::Horizontal,tr("캠퍼스"));

    ui->stuTableView->setModel(my.mModel);

    //좌석현황
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("select name, reservLocation, whenend from reservseat");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("학생 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("좌석번호"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("끝나는시간"));

    ui->seatTableView->setModel(my.mModel);

    //책 예약현황
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery("select stuName, bookName, whengive from borrowbook");
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("학생 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("책 이름"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("반납 날짜"));

    ui->bookTableView->setModel(my.mModel);

    //총 회원수
    query.prepare("select count(name) from student");
    query.exec();
    query.next();
    const int studentCount = query.value(0).toInt();
    const QString studentCountString = QString::number(studentCount);
    ui->total1->setText(studentCountString + " 명");

    //금일 방문수
    query.prepare("select todayStudent from admin");
    query.exec();
    query.next();
    const int todayStudentCount = query.value(0).toInt();
    const QString todayStudentCountString = QString::number(todayStudentCount);
    ui->total2->setText(todayStudentCountString + "명");

    //책 현황개수
    query.prepare("select count(name) from book");
    query.exec();
    query.next();
    const int bookCount = query.value(0).toInt();
    const QString bookCountString = QString::number(bookCount);
    ui->total3->setText(bookCountString + " 권");

    //책 예약개수
    query.prepare("select count(stuName) from borrowbook");
    query.exec();
    query.next();
    const int reservCount = query.value(0).toInt();
    const QString reservCountString = QString::number(reservCount);
    ui->total4->setText(reservCountString + " 명");

    //좌석 예약 수
    query.prepare("select count(name) from reservseat");
    query.exec();
    query.next();
    const int reservSeatCount = query.value(0).toInt();
    const QString reservSeatCountString = QString::number(reservSeatCount);
    ui->total5->setText(reservSeatCountString + " 명");

}

library_admin::~library_admin()
{
    delete ui;
}

void library_admin::on_studentFindBtn_clicked()
{
    const QString stuName = ui->lineEdit->text();

    //학생정보
    mysql my;
    my.mModel = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("select name, num, major, campus from student where name = :stuname");
    query.bindValue(":stuname",stuName);
    query.exec();
    query.next();
    my.mModel->setQuery(query);
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("학생 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("학번"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("학과"));
    my.mModel->setHeaderData(3,Qt::Horizontal,tr("캠퍼스"));

    ui->stuTableView->setModel(my.mModel);

    //좌석현황
    my.mModel = new QSqlQueryModel;
    QSqlQuery query2;
    query2.prepare("select name, reservLocation, whenend from reservseat where name = :stuname");
    query2.bindValue(":stuname",stuName);
    query2.exec();
    query2.next();
    my.mModel->setQuery(query2);
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("학생 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("좌석번호"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("끝나는시간"));

    ui->seatTableView->setModel(my.mModel);

    //책 예약현황
    my.mModel = new QSqlQueryModel;
    QSqlQuery query3;
    query3.prepare("select stuName, bookName, whengive from borrowbook where stuName = :stuname");
    query3.bindValue(":stuname",stuName);
    query3.exec();
    query3.next();
    my.mModel->setQuery(query3);
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("학생 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("책 이름"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("반납 날짜"));

    ui->bookTableView->setModel(my.mModel);
}
