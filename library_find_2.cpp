#include "library_find_2.h"
#include "ui_library_find_2.h"
#include "mysql.h"

library_find_2::library_find_2(QString str) :
    ui(new Ui::library_find_2)
{
    ui->setupUi(this);

    BookName = str;
    qDebug()<<"BookName : " + BookName;

    //mysql 값 가져오기
    mysql my;
    QSqlQuery query;

    query.prepare("select name, source, author, location, separate,reserv from book where name = :txt");
    query.bindValue(":txt",BookName);

    if(query.exec())
    {
        qDebug()<<"Success";
    }
    else
    {
        qDebug()<<"failed";
    }

    query.next();

    name = query.value(0).toString();
    source = query.value(1).toString();
    author = query.value(2).toString();
    position = query.value(3).toString();
    separate = query.value(4).toString();
    reserv = query.value(5).toString();

    ui->bookName->setText("책 이름 : " + name);
    ui->bookSource->setText("책 출판사 : " + source);
    ui->bookAuthor->setText("책 작가 : " + author);
    ui->bookPosition->setText("책 위치 : " + position);
    ui->bookSeparate->setText("책 분류 : " + separate);
    ui->bookReserv->setText("책 예약여부 : " + reserv);
}

library_find_2::~library_find_2()
{
    delete ui;
}

void library_find_2::on_pushButton_clicked() //도서예매
{
    mysql my;
    QSqlQuery query;

    //만약 빌린책이 총 3권이면 안됀다.
    query.prepare("select stuname from myinfo");
    query.exec();
    query.next();
    const QString name = query.value(0).toString();

    query.prepare("select count(stuName) from borrowbook where stuName = :stuname");
    query.bindValue(":stuname",name);
    query.exec();
    query.next();
    const quint64 CountReservBook = query.value(0).toInt();
    const QString CountReservBookString = QString::number(CountReservBook);
    const QString CountCompare = QString::number(3);

    qDebug()<<"CountReservBook : "<<CountReservBook;
    qDebug()<<"CountReservBookString : "<<CountReservBookString;

    if(CountReservBookString == CountCompare)
    {
        QMessageBox msgBox;
        msgBox.setText("책 대출횟수 초과 : " + CountReservBookString);
        msgBox.exec();

        return ;
    }

    //현재 시간과 3주 후의 시간 클래스
    QString time_format = "yyyyMMdd";
    QDate currentTime = QDate::currentDate();

    const quint64 BackTime = currentTime.toString(time_format).toInt(); //현재 시간

    currentTime = currentTime.addDays(21);

    const quint64 time = currentTime.toString(time_format).toInt(); //3주후 시간

    if(reserv == "대출가능")
    {
        qDebug()<<"예매합니다";

        //myinfo안에 책이름이랑, 책반납날짜기입. ----- 1
        query.prepare("update myinfo set stuBook = :BookName, stuBookWhen = :stuBookWhen");

        query.bindValue(":BookName",BookName);
        query.bindValue(":stuBookWhen",time);

        if(query.exec())
        {
            qDebug()<<"myinfo에 넣는거 성공";
        }
        else
        {
            qDebug()<<"myinfo에 넣는거 실패";
            qDebug()<<query.lastError();
        }

        //myinfo에서 학생이름 가지고오기
        query.prepare("select * from myinfo");
        query.exec();
        query.next();
        QString stuName = query.value(0).toString();
        qDebug()<<"bookreserv에 넣을 학생이름 : "<<stuName;

        //bookreserv안에 학생이름, 책이름, 빌린날짜, 반납날짜기입 ----- 2
        query.prepare("insert into borrowbook(stuName, bookName, whenborrow, whengive)"
                      "values(?,?,?,?)");
        query.addBindValue(stuName);
        query.addBindValue(BookName);
        query.addBindValue(BackTime);
        query.addBindValue(time);

        if(query.exec())
        {
            qDebug()<<"Borrow book에 넣는거 성공";

            //bookDatabase에 favorite 단항연산시키기
            query.prepare("select favorite from book where name = :bookname");
            query.bindValue(":bookname",BookName);
            query.exec();
            query.next();

            qint64 bookFavorite = query.value(0).toInt();
            bookFavorite++;

            qDebug()<<"bookFavorite : "<<bookFavorite;

            query.prepare("update book set favorite = :favor where name = :bookname");
            query.bindValue(":favor",bookFavorite);
            query.bindValue(":bookname",BookName);
            if(query.exec())
            {
                qDebug()<<"인기순우 변동";
            }
            else
            {
                qDebug()<<"인기순위 안바뀜 에러";
                qDebug()<<query.lastError();
            }


            //BookDb에 해당 책의 이름으로 된걸 예매거기서 "예매불가"라고 변경한다.
            query.prepare("update book set reserv = :reserv where name = :name");
            query.bindValue(":reserv","대출불가");
            query.bindValue(":name",BookName);

            if(query.exec())
            {
                qDebug()<<"bookDB의 reserv 예매불가 성공";

                //historybook에다가 저장을 하는데
                //column을 하나 더 만들어서 1이면 hisbook1 --->
                QString QNum;

                query.prepare("select hisbookNum from histroybook");
                query.exec();
                query.next();
                QNum = query.value(0).toString();

                if(QNum == "1")
                {
                    qDebug()<<QNum;
                }
                else if(QNum == "2")
                {
                    qDebug()<<QNum;
                }
                else if(QNum == "3")
                {
                    qDebug()<<QNum;
                }
            }
            else
            {
                qDebug()<<"bookDB의 reserv 예매불가 실패";
                qDebug()<<query.lastError();
            }

            //예매한 내용의 대해서 historybook 디비에 넣는다
            //만약 3개의 값이 있을경우 처음부터하는 알고리즘
            QString Qnum;

            query.prepare("select hisnum from historybook where stuName = :name");
            query.bindValue(":name",name);
            query.exec();
            query.next();
            Qnum = query.value(0).toString();

            if(Qnum == "1")
            {
                qDebug()<<"Qnum : " + Qnum;

                query.prepare("update historybook set hisbook1 = ?,"
                              "hisnum = ?");
                query.addBindValue(BookName);
                query.addBindValue("2");

                query.exec();
            }
            else if(Qnum == "2")
            {
                qDebug()<<"Qnum : " + Qnum;

                query.prepare("update historybook set hisbook2 = ?,"
                              "hisnum = ?");
                query.addBindValue(BookName);
                query.addBindValue("3");

                query.exec();
            }
            else if(Qnum == "3")
            {
                qDebug()<<"Qnum : " + Qnum;

                query.prepare("update historybook set hisbook3 = ?,"
                              "hisnum = ?");
                query.addBindValue(BookName);
                query.addBindValue("1");

                query.exec();
            }

        }
        else
        {
            qDebug()<<"Borrow book에 넣는거 실패";
            qDebug()<<query.lastError();
        }



         QMessageBox::information(this,"Notice","예약완료 돼었습니다.");
         close();

    }
    else
    {
        QMessageBox::information(this,"Notice","해당 책은 예약불가능 합니다.");
        close();
    }
}

void library_find_2::on_pushButton_2_clicked() //종료하기
{
    close();
}
