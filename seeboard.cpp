#include "seeboard.h"
#include "ui_seeboard.h"

seeboard::seeboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seeboard)
{
    ui->setupUi(this);
    setFixedSize(1000,633);
    /*
    ui->text1->setText("None");
    ui->text2->setText("None");
    ui->text3->setText("None");
    ui->text4->setText("None");
    ui->text5->setText("None");
    ui->text6->setText("None");
    */

    mysql my;
    int count = 0;
    while(true)
    {
        QSqlQuery query;
        query.prepare("select stuName, writeTitle,writeText, orderText, writeTime from seeboard where ordertext = :ordertext");
        query.bindValue(":ordertext",QString::number(count));
        query.exec();

        if(query.next())
        {
            qDebug()<<"존재한다.";
            qDebug()<<QString::number(count);

            stuName = query.value(0).toString();
            stuText = query.value(1).toString();
            plusddd = query.value(2).toString();
            orderText = query.value(3).toString();
            const QString writeTime = query.value(4).toString();

            if(orderText == "0")
            {
                qDebug()<<"0";
                ui->label_4->setText(stuName);
                ui->text1->setText(stuText);
                ui->weather1->setText(writeTime);
            }
            else if(orderText == "1")
            {
                qDebug()<<"1";
                ui->label_5->setText(stuName);
                ui->text2->setText(stuText);
                ui->weather2->setText(writeTime);
            }
            else if(orderText == "2")
            {
                qDebug()<<"2";
                ui->label_16->setText(stuName);
                ui->text3->setText(stuText);
                ui->weather3->setText(writeTime);
            }
            else if(orderText == "3")
            {
                qDebug()<<"3";
                ui->label_17->setText(stuName);
                ui->text4->setText(stuText);
                ui->weather4->setText(writeTime);
            }
            else if(orderText == "4")
            {
                qDebug()<<"4";
                ui->label_18->setText(stuName);
                ui->text5->setText(stuText);
                ui->weather5->setText(writeTime);
            }
            else if(orderText == "5")
            {
                qDebug()<<"5";
                ui->label_19->setText(stuName);
                ui->text6->setText(stuText);
                ui->weather6->setText(writeTime);
            }
        }
        else
        {
            qDebug()<<"존재하지 않는다.";
            qDebug()<<QString::number(count);
        }

        count++;
        if(count == 6)
        {
            qDebug()<<"없어용";
            break;
        }
    }
}

seeboard::~seeboard()
{
    delete ui;
}

void seeboard::on_pushButton_16_clicked() //종료하기 버튼
{
    Main_View *main = new Main_View();
    main->show();
    close();
}

void seeboard::on_pushButton_15_clicked() //글 쓰기 버튼
{
    mysql my;
    QSqlQuery query;

    query.prepare("select stuName from myinfo");
    query.exec();

    if(query.next())
    {
        qDebug()<<"성공";
    }
    else
    {
        qDebug()<<"실패";
    }
    QString name = query.value(0).toString();

    qDebug()<<"name : "<<name;

    //myinfo seeOpportunity 1이면 더이상 게시할수없다.
    query.prepare("select seeNum from myinfo where stuName = :stuname");
    query.bindValue(":stuname",name);
    if(query.exec())
    {
        qDebug()<<"myinfo seenum 성공";
    }
    else
    {
        qDebug()<<"myinfo seenum 실패";
    }
    if(query.next())
    {
        qDebug()<<"myinfo 가지고오기 성공";
    }
    else
    {
        qDebug()<<"myinfo 가지고오기 실패";
        qDebug()<<query.lastError();
    }

    QString seeOpportunity = query.value(0).toString();
    qDebug()<<seeOpportunity;

    if(seeOpportunity == "1")
    {
        QMessageBox::information(this,"Notice","더이상 게시할 수 없습니다.(관리자문의)");
        return ;
    }

    int count =0;
    //여기서 순서를 부여해준다.
    if(ui->text1->text() == "None") { seeText[0] = 0; }
    else if(ui->text2->text() == "None") { seeText[1] = 0; }
    else if(ui->text3->text() == "None") { seeText[2] = 0; }
    else if(ui->text4->text() == "None") { seeText[3] = 0; }
    else if(ui->text5->text() == "None") { seeText[4] = 0; }
    else if(ui->text6->text() == "None") { seeText[5] = 0; }

    qDebug()<<seeText[0];
    qDebug()<<seeText[1];
    qDebug()<<seeText[2];
    qDebug()<<seeText[3];
    qDebug()<<seeText[4];
    qDebug()<<seeText[5];

    while(true)
    {
        if(seeText[count] == 0)
        {
            break;
        }

        count++;

        if(count == 6)
        {
            break;
        }
    }

    QString countText = QString::number(count);
    qDebug()<<"Count : "<<countText;

    if(count == 6)
    {
        QMessageBox::information(this,"Notice","글을 게시할수 없습니다.");
        return ;
    }

    seeboardWrite *write = new seeboardWrite(countText);
    write->show();
    close();
}

