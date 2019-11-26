#include "sign_up.h"
#include "ui_sign_up.h"

Sign_up::Sign_up(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sign_up)
{
    /*
     * 또 구현해야할것. 만약에 좌석예약이나 책을 계속할수도 있으니까 책은 총 3권빌릴수 있도록
     * 3권의 static을 지정해주고,
     * 좌석같은 경우에는 1번의 static을 미리 전역변수로 지정하자. --> 나중에 하자
     *
     * 사인업 킬때 좌석예약의 대해서 거를건 거르돼, 초기에 들어가면 이미 예약됐다는걸 해줘야한다....
     * database 2층이랑 3층나눠서 해줘야한다
     *
     * book database에 favorite을 지정해줘야한다. 할때마다 오르게.
     *
     * seeboard 게시판 수정하기 짜야한다.
     */
    ui->setupUi(this);

    //pixmap
    QPixmap pix("/Build_Item/QT/Library/Resource/kdu_logo.png");
    ui->label_img->setPixmap(pix);
    ui->label_img->setPixmap(pix.scaled(90,80,Qt::KeepAspectRatio));

    //dropbox
    ui->comboBox->addItem(QIcon("/Build_Item/QT/Library/Resource/South Korea.ico"),"Korea");
    ui->comboBox->addItem(QIcon("/Build_Item/QT/Library/Resource/China.ico"),"China");
    ui->comboBox->addItem(QIcon("/Build_Item/QT/Library/Resource/Japan.ico"),"Japan");
    ui->comboBox->addItem(QIcon("/Build_Item/QT/Library/Resource/United States of America(USA).ico"),"English");
    ui->comboBox->addItem("....");

    //빌린책 예약좌석 시간지난거 데이터 삭제하는 함수만들거임.
    mysql my;
    QSqlQuery query;

    QTime time = QTime::currentTime();
    QString currentSeatTime = time.toString("hhmmss"); //현재시간

    qDebug()<<"현재 좌석 시간 : " + currentSeatTime; //좌석없애는 시간

    //Qstring으로 받은거 quint64 처리
    const quint64 SeatEndTime = currentSeatTime.toInt();
    qDebug()<<"SeatEndTime : "<<SeatEndTime; //좌석없앨기준시간

    //2층  문제점 오후시간대 3시간후가 새벽시간대는 알아서 지워짐.....
    query.prepare("delete from reservseat where whenend < :end");
    query.bindValue(":end",SeatEndTime);
    if(query.exec())
    {
        qDebug()<<"2층 지움";
        //myinfo에 stuSeatNum
    }
    else
    {
        qDebug()<<"2층 못지움";
    }
    query.prepare("delete from myinfo");
    if(query.exec())
    {
        qDebug()<<"myinfo 깔끔히 지움";
    }
    else
    {
        qDebug()<<"myinfo 못지움";
    }

}

Sign_up::~Sign_up()
{
    delete ui;
}

void Sign_up::on_btn_login_clicked()
{
    //if 해서 학번이랑 개인번호가 맞는다면....
    QString num = ui->edit_num->text();
    QString privateNum = ui->edit_private_num->text();

    mysql my;
    bool boolean = my.CheckLogin(num, privateNum);

    if(boolean)
    {
        /*---------------------------------------*/
        Main_View *Main = new Main_View();
        main_view_2 *Main2 = new main_view_2();
        Main->show();
        Main2->show();
        close();
    }
    else
    {
        QMessageBox::information(this,"Notice","없는 학생 정보입니다.");
    }
}

void Sign_up::on_btn_join_clicked()
{
    Join_view *join = new Join_view();
    join->show();
    close();
}
