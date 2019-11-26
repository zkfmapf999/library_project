#ifndef MYSQL_H
#define MYSQL_H

#include "header.h"
#include "secound_floor.h"
#include "thrid_floor.h"


class mysql
{
public:
    mysql();
    ~mysql();

    /*                       sign_view                         */
    bool CheckLogin(QString num, QString privateNum); //로그인







    /*                       join_view                         */
    //openChchek
    void DatabaseOpenCheck(QString str);

    //학번 중복확인
    bool NumOverlapCheck(QString num);

    //캠퍼스 중복확인
    bool CampusOverlapCheck(QString Capmus);


    /*                      main_view                          */
    void Main_Cancle();

    /*                      secound_floor, third_floor              */
    QString MessageBox(QString str);
    QString CheckCount();

    void SeeBoardDeleteText(QString orderText); //deleteNumber;


public:
    QSqlDatabase database;

    QString TestName; //myinfo에 저장될 학생이름
    QString TestNum; //myinfo에 저장될 학생학번
    QString TestPrivateNum; //그냥 쩌리

    /*
    QTime time; //현재시간 date
    QString currentTime; //현재시간 String
    QTime time2; //현재시간 3시간 후
    QString laterTime; //현재시간 3시간 후 String
    */

public:
    QSqlQueryModel *mModel;


};

#endif // MYSQL_H
