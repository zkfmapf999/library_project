#ifndef SEEBOARD_H
#define SEEBOARD_H

#include <QWidget>
#include <QDebug>
#include "main_view.h"
#include "seeboardwrite.h"
#include "mysql.h"
#include "header.h"
#include "seeplus.h"

namespace Ui {
class seeboard;
}

class seeboard : public QWidget
{
    Q_OBJECT

public:
    explicit seeboard(QWidget *parent = 0);
    ~seeboard();

private slots:
    void on_pushButton_16_clicked();


    void on_pushButton_15_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    //void on_pushButton_17_clicked();

    void on_del_1_clicked();

    void on_del_2_clicked();

    void on_del_3_clicked();

    void on_del_4_clicked();

    void on_del_5_clicked();

    void on_del_6_clicked();

private:
    Ui::seeboard *ui;

    //순서정하기
    int seeText[6] = {1,1,1,1,1,1};
    //int count = 0;

    //이름이랑 텍스트
    QString stuName;
    QString stuText;
    QString goodPoint;
    QString badPoint;
    QString orderText;

    //확대할때 전해줄 매개변수
    QString plusName;
    QString plustxt;
    QString plusddd;

};

#endif // SEEBOARD_H
