#include "myinfo.h"
#include "ui_myinfo.h"

myinfo::myinfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myinfo)
{
    ui->setupUi(this);

    setFixedSize(418,639);

    mysql my;

    QSqlQuery query;
    query.prepare("select stuName from myinfo");
    query.exec();
    query.next();
    const QString sstuName = query.value(0).toString();

    qDebug()<<"student Name : "<<sstuName;

    query.prepare("select * from student where name = :Name");
    query.bindValue(":Name",sstuName);

    if(query.exec())
    {
        qDebug()<<"마이인포 열렸다.";
    }
    else
    {
        qDebug()<<"마이인포 닫혔다.";
    }
    query.next();
    const QString stuName = query.value(0).toString();
    const QString stuNum = query.value(1).toString();
    const QString stuMajor = query.value(2).toString();
    const QString QNum = query.value(4).toString();
    QString stuCampus;

    if(QNum == "1") stuCampus = "고성캠퍼스";
    else if(QNum == "2") stuCampus == "양주캠퍼스";
    else stuCampus == "문막캠퍼스";

    ui->labelName->setText(stuName);
    ui->labelNum->setText(stuNum);
    ui->labelMajor->setText(stuMajor);
    ui->labelCampus->setText(stuCampus);

    QLabel *LableGroup[4] = {ui->labelBorrowBook,ui->labelBorrowBook_3,ui->labelBorrowBook_4};
    QLabel *LableBorrowWhen[4] = {ui->labelBorrowhen,ui->labelBorrowhen_2,ui->labelBorrowhen_3};

    query.prepare("select * from borrowbook where stuName = :stuname");
    query.bindValue(":stuname",stuName);
    if(query.exec())
    {
        qDebug()<<"borrowbook열렸다";
    }
    else
    {
        qDebug()<<"borrowbook닫혔다";
    }

    qint64 Count = 0;
    while(query.next())
    {
        const QString BookName = query.value(1).toString();
        QString BookWhen = query.value(3).toString();

        BookWhen.insert(4,QString("-"));
        BookWhen.insert(7,QString("-"));

        LableGroup[Count]->setText(BookName);
        LableBorrowWhen[Count]->setText(BookWhen);

        Count++;
    }

    query.prepare("select * from reservseat where name = :name");
    query.bindValue(":name",sstuName);
    query.exec();
    query.next();
    const QString reservSeat = query.value(1).toString();
    QString reservEnd = query.value(3).toString();

    ui->labelBorrowGive->setText(reservSeat);

    if(reservEnd.length() == 5)
    {
        reservEnd.insert(1,QString(":"));
        reservEnd.insert(4,QString(":"));
    }
    else
    {
        reservEnd.insert(2,QString(":"));
        reservEnd.insert(5,QString(":"));
    }
    ui->labelEndTime->setText(reservEnd);

    //지금까지 빌린책 3권 정리하기

    query.prepare("select * from historybook");
    query.exec();
    query.next();
    const QString book1 = query.value(1).toString();
    const QString book2 = query.value(2).toString();
    const QString book3 = query.value(3).toString();

    ui->bookName1->setText(book1);
    ui->bookName2->setText(book2);
    ui->BookName3->setText(book3);
}

myinfo::~myinfo()
{
    delete ui;
}

void myinfo::on_pushButton_clicked()
{
    Main_View *main = new Main_View();
    main->show();
    close();
}
