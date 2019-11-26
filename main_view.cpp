#include "main_view.h"
#include "ui_main_view.h"
#include "mysql.h"

Main_View::Main_View(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_View)
{
    ui->setupUi(this);

    setFixedSize(808,522);

    mysql my;


    QSqlQuery query;
    query.prepare("select stuName from myinfo");
    query.exec();
    query.next();
    const QString myinfoName = query.value(0).toString(); //myinfo 학생이름

    query.prepare("select adminName from admin");
    query.exec();
    query.next();
    const QString adminName = query.value(0).toString(); //admin 이름

    if(myinfoName != adminName) ui->pushButton_6->hide();
    else
    {
        QMessageBox msgBox;
        msgBox.setText("관리자 영역입니다.");
        msgBox.exec();
    }

    //admin todaystudent의 한명이 올때마다 증가. 그리고 12시돼면 알아서 초기화
    query.prepare("select todayStudent from admin");
    query.exec();
    query.next();
    int todayStudentCount = query.value(0).toInt();
    qDebug()<<"todayStudentCount : " <<todayStudentCount;

    //todayStudentCount 올리기.
    todayStudentCount++;

    //만약 현재시간 23시30분 이후라면 0으로 초기화.....
    QTime time = QTime::currentTime();
    const quint64 currentTime = time.toString("hhmmss").toInt();
    qDebug()<<"CurrentTime : "<<currentTime;

    //23시30분
    if(currentTime > 233000) {todayStudentCount = 0;}

    query.prepare("update admin set todayStudent = :count where adminName = :admin");
    query.bindValue(":count",todayStudentCount);
    query.bindValue(":admin","admin");
    if(query.exec())
    {
        qDebug()<<"MainView Count올림 성공";
    }
    else
    {
        qDebug()<<"MainView Count안됨 실패";
        qDebug()<<query.lastError();
    }
}

Main_View::~Main_View()
{
    delete ui;
}

void Main_View::on_pushButton_clicked() //도서목록
{
    Library_list *library_list = new Library_list();
    library_list->show();
    close();
}



void Main_View::on_pushButton_8_clicked() //종료하기
{
    Sign_up *sign = new Sign_up();
    sign->show();
    close();
}

void Main_View::on_pushButton_4_clicked() //좌석예약
{
    library_seat *seat = new library_seat;
    seat->show();
    close();
}

void Main_View::on_pushButton_2_clicked() //도서찾기 예약
{
    library_find *find = new library_find;
    find->show();
    close();
}

void Main_View::on_pushButton_7_clicked()
{
    myinfo *my = new myinfo;
    my->show();
}

void Main_View::on_pushButton_3_clicked()
{
    seeboard *see = new seeboard();
    see->show();
    close();
}

void Main_View::on_pushButton_5_clicked()
{
    library_recommand *recommand = new library_recommand();
    recommand->show();
}

void Main_View::on_pushButton_6_clicked()
{
    library_admin *admin = new library_admin();
    admin->show();
}
