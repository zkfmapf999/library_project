#include "mysql.h"

mysql::mysql()
{
    this->database = QSqlDatabase::addDatabase("QMYSQL");
    this->database.setHostName("localhost");
    this->database.setUserName("root");
    this->database.setPassword("djaak8");
    this->database.setDatabaseName("library_practice");

    if(this->database.open())
    {
        qDebug()<<"database succeese";
    }
    else
    {
        qDebug()<<"database failed";
    }

    DatabaseOpenCheck("Mysql");
}

bool mysql::CheckLogin(QString num, QString privateNum)
{
    ///* 테스트를 위해서 주석처리
    QSqlQuery query;
    query.prepare("select name, num, privateNum from student where num = :num and privateNum = :private");

    query.bindValue(":num",num);
    query.bindValue(":private",privateNum);

    if(query.exec())
    {
        qDebug()<<"query success";
    }
    else
    {
        qDebug()<<"query failed";
        qDebug()<<query.lastError();
    }

    query.next();

    TestName = query.value(0).toString();
    TestNum = query.value(1).toString();
    TestPrivateNum = query.value(2).toString();

    if(TestNum == num && TestPrivateNum == privateNum)
    {
        qDebug()<<"login Success";

        //myinfo 에다가 넣기

        query.prepare("insert into myinfo(stuName, stuNum)"
                       "values(?, ?)");

        query.addBindValue(TestName);
        query.addBindValue(TestNum);

        if(query.exec())
        {
            qDebug()<<"myinfo에다가 넣는거 완료";

            //historybook에다가 넣기

            query.prepare("insert into historybook(stuName) values(:stuname)");
            query.bindValue(":stuname",TestName);
            if(query.exec())
            {
                qDebug()<<TestName + "저장성공 historybook";
            }
            else
            {
                qDebug()<<"historybook 저장실패";
            }
        }
        else
        {
            qDebug()<<"myinfo다가 넣는거 안됌";
            qDebug()<<query.lastError();
        }

        return true;

    }
    else
    {
        qDebug()<<"login failed";
        qDebug()<<query.lastError();

        return false;
    }
    //*/
}

void mysql::DatabaseOpenCheck(QString str)
{
    if(database.open()) qDebug()<<"database open\t" + str;
    else qDebug()<<"database Not Open\t" + str;
}

bool mysql::NumOverlapCheck(QString num)
{
    QSqlQuery query;
    query.exec("SELECT * FROM student");

    while(query.next())
    {
        QString Qnum = query.value(1).toString();
        qDebug()<<Qnum;

        if(num == Qnum)
        {
            //QMessageBox msg;
            //msg.setText(num + " overlap!!!");
            //msg.exec();

            qDebug()<<"매개변수 : "<<num;
            qDebug()<<"Qnum : "<<Qnum;

            return false;
        }
        else
        {
            //QMessageBox msg;
            //msg.setText(num + " correct number");
            //msg.exec();

            qDebug()<<"매개변수 : "<<num;
            qDebug()<<"Qnum : "<<Qnum;
        }
    }

    return true;
}

bool mysql::CampusOverlapCheck(QString Campus)
{
    QSqlQuery query;
    query.exec("SELECT * FROM student");

    while(query.next())
    {
        if(Campus != "1" && Campus !="2" && Campus != "3")
        {
            //QMessageBox msg;
            //msg.setText(Campus + " overlap!!!");
            //msg.exec();

            return false;
        }
        else
        {
            //QMessageBox msg;
            //msg.setText(Campus + " correct campus");
            //msg.exec();
        }
    }

    return true;
}

