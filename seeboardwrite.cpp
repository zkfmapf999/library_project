#include "seeboardwrite.h"
#include "ui_seeboardwrite.h"
#include "seeboard.h"

seeboardWrite::seeboardWrite(QString order) :
    ui(new Ui::seeboardWrite)
{
    ui->setupUi(this);

    ui->fontComboBox->addItem("주제를 선택하세요");
    ui->fontComboBox->addItem("2층 도서관(좌석)");
    ui->fontComboBox->addItem("3층 도서관(도서관예매/반납)");
    ui->fontComboBox->addItem("관리자 문의");
    ui->fontComboBox->addItem("스터디 및 동아리활동");
    ui->fontComboBox->addItem("분실 신고");
    ui->fontComboBox->addItem("기타");

    mysql my;

    QSqlQuery query;

    query.prepare("select stuName from myinfo");
    query.exec();
    query.next();
    stuName = query.value(0).toString();
    ui->label_2->setText(stuName);
    qDebug()<<"stuName : " + stuName;

    orderText = order;

}

seeboardWrite::~seeboardWrite()
{
    delete ui;
}

void seeboardWrite::on_pushButton_2_clicked() //종료하기 버튼
{
    seeboard *see = new seeboard(NULL);
    see->show();
    close();
}

void seeboardWrite::on_pushButton_clicked() //글 게시하기
{
    mysql my;

    QString str = ui->textEdit->toPlainText();
    orderTitle = ui->fontComboBox->currentText();

    const QString time_format = "yyyyMMdd";
    QDate currentTime = QDate::currentDate();
    QString writetime = currentTime.toString(time_format);
    writetime.insert(4,"년");
    writetime.insert(7,"월");
    writetime.insert(10,"일");

    QSqlQuery query;
    query.prepare("insert seeboard(stuName,writeTitle,writeText,ordertext,writeTime)"
                  " values(:stuname,:writetitle,:writetext,:order,:writetime)");
    query.bindValue(":stuname",stuName);
    query.bindValue(":writetitle",orderTitle);
    query.bindValue(":writetext",str);
    query.bindValue(":order",orderText);
    query.bindValue(":writetime",writetime);

    if(query.exec())
    {
        qDebug()<<"seeboard에 저장성공";
        qDebug()<<"stuname : " + stuName + str;
        qDebug()<<"order : "<<orderText;

        //myinfo seeNum에 1저장하기 게시판 쓸기회 한번임
        query.prepare("update myinfo set seeNum = :seenum");
        query.bindValue(":seenum","1");
        if(query.exec())
        {
            qDebug()<<"myinfo 게시판 기회 성공";
        }
        else
        {
            qDebug()<<"myinfo 게시판 기회 실패";
        }

    }
    else
    {
        qDebug()<<"seeboard에 저장실패";
        qDebug()<<query.lastError();
    }


    seeboard *see = new seeboard();
    see->show();
    close();

}
