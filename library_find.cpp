#include "library_find.h"
#include "ui_library_find.h"
#include "main_view.h"
#include "library_find_2.h"
#include "mysql.h"
#include "header.h"

library_find::library_find(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::library_find)
{
    QMessageBox::information(this,"Help","예매를 희망할 시에는"
                                         " 책이름을 클릭해주세요");

    ui->setupUi(this);
    ui->comboBox->addItem("목차");
    ui->comboBox->addItem("도서이름");
    ui->comboBox->addItem("출판사");
    ui->comboBox->addItem("작가");

    //책을 반납하지 않으면 반납하라고 알람이 울린다.
    //책 반납하지 않은거 불러온다.
    const QString time_format = "yyyyMMdd";
    QDate currentTime = QDate::currentDate();
    QString BookEndTime = currentTime.toString(time_format);
    const quint64 BookEndTimeInt = BookEndTime.toInt();
    qDebug()<<"BookEndTimeInt : "<<BookEndTimeInt;
    mysql my;
    QSqlQuery query;
    query.prepare("select stuName from myinfo");
    query.exec();
    query.next();
    const QString myInfoUserName = query.value(0).toString();


    query.prepare("select bookName, checkbook from borrowbook where whengive < :give and stuName = :stuname");
    query.bindValue(":give",BookEndTimeInt);
    query.bindValue(":stuname",myInfoUserName);
    if(query.exec())
    {
        qDebug()<<"알림로직 성공";
    }
    else
    {
        qDebug()<<"알림로직 실패";
        qDebug()<<query.lastError();
    }
    query.next();

    const QString GiveBookName = query.value(0).toString();
    const QString CheckNumber = query.value(1).toString();

    if(CheckNumber == "xx")
    {
        qDebug()<<"반납할 책이 있다.";

        QMessageBox msg;
        msg.setText("반납해야 할 책 : " + GiveBookName);
        msg.exec();
    }
    else
    {
        qDebug()<<"반납할 책이 없다";
    }

    on_pushButton_clicked();

}

library_find::~library_find()
{
    delete ui;
}

void library_find::on_pushButton_clicked() //찾기
{
    mysql my;
    QSqlQuery query;
    my.mModel = new QSqlQueryModel;

    QString text = ui->lineEdit->text();

    if(ui->comboBox->currentText() == "도서이름")
    {
        qDebug()<<"check : "<<ui->comboBox->currentText();
        qDebug()<<"check : "<<text;

        query.prepare("select name, source, author, location, separate,reserv from book where name = :txt");
        query.bindValue(":txt",text);

        /* Check
        if(query.exec())
        {
            qDebug()<<"succcess";
        }
        else
        {
            qDebug()<<"failed";
        }
        */
        query.exec();

        my.mModel->setQuery(query);

    }
    else if(ui->comboBox->currentText() == "출판사")
    {
        qDebug()<<"check : "<<ui->comboBox->currentText();
        qDebug()<<"check : "<<text;

        query.prepare("select name, source, author, location, separate,reserv from book where source = :txt");
        query.bindValue(":txt",text);

        query.exec();

        my.mModel->setQuery(query);
    }
    else if(ui->comboBox->currentText()=="작가")
    {
        qDebug()<<"check : "<<ui->comboBox->currentText();
        qDebug()<<"check : "<<text;

        query.prepare("select name, source, author, location, separate,reserv from book where author = :txt");
        query.bindValue(":txt",text);

        query.exec();

        my.mModel->setQuery(query);
    }
    else
    {
        qDebug()<<"check : nothing";

        my.mModel->setQuery("select name, source, author, location, separate,reserv from book");
    }

    my.mModel->setHeaderData(0,Qt::Horizontal,tr("책 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("출판사"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("작가"));
    my.mModel->setHeaderData(3,Qt::Horizontal,tr("책 위치"));
    my.mModel->setHeaderData(4,Qt::Horizontal,tr("책 분류"));
    my.mModel->setHeaderData(5,Qt::Horizontal,tr("예매구분"));

    ui->tableView->setModel(my.mModel);

}

void library_find::on_pushButton_2_clicked()
{
    Main_View *main = new Main_View();
    main->show();
    close();
}

//case by press the tableview
void library_find::on_tableView_doubleClicked(const QModelIndex &index)
{
    cellText = index.data().toString();
    qDebug()<<"CellText : " + cellText;

    mysql my;
    QSqlQuery query;

    library_find_2 *find2 = new library_find_2(cellText);

    find2->show();
}

void library_find::on_pushButton_3_clicked()
{
    library_find_3 *find = new library_find_3();
    find->show();
    close();
}
