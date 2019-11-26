#include "join_view.h"
#include "ui_join_view.h"

Join_view::Join_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Join_view)
{
    ui->setupUi(this);
}

Join_view::~Join_view()
{
    delete ui;
}

void Join_view::on_btn_complete_clicked() //가입완료버튼
{
    const QString name = ui->EditName->text();
    const QString num = ui->EditNum->text();
    const QString major = ui->EditMajor_2->currentText();
    const QString private_num = ui->EditPrivateNum->text();
    //const QString campus = "1";

    //중복확인 하기
    on_pushButton_clicked(); //student 학번 중복확인
    //on_pushButton_2_clicked(); //student 캠퍼스 중복확인

    mysql my;
    QSqlQuery query;
    query.prepare("INSERT INTO STUDENT(name,num,major,privateNum,campus)"
                  "VALUES(?,?,?,?,?)");

    query.addBindValue(name);
    query.addBindValue(num);
    query.addBindValue(major);
    query.addBindValue(private_num);
    query.addBindValue("1");

    if(query.exec())
    {
        qDebug()<<"insert 성공";
    }
    else
    {
        qDebug()<<"insert 실패";
        qDebug()<<query.lastError();
    }

    QMessageBox::information(this,"Notice","Complete, Join us");
    Sign_up *sign = new Sign_up();
    sign->show();
    close();
}

void Join_view::on_btn_cancel_clicked()
{
    QMessageBox::information(this,"Notice","Cancle");
    Sign_up *sign = new Sign_up();
    sign->show();
    close();
}

void Join_view::on_pushButton_clicked() //student 테이블의 학번 중복확인
{
    const QString num = ui->EditNum->text();

    mysql my;
    const bool bCheck = my.NumOverlapCheck(num);

    if(!bCheck)
    {
        QMessageBox msg;
        msg.setText(num + " 중복된 학번입니다.");
        msg.exec();

        ui->btn_complete->hide();

        /*
        Join_view *join = new Join_view();
        join->show();
        close();
        */
    }
    else
    {
        QMessageBox msg;
        msg.setText(num + " 중복되지 않았습니다.");
        msg.exec();

        ui->btn_complete->show();
    }
}

void Join_view::on_pushButton_2_clicked() //캠퍼스 중복확인
{
    QString campus = "1";

    mysql my;
    const bool bCheck = my.CampusOverlapCheck(campus);

    if(!bCheck)
    {
        QMessageBox msg;
        msg.setText(campus + " 유효하지 않은 숫자입니다.");
        msg.exec();

        ui->btn_complete->hide();

        /*
        Join_view *join = new Join_view();
        join->show();
        close();
        */
    }
    else
    {
        QMessageBox msg;
        msg.setText(campus + " 중복되지 않았습니다.");
        msg.exec();

        ui->btn_complete->show();
    }
}