void seeboard::on_pushButton_18_clicked() //첫번째 게시글 크게보기
{
    plusName = ui->label_4->text();
    plustxt = ui->text1->text();

    qDebug()<<plusName;
    qDebug()<<plustxt;

    mysql my;
    QSqlQuery query;
    query.prepare("select writeText from seeboard where stuName = :name");
    query.bindValue(":name",plusName);
    if(query.exec())
    {
        qDebug()<<"plusddd 성공";
    }
    else
    {
        qDebug()<<"plusddd 실패";
        qDebug()<<query.lastError();
    }
    query.next();
    plusddd = query.value(0).toString();

    qDebug()<<"plusadd : "<<plusddd;

    seeplus *plus = new seeplus(plusName,plustxt,plusddd);
    plus->show();
    close();
}

void seeboard::on_pushButton_25_clicked() //두번째 게시글 크게보기
{
    plusName = ui->label_5->text();
    plustxt = ui->text2->text();

    mysql my;
    QSqlQuery query;
    query.prepare("select writeText from seeboard where stuName = :name");
    query.bindValue(":name",plusName);
    if(query.exec())
    {
        qDebug()<<"plusddd 성공";
    }
    else
    {
        qDebug()<<"plusddd 실패";
        qDebug()<<query.lastError();
    }
    query.next();
    plusddd = query.value(0).toString();

    qDebug()<<"plusadd : "<<plusddd;

    seeplus *plus = new seeplus(plusName,plustxt,plusddd);
    plus->show();
    close();
}

void seeboard::on_pushButton_26_clicked() //세번째 게시글 크게보기
{
    plusName = ui->label_16->text();
    plustxt = ui->text3->text();

    mysql my;
    QSqlQuery query;
    query.prepare("select writeText from seeboard where stuName = :name");
    query.bindValue(":name",plusName);
    if(query.exec())
    {
        qDebug()<<"plusddd 성공";
    }
    else
    {
        qDebug()<<"plusddd 실패";
        qDebug()<<query.lastError();
    }
    query.next();
    plusddd = query.value(0).toString();

    qDebug()<<"plusadd : "<<plusddd;
    seeplus *plus = new seeplus(plusName,plustxt,plusddd);
    plus->show();
    close();
}

void seeboard::on_pushButton_27_clicked() //네번째 게시글 크게보기
{
    plusName = ui->label_17->text();
    plustxt = ui->text4->text();

    mysql my;
    QSqlQuery query;
    query.prepare("select writeText from seeboard where stuName = :name");
    query.bindValue(":name",plusName);
    if(query.exec())
    {
        qDebug()<<"plusddd 성공";
    }
    else
    {
        qDebug()<<"plusddd 실패";
        qDebug()<<query.lastError();
    }
    query.next();
    plusddd = query.value(0).toString();

    qDebug()<<"plusadd : "<<plusddd;

    seeplus *plus = new seeplus(plusName,plustxt,plusddd);
    plus->show();
    close();
}

