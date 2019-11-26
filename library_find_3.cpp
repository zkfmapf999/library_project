#include "library_find_3.h"
#include "ui_library_find_3.h"

library_find_3::library_find_3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::library_find_3)
{
    ui->setupUi(this);

    mysql my;

    QSqlQuery query;
    //myinfo에서 가지고오기
    query.prepare("select stuName from myinfo");
    query.exec();
    query.next();
    QString stuName = query.value(0).toString();
    qDebug()<<"stuName : " + stuName;
    ui->labelStuName->setText(stuName);

    //borrowbook에서 myinfo.stuName가져오기
    query.prepare("select bookName, whenborrow, whengive from borrowbook where stuName = :stuname");
    query.bindValue(":stuname",stuName);
    if(query.exec())
    {
        qDebug()<<"borrowbook에서 where절 성공";
    }
    else
    {
        qDebug()<<"borrowbook에서 where절 실패";
    }

    //tableView 지정
    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery(query);
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("책 이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("빌린 날짜"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("반납 날짜"));

    ui->tableView->setModel(my.mModel);


}

library_find_3::~library_find_3()
{
    delete ui;
}

void library_find_3::on_pushButton_clicked()
{
    library_find *find = new library_find();
    find->show();
    close();
}

//tableview double click
void library_find_3::on_tableView_doubleClicked(const QModelIndex &index)
{
    cellText = index.data().toString();
    qDebug()<<"cellText : " + cellText;

    QMessageBox msgBox;
    msgBox.setText(cellText + " 반납하시겠습니까?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    int ret;
    ret = msgBox.exec();

    switch (ret)
    {
    case QMessageBox::Ok:
    {
        mysql my;
        QSqlQuery query;

        query.prepare("delete from borrowbook where bookName = :bookname");
        query.bindValue(":bookname",cellText);
        qDebug()<<"cellText : "<<cellText;
        if(query.exec())
        {
            qDebug()<<"borrowbook 제거성공";

            query.prepare("update book set reserv = :reservString where name = :bookname");
            query.bindValue(":reservString","대출가능");
            query.bindValue(":bookname",cellText);
            if(query.exec())
            {
                qDebug()<<"예매가능으로 바꿈";
            }
            else
            {
                qDebug()<<"예매가능으로 못바꿈";
                qDebug()<<query.lastError();
            }
        }
        else
        {
            qDebug()<<"borrowbook 제거실패";
        }

        library_find_3 *find = new library_find_3();
        find->show();
        close();
    }

    case QMessageBox::Cancel:
        break;
    }

}