QString mysql::MessageBox(QString str)
{
    QMessageBox msgBox;
    msgBox.setText(str + " 좌석을 예약하시겠습니까?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    int ret;
    ret = msgBox.exec();

    //현재 시간 dd-yy-mm 이런형태로 출력
    QTime time = QTime::currentTime();
    const quint64 currentTime = time.toString("hhmmss").toInt(); //현재시간
    qDebug()<<"CurrentTime : "<<currentTime;

    //3시간 후를 코드로 추가시킨다.

    QTime time2 = QTime::currentTime().addSecs(10800);
    //time2 = time2.addSecs(10800); //3시간 추가
    const quint64 laterTime = time2.toString("hhmmss").toInt(); //3시간 후 시간

    qDebug()<<"laterTime : "<<laterTime;

    switch(ret)
    {
    case QMessageBox::Ok:
    {

        qDebug()<<"가자";

        QString StuName; //학생이름
        quint64 check; //just index

        // 1.학생이름 myinfo에서 가지고오기.

        QSqlQuery query;

        query.prepare("select * from myinfo");
        query.exec();
        query.next();
        StuName = query.value(0).toString();
        qDebug()<<"학생이름 : "<<StuName; //학생이름

        // 2. reservseat에 다가 학생이름 자리 언제 시작, 언제 끝 , 점유 하고 만약 점유 있을 시 에는 불가....

        query.prepare("select occupy from reservseat where reservLocation = :reserv and name = :Name");
        query.bindValue(":reserv",str);
        query.bindValue(":Name",StuName);

        if(query.exec())
        {
            qDebug()<<"성공";
        }
        else
        {
            qDebug()<<"실패";
            qDebug()<<query.lastError();
        }
        query.next();
        check = query.value(0).toInt();
        const QString checkString = QString::number(check);

        qDebug()<<"checkString : "<<checkString;
        qDebug()<<"reservseat occupy 있는지 검사 ";

        //이미 점유하고 있는 자리라면....
        query.prepare("select reservLocation from reservseat where reservLocation = :location");
        query.bindValue(":location",str);
        query.exec();
        query.next();
        const QString reservLocationString = query.value(0).toString();

        if(reservLocationString == str)
        {
            QMessageBox msgBox;
            msgBox.setText("이미 다른 사람이 예약한 좌석입니다.");
            msgBox.exec();

            const QString fail = "xxx";
            return fail;
        }

        //resevseat에 myinfo에서가져온 아이디가 있을경우, 즉 한자리를 점유하고있을경우 불가능....
        QSqlQuery query2;
        query2.prepare("select count(name) from reservseat where name = :Name");
        query2.bindValue(":Name",StuName);
        if(query2.exec())
        {
            qDebug()<<"카운트를 실행했음";
        }
        else
        {
            qDebug()<<"카운트 실행못함";
        }
        query2.next();
        quint64 CountNumberInt= query2.value(0).toInt();
        QString CountNumberString = QString::number(CountNumberInt);

        qDebug()<<"CountNumberInt : "<<CountNumberInt;
        qDebug()<<"CountNumberString : "<<CountNumberString;

        if(checkString == "1"  || CountNumberString== "1" )
        {
            //경고창을 하나 띄워야한다.;
            qDebug()<<"nono";

            const QString fail = "xxx";
            return fail;
        }
        query.prepare("insert into reservseat(name, reservLocation, whenStart, whenend)"
                      "values(:name, :location, :start, :end)");

        query.bindValue(":name",StuName);
        query.bindValue(":location",str);
        query.bindValue(":start",currentTime);
        query.bindValue(":end",laterTime);

        if(query.exec())
        {
            qDebug()<<"reservseat 저장성공";
        }
        else
        {
            qDebug()<<"reservseat 저장실패";
            qDebug()<<query.lastError();
        }

        // 3.자리 : str
        //myinfo에다가 자리장소, 자리언제끝 저장
        //자리 지정시 해당 label이 바뀐다. 그리고 label에 끝나느 시간 저장

        query.prepare("update myinfo set stuSeatNum = :seatnum,"
                      "stuSeatWhen = :seatwhen");

        query.bindValue(":seatnum",str);
        query.bindValue("seatwhen:",laterTime);

        if(query.exec())
        {
            qDebug()<<"myinfo 에 저장이 되었다";
        }
        else
        {
            qDebug()<<"myinfo에 저장안됌 실패";
        }

        QString Later = QString::number(laterTime);
        qDebug()<<"Later : "<<Later;
        return Later;
    }

    case QMessageBox::Cancel:
    {

        qDebug()<<"취소";
        return "xxx";
    }
    }
}

void mysql::SeeBoardDeleteText(QString orderText)
{
    //myinfo에서 가지고오기
    QSqlQuery query;

    query.prepare("select stuName from myinfo");
    query.exec();
    query.next();

    const QString delName = query.value(0).toString();
    qDebug()<<"delName : "<<delName;

        QMessageBox msgBox;
        msgBox.setText(delName + " 의 글을 삭제하시겠습니까?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        int ret = msgBox.exec();

    if(ret == QMessageBox::Yes)
    {
        //일단 seeboard orderText에 stuName과 delName이 같다면 지운다.

        query.prepare("select stuName from seeboard where orderText = :order");
        query.bindValue(":order",orderText);
        query.exec();
        query.next();

        const QString delTestName = query.value(0).toString();
        qDebug()<<"delTestName : "<<delTestName;

        if(delName == delTestName)
        {
            query.prepare("delete from seeboard where stuName = :stuname");
            query.bindValue(":stuname",delName);
            if(query.exec())
            {
                //myinfo에 seeNum을 0으로 바꿔야한다.
                query.prepare("update myinfo set seeNum = :seeNum");
                query.bindValue(":seeNum","0");
                query.exec();

                qDebug()<<"지웠다.";
            }
            else
            {
                qDebug()<<"지웠다nono";
            }
        }
        else if(delName == "admin")
        {
            query.prepare("delete from seeboard where stuName = :stuname");
            query.bindValue(":stuname",delTestName);
            if(query.exec())
            {
                //myinfo에 seeNum을 0으로 바꿔야한다.
                query.prepare("update myinfo set seeNum = :seeNum");
                query.bindValue(":seeNum","0");
                query.exec();

                qDebug()<<"지웠다.";
            }
            else
            {
                qDebug()<<"지웠다nono";
            }
        }
        else
        {
            //틀리다고 메시지를 전해주고싶어용
            QMessageBox msgBox;
            msgBox.setText("해당 아이디와 다른글은 지울 수 없습니다.");
            msgBox.exec();
            qDebug()<<"틀림";
        }
    }
    else if(ret == QMessageBox::No)
    {

        qDebug()<<"취소";
        return ;
    }
}

QString mysql::CheckCount()
{
    //한개 자리 점유시 못한다.
}

void mysql::Main_Cancle()
{
    QSqlQuery query;

    query.exec("delete from myinfo");
}





mysql::~mysql()
{
    database.close();
}