void seeboard::on_pushButton_28_clicked() //다섯번째 게시글 크게보기
{
    plusName = ui->label_18->text();
    plustxt = ui->text5->text();

    mysql my;
    QSqlQuery query;
    query.prepare("select writeText from seeboard where stuName = :name");
    query.bindValue(":name",plusName);
    if(query.exec())
    {
        qDebug()<<"plusddd 성공";
    }
    else
    {
        qDebug()<<"plusddd 실패";
        qDebug()<<query.lastError();
    }
    query.next();
    plusddd = query.value(0).toString();

    qDebug()<<"plusadd : "<<plusddd;

    seeplus *plus = new seeplus(plusName,plustxt,plusddd);
    plus->show();
    close();
}

void seeboard::on_pushButton_29_clicked() //여섯번째 게시글 크게보기
{
    plusName = ui->label_19->text();
    plustxt = ui->text6->text();

    mysql my;
    QSqlQuery query;
    query.prepare("select writeText from seeboard where stuName = :name");
    query.bindValue(":name",plusName);
    if(query.exec())
    {
        qDebug()<<"plusddd 성공";
    }
    else
    {
        qDebug()<<"plusddd 실패";
        qDebug()<<query.lastError();
    }
    query.next();
    plusddd = query.value(0).toString();

    qDebug()<<"plusadd : "<<plusddd;

    seeplus *plus = new seeplus(plusName,plustxt,plusddd);
    plus->show();
    close();
}

/*
void seeboard::on_pushButton_17_clicked()
{
    //확인 취소를 하고 확인을 누르면 해당하는 게시물을 삭제한다.

    QMessageBox msgBox;
    msgBox.setText(stuName + "의 글을 삭제하시겠습니까?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    int ret = msgBox.exec();

    if(ret == QMessageBox::Yes)
    {
        mysql my;

        QSqlQuery query;
        query.prepare("delete from seeboard where stuName = :stuname");
        query.bindValue(":stuname",stuName);
        if(query.exec())
        {
            qDebug()<<"글 지웠다.";

            query.prepare("update myinfo myinfo set seeNum = :seeNum");
            query.bindValue(":seeNum","0");
            if(query.exec())
            {
                qDebug()<<"myinfo seeNum 성공";
            }
            else
            {
                qDebug()<<"myinfo seeNum 실패";
            }

            seeboard *see = new seeboard();
            see->show();
            close();
        }
        else
        {
            qDebug()<<"글 못지웠다";
        }
    }
    else if(ret == QMessageBox::No)
    {

        qDebug()<<"취소";
        return ;

    }
}
*/

void seeboard::on_del_1_clicked()
{
    mysql my;
    //orderText 0
    my.SeeBoardDeleteText("0");

    seeboard *see = new seeboard();
    see->show();
    close();
}

void seeboard::on_del_2_clicked()
{
    mysql my;
    //orderText 1
    my.SeeBoardDeleteText("1");

    seeboard *see = new seeboard();
    see->show();
    close();
}

void seeboard::on_del_3_clicked()
{
    mysql my;
    //orderText 2
    my.SeeBoardDeleteText("2");

    seeboard *see = new seeboard();
    see->show();
    close();
}

void seeboard::on_del_4_clicked()
{
    mysql my;
    //orderText 3
    my.SeeBoardDeleteText("3");

    seeboard *see = new seeboard();
    see->show();
    close();
}

void seeboard::on_del_5_clicked()
{
    mysql my;
    //orderText 4
    my.SeeBoardDeleteText("4");

    seeboard *see = new seeboard();
    see->show();
    close();
}

void seeboard::on_del_6_clicked()
{
    mysql my;
    //orderText 5
    my.SeeBoardDeleteText("5");

    seeboard *see = new seeboard();
    see->show();
    close();
}
