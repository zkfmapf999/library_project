#include "secound_floor.h"
#include "ui_secound_floor.h"

secound_Floor::secound_Floor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secound_Floor)
{
    ui->setupUi(this);

    //2200,1000 하면 옆에 한번에 확인할 수 있는 차트 있음 아직 미완성
    setFixedSize(1860,1000);

    const qint64 MAX_NUMBER = 164;

    QPushButton *btnGroup[MAX_NUMBER] = {ui->btn1, ui->btn2, ui->btn3,ui->btn4,ui->btn5,ui->btn6,ui->btn7,
                              ui->btn8, ui->btn9, ui->btn10,ui->btn11,ui->btn12,ui->btn13,ui->btn14,
                              ui->btn15, ui->btn16, ui->btn17,ui->btn18,ui->btn19,ui->btn20,ui->btn21,
                              ui->btn22, ui->btn23, ui->btn24,ui->btn25,ui->btn26,ui->btn27,ui->btn28,
                              ui->btn29, ui->btn30, ui->btn31,ui->btn32,ui->btn33,ui->btn34,ui->btn35,
                              ui->btn36, ui->btn37, ui->btn38,ui->btn39,ui->btn40,ui->btn41,ui->btn42,
                              ui->btn43, ui->btn44, ui->btn45,ui->btn46,ui->btn47,ui->btn48,ui->btn49,
                              ui->btn50, ui->btn51, ui->btn52,ui->btn53,ui->btn54,ui->btn55,ui->btn56,
                              ui->btn57, ui->btn58, ui->btn59,ui->btn60,ui->btn61,ui->btn62,ui->btn63,
                              ui->btn64, ui->btn65, ui->btn66,ui->btn67,ui->btn68,ui->btn69,ui->btn70,
                              ui->btn71, ui->btn72, ui->btn73,ui->btn74,ui->btn75,ui->btn76,ui->btn77,ui->btn78,ui->btn79,ui->btn80,
                              ui->btn81, ui->btn82, ui->btn83,ui->btn84,ui->btn85,ui->btn86,ui->btn87,ui->btn88,ui->btn89,ui->btn90,
                              ui->btn91, ui->btn92, ui->btn93,ui->btn94,ui->btn95,ui->btn96,ui->btn97,ui->btn98,ui->btn99,ui->btn100,
                              ui->btn101, ui->btn102, ui->btn103,ui->btn104,ui->btn105,ui->btn106,ui->btn107,ui->btn108,ui->btn109,ui->btn110,
                              ui->btn111, ui->btn112, ui->btn113,ui->btn114,ui->btn115,ui->btn116,ui->btn117,ui->btn118,ui->btn119,ui->btn120,
                              ui->btn121, ui->btn122, ui->btn123,ui->btn124,ui->btn125,ui->btn126,ui->btn127,ui->btn128,ui->btn129,ui->btn130,
                              ui->btn131, ui->btn132, ui->btn133,ui->btn134,ui->btn135,ui->btn136,ui->btn137,ui->btn138,ui->btn139,ui->btn140,
                              ui->btn141, ui->btn142, ui->btn143,ui->btn144,ui->btn145,ui->btn146,ui->btn147,ui->btn148,ui->btn149,ui->btn150,
                              ui->btn151, ui->btn152, ui->btn153,ui->btn154,ui->btn155,ui->btn156,ui->btn157,ui->btn158,ui->btn159,ui->btn160,
                              ui->btn161,ui->btn162,ui->btn163};

    QLabel *timeGroup[MAX_NUMBER] = {ui->time1, ui->time2, ui->time3,ui->time4,ui->time5,ui->time6,ui->time7,
                           ui->time8, ui->time9, ui->time10,ui->time11,ui->time12,ui->time13,ui->time14,
                           ui->time15, ui->time16, ui->time17,ui->time18,ui->time19,ui->time20,ui->time21,
                           ui->time22, ui->time23, ui->time24,ui->time25,ui->time26,ui->time27,ui->time28,
                           ui->time29, ui->time30, ui->time31,ui->time32,ui->time33,ui->time34,ui->time35,
                           ui->time36, ui->time37, ui->time38,ui->time39,ui->time40,ui->time41,ui->time42,
                           ui->time43, ui->time44, ui->time45,ui->time46,ui->time47,ui->time48,ui->time49,
                           ui->time50, ui->time51, ui->time52,ui->time53,ui->time54,ui->time55,ui->time56,
                           ui->time57, ui->time58, ui->time59,ui->time60,ui->time61,ui->time62,ui->time63,
                           ui->time64, ui->time65, ui->time66,ui->time67,ui->time68,ui->time69,ui->time70,
                           ui->time71, ui->time72, ui->time73,ui->time74,ui->time75,ui->time76,ui->time77,ui->time78,ui->time79,ui->time80,
                           ui->time81, ui->time82, ui->time83,ui->time84,ui->time85,ui->time86,ui->time87,ui->time88,ui->time89,ui->time90,
                           ui->time91, ui->time92, ui->time93,ui->time94,ui->time95,ui->time96,ui->time97,ui->time98,ui->time99,ui->time100,
                           ui->time101, ui->time102, ui->time103,ui->time104,ui->time105,ui->time106,ui->time107,ui->time108,ui->time109,ui->time110,
                           ui->time111, ui->time112, ui->time113,ui->time114,ui->time115,ui->time116,ui->time117,ui->time118,ui->time119,ui->time120,
                           ui->time121, ui->time122, ui->time123,ui->time124,ui->time125,ui->time126,ui->time127,ui->time128,ui->time129,ui->time130,
                           ui->time131, ui->time132, ui->time133,ui->time134,ui->time135,ui->time136,ui->time137,ui->time138,ui->time139,ui->time140,
                           ui->time141, ui->time142, ui->time143,ui->time144,ui->time145,ui->time146,ui->time147,ui->time148,ui->time149,ui->time150,
                           ui->time151, ui->time152, ui->time153,ui->time154,ui->time155,ui->time156,ui->time157,ui->time158,ui->time159,ui->time160,
                           ui->time161,ui->time162,ui->time163};


    int COUNT_NUMBER = 0;

    mysql my;
    QSqlQuery query;

    qDebug()<<"11111";

    //stylesheet
    for(quint64 i = 0; i<163; i++)
    {
        //qDebug()<<"error Number : "<<i;

        btnGroup[i]->setStyleSheet("background-color : rgb(170, 255, 127);"
                                   "font-weight : bold;");

        btnGroup[i]->setText("이용가능");

        timeGroup[i]->setText(" ");
    }

    qDebug()<<"11111";


    qDebug()<<"2층 시작";

    query.exec("select reservLocation,whenend from reservseat");

    while(query.next()) //database에서 query내에 있는것 색깔바꾸기...
    {
        const QString numberSeat = query.value(0).toString();
        QString basicTime = query.value(1).toString();

        if(basicTime.length() == 5)
        {
            basicTime.insert(1,":");
            basicTime.insert(4,":");
        }
        else
        {
            basicTime.insert(2,":");
            basicTime.insert(5,":");
        }
        qDebug()<<"numberSeat : "<<numberSeat;
        for(int i=0;i<163; i++)
        {
            if(btnGroup[i]->objectName() == numberSeat)
            {
                btnGroup[i]->setStyleSheet("background-color : red; font-weight : bold;");
                btnGroup[i]->setText("이용중");
                timeGroup[i]->setStyleSheet("color : red;");
                timeGroup[i]->setText(basicTime);
            }
        }
    };

    // 옆에 자리좌석 있는거 체크하는 확장성
    query.prepare("select name,reservLocation,whenend from reservseat");
    if(query.exec())
    {
        qDebug()<<"좌석번호 찍기";
    }
    else
    {
        qDebug()<<"좌석번호찍기 실패";
        qDebug()<<query.lastError();
    }
    query.next();

    my.mModel = new QSqlQueryModel;
    my.mModel->setQuery(query);
    my.mModel->setHeaderData(0,Qt::Horizontal,tr("이름"));
    my.mModel->setHeaderData(1,Qt::Horizontal,tr("좌석번호"));
    my.mModel->setHeaderData(2,Qt::Horizontal,tr("끝나는시간"));

    ui->tableView->setModel(my.mModel);

    QDateTime QDT = QDateTime::currentDateTime();
    QDateTimeEdit* QDTE = new QDateTimeEdit(QDT,this);
    QDTE->setDisplayFormat("yyyy년MM월dd일 ap hh:mm:ss-zzz");
    QDTE->setGeometry(1380,18,260,28);
    QDTE->setStyleSheet("font : 15px; font-weight : bold;");

    ui->dateTimeEdit->hide();

}

secound_Floor::~secound_Floor()
{
    delete ui;
}

void secound_Floor::on_pushButton_clicked()
{
    mysql my;
    library_seat *seat = new library_seat();
    seat->show();
    close();
}


void secound_Floor::on_btn1_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn1->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn1->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn1->setText("이용중");
        ui->time1->setStyleSheet("color : red;");
        ui->time1->setText(timetext);
    }
}


void secound_Floor::on_btn2_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn2->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn2->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn2->setText("이용중");
        ui->time2->setStyleSheet("color : red;");
        ui->time2->setText(timetext);
    }
}

void secound_Floor::on_btn3_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn3->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn3->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn3->setText("이용중");
        ui->time3->setStyleSheet("color : red;");
        ui->time3->setText(timetext);
    }
}

void secound_Floor::on_btn4_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn4->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn4->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn4->setText("이용중");
        ui->time4->setStyleSheet("color : red;");
        ui->time4->setText(timetext);
    }
}

void secound_Floor::on_btn5_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn5->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn5->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn5->setText("이용중");
        ui->time5->setStyleSheet("color : red;");
        ui->time5->setText(timetext);
    }
}

void secound_Floor::on_btn6_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn6->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn6->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn6->setText("이용중");
        ui->time6->setStyleSheet("color : red;");
        ui->time6->setText(timetext);
    }
}

void secound_Floor::on_btn7_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn7->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn7->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn7->setText("이용중");
        ui->time7->setStyleSheet("color : red;");
        ui->time7->setText(timetext);
    }
}

void secound_Floor::on_btn8_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn8->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn8->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn8->setText("이용중");
        ui->time8->setStyleSheet("color : red;");
        ui->time8->setText(timetext);
    }
}

void secound_Floor::on_btn9_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn9->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn9->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn9->setText("이용중");
        ui->time9->setStyleSheet("color : red;");
        ui->time9->setText(timetext);
    }
}

void secound_Floor::on_btn10_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn10->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn10->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn10->setText("이용중");
        ui->time10->setStyleSheet("color : red;");
        ui->time10->setText(timetext);
    }
}
//
void secound_Floor::on_btn11_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn11->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn11->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn11->setText("이용중");
        ui->time11->setStyleSheet("color : red;");
        ui->time11->setText(timetext);
    }
}


void secound_Floor::on_btn12_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn12->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn12->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn12->setText("이용중");
        ui->time12->setStyleSheet("color : red;");
        ui->time12->setText(timetext);
    }
}

void secound_Floor::on_btn13_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn13->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn13->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn13->setText("이용중");
        ui->time13->setStyleSheet("color : red;");
        ui->time13->setText(timetext);
    }
}

void secound_Floor::on_btn14_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn4->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn14->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn14->setText("이용중");
        ui->time14->setStyleSheet("color : red;");
        ui->time14->setText(timetext);
    }
}

void secound_Floor::on_btn15_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn5->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn15->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn15->setText("이용중");
        ui->time15->setStyleSheet("color : red;");
        ui->time15->setText(timetext);
    }
}

void secound_Floor::on_btn16_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn6->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn16->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn16->setText("이용중");
        ui->time16->setStyleSheet("color : red;");
        ui->time16->setText(timetext);
    }
}

void secound_Floor::on_btn17_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn7->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn17->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn17->setText("이용중");
        ui->time17->setStyleSheet("color : red;");
        ui->time17->setText(timetext);
    }
}

void secound_Floor::on_btn18_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn8->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn18->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn18->setText("이용중");
        ui->time18->setStyleSheet("color : red;");
        ui->time18->setText(timetext);
    }
}

void secound_Floor::on_btn19_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn9->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn19->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn19->setText("이용중");
        ui->time19->setStyleSheet("color : red;");
        ui->time19->setText(timetext);
    }
}

void secound_Floor::on_btn20_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn20->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn20->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn20->setText("이용중");
        ui->time20->setStyleSheet("color : red;");
        ui->time20->setText(timetext);
    }
}
//
void secound_Floor::on_btn21_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn21->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn21->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn21->setText("이용중");
        ui->time21->setStyleSheet("color : red;");
        ui->time21->setText(timetext);
    }
}


void secound_Floor::on_btn22_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn22->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn22->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn22->setText("이용중");
        ui->time22->setStyleSheet("color : red;");
        ui->time22->setText(timetext);
    }
}

void secound_Floor::on_btn23_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn23->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn23->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn23->setText("이용중");
        ui->time23->setStyleSheet("color : red;");
        ui->time23->setText(timetext);
    }
}

void secound_Floor::on_btn24_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn24->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn24->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn24->setText("이용중");
        ui->time24->setStyleSheet("color : red;");
        ui->time24->setText(timetext);
    }
}

void secound_Floor::on_btn25_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn25->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn25->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn25->setText("이용중");
        ui->time25->setStyleSheet("color : red;");
        ui->time25->setText(timetext);
    }
}

void secound_Floor::on_btn26_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn26->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn26->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn26->setText("이용중");
        ui->time26->setStyleSheet("color : red;");
        ui->time26->setText(timetext);
    }
}

void secound_Floor::on_btn27_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn27->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn27->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn27->setText("이용중");
        ui->time27->setStyleSheet("color : red;");
        ui->time27->setText(timetext);
    }
}

void secound_Floor::on_btn28_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn28->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn28->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn28->setText("이용중");
        ui->time28->setStyleSheet("color : red;");
        ui->time28->setText(timetext);
    }
}

void secound_Floor::on_btn29_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn29->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn29->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn29->setText("이용중");
        ui->time29->setStyleSheet("color : red;");
        ui->time29->setText(timetext);
    }
}

void secound_Floor::on_btn30_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn30->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn30->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn30->setText("이용중");
        ui->time30->setStyleSheet("color : red;");
        ui->time30->setText(timetext);
    }
}
//
void secound_Floor::on_btn31_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn31->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn31->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn31->setText("이용중");
        ui->time31->setStyleSheet("color : red;");
        ui->time31->setText(timetext);
    }
}


void secound_Floor::on_btn32_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn32->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn32->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn32->setText("이용중");
        ui->time32->setStyleSheet("color : red;");
        ui->time32->setText(timetext);
    }
}

void secound_Floor::on_btn33_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn33->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn33->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn33->setText("이용중");
        ui->time33->setStyleSheet("color : red;");
        ui->time33->setText(timetext);
    }
}

void secound_Floor::on_btn34_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn34->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn34->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn34->setText("이용중");
        ui->time34->setStyleSheet("color : red;");
        ui->time34->setText(timetext);
    }
}

void secound_Floor::on_btn35_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn35->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn35->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn35->setText("이용중");
        ui->time35->setStyleSheet("color : red;");
        ui->time35->setText(timetext);
    }
}

void secound_Floor::on_btn36_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn36->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn36->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn36->setText("이용중");
        ui->time36->setStyleSheet("color : red;");
        ui->time36->setText(timetext);
    }
}

void secound_Floor::on_btn37_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn37->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn37->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn37->setText("이용중");
        ui->time37->setStyleSheet("color : red;");
        ui->time37->setText(timetext);
    }
}

void secound_Floor::on_btn38_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn38->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn38->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn38->setText("이용중");
        ui->time38->setStyleSheet("color : red;");
        ui->time38->setText(timetext);
    }
}

void secound_Floor::on_btn39_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn39->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn39->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn39->setText("이용중");
        ui->time39->setStyleSheet("color : red;");
        ui->time39->setText(timetext);
    }
}

void secound_Floor::on_btn40_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn40->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn40->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn40->setText("이용중");
        ui->time40->setStyleSheet("color : red;");
        ui->time40->setText(timetext);
    }
}
//
void secound_Floor::on_btn41_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn41->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn41->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn41->setText("이용중");
        ui->time41->setStyleSheet("color : red;");
        ui->time41->setText(timetext);
    }
}


void secound_Floor::on_btn42_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn42->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn42->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn42->setText("이용중");
        ui->time42->setStyleSheet("color : red;");
        ui->time42->setText(timetext);
    }
}

void secound_Floor::on_btn43_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn43->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn43->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn43->setText("이용중");
        ui->time43->setStyleSheet("color : red;");
        ui->time43->setText(timetext);
    }
}

void secound_Floor::on_btn44_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn44->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn44->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn44->setText("이용중");
        ui->time44->setStyleSheet("color : red;");
        ui->time44->setText(timetext);
    }
}

void secound_Floor::on_btn45_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn45->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn45->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn45->setText("이용중");
        ui->time45->setStyleSheet("color : red;");
        ui->time45->setText(timetext);
    }
}

void secound_Floor::on_btn46_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn46->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn46->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn46->setText("이용중");
        ui->time46->setStyleSheet("color : red;");
        ui->time46->setText(timetext);
    }
}

void secound_Floor::on_btn47_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn47->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn47->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn47->setText("이용중");
        ui->time47->setStyleSheet("color : red;");
        ui->time47->setText(timetext);
    }
}

void secound_Floor::on_btn48_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn48->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn48->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn48->setText("이용중");
        ui->time48->setStyleSheet("color : red;");
        ui->time48->setText(timetext);
    }
}

void secound_Floor::on_btn49_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn49->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn49->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn49->setText("이용중");
        ui->time49->setStyleSheet("color : red;");
        ui->time49->setText(timetext);
    }
}

void secound_Floor::on_btn50_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn50->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn50->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn50->setText("이용중");
        ui->time50->setStyleSheet("color : red;");
        ui->time50->setText(timetext);
    }
}
//
void secound_Floor::on_btn51_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn51->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn51->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn51->setText("이용중");
        ui->time51->setStyleSheet("color : red;");
        ui->time51->setText(timetext);
    }
}


void secound_Floor::on_btn52_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn52->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn52->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn52->setText("이용중");
        ui->time52->setStyleSheet("color : red;");
        ui->time52->setText(timetext);
    }
}

void secound_Floor::on_btn53_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn53->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn53->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn53->setText("이용중");
        ui->time53->setStyleSheet("color : red;");
        ui->time53->setText(timetext);
    }
}

void secound_Floor::on_btn54_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn54->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn54->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn54->setText("이용중");
        ui->time54->setStyleSheet("color : red;");
        ui->time54->setText(timetext);
    }
}

void secound_Floor::on_btn55_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn55->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn55->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn55->setText("이용중");
        ui->time55->setStyleSheet("color : red;");
        ui->time55->setText(timetext);
    }
}

void secound_Floor::on_btn56_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn56->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn56->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn56->setText("이용중");
        ui->time56->setStyleSheet("color : red;");
        ui->time56->setText(timetext);
    }
}

void secound_Floor::on_btn57_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn57->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn57->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn57->setText("이용중");
        ui->time57->setStyleSheet("color : red;");
        ui->time57->setText(timetext);
    }
}

void secound_Floor::on_btn58_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn58->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn58->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn58->setText("이용중");
        ui->time58->setStyleSheet("color : red;");
        ui->time58->setText(timetext);
    }
}

void secound_Floor::on_btn59_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn59->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn59->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn59->setText("이용중");
        ui->time59->setStyleSheet("color : red;");
        ui->time59->setText(timetext);
    }
}

void secound_Floor::on_btn60_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn60->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn60->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn60->setText("이용중");
        ui->time60->setStyleSheet("color : red;");
        ui->time60->setText(timetext);
    }
}
//
void secound_Floor::on_btn61_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn61->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn61->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn61->setText("이용중");
        ui->time61->setStyleSheet("color : red;");
        ui->time61->setText(timetext);
    }
}


void secound_Floor::on_btn62_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn62->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn62->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn62->setText("이용중");
        ui->time62->setStyleSheet("color : red;");
        ui->time62->setText(timetext);
    }
}

void secound_Floor::on_btn63_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn63->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn63->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn63->setText("이용중");
        ui->time63->setStyleSheet("color : red;");
        ui->time63->setText(timetext);
    }
}

void secound_Floor::on_btn64_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn64->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn64->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn64->setText("이용중");
        ui->time64->setStyleSheet("color : red;");
        ui->time64->setText(timetext);
    }
}

void secound_Floor::on_btn65_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn65->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn65->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn65->setText("이용중");
        ui->time65->setStyleSheet("color : red;");
        ui->time65->setText(timetext);
    }
}

void secound_Floor::on_btn66_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn66->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn66->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn66->setText("이용중");
        ui->time66->setStyleSheet("color : red;");
        ui->time66->setText(timetext);
    }
}

void secound_Floor::on_btn67_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn67->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn67->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn67->setText("이용중");
        ui->time67->setStyleSheet("color : red;");
        ui->time67->setText(timetext);
    }
}

void secound_Floor::on_btn68_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn68->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn68->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn68->setText("이용중");
        ui->time68->setStyleSheet("color : red;");
        ui->time68->setText(timetext);
    }
}

void secound_Floor::on_btn69_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn69->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn69->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn69->setText("이용중");
        ui->time69->setStyleSheet("color : red;");
        ui->time69->setText(timetext);
    }
}

void secound_Floor::on_btn70_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn70->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn70->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn70->setText("이용중");
        ui->time70->setStyleSheet("color : red;");
        ui->time70->setText(timetext);
    }
}
//
void secound_Floor::on_btn71_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn71->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn71->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn71->setText("이용중");
        ui->time71->setStyleSheet("color : red;");
        ui->time71->setText(timetext);
    }
}


void secound_Floor::on_btn72_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn72->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn72->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn72->setText("이용중");
        ui->time72->setStyleSheet("color : red;");
        ui->time72->setText(timetext);
    }
}

void secound_Floor::on_btn73_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn73->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn73->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn73->setText("이용중");
        ui->time73->setStyleSheet("color : red;");
        ui->time73->setText(timetext);
    }
}

void secound_Floor::on_btn74_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn74->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn74->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn74->setText("이용중");
        ui->time74->setStyleSheet("color : red;");
        ui->time74->setText(timetext);
    }
}

void secound_Floor::on_btn75_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn75->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn75->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn75->setText("이용중");
        ui->time75->setStyleSheet("color : red;");
        ui->time75->setText(timetext);
    }
}

void secound_Floor::on_btn76_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn76->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn76->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn76->setText("이용중");
        ui->time76->setStyleSheet("color : red;");
        ui->time76->setText(timetext);
    }
}

void secound_Floor::on_btn77_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn77->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn77->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn77->setText("이용중");
        ui->time77->setStyleSheet("color : red;");
        ui->time77->setText(timetext);
    }
}

void secound_Floor::on_btn78_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn78->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn78->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn78->setText("이용중");
        ui->time78->setStyleSheet("color : red;");
        ui->time78->setText(timetext);
    }
}

void secound_Floor::on_btn79_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn79->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn79->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn79->setText("이용중");
        ui->time79->setStyleSheet("color : red;");
        ui->time79->setText(timetext);
    }
}

void secound_Floor::on_btn80_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn80->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn80->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn80->setText("이용중");
        ui->time80->setStyleSheet("color : red;");
        ui->time80->setText(timetext);
    }
}
//
void secound_Floor::on_btn81_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn81->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn81->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn81->setText("이용중");
        ui->time81->setStyleSheet("color : red;");
        ui->time81->setText(timetext);
    }
}


void secound_Floor::on_btn82_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn82->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn82->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn82->setText("이용중");
        ui->time82->setStyleSheet("color : red;");
        ui->time82->setText(timetext);
    }
}

void secound_Floor::on_btn83_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn83->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn83->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn83->setText("이용중");
        ui->time83->setStyleSheet("color : red;");
        ui->time83->setText(timetext);
    }
}

void secound_Floor::on_btn84_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn84->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn84->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn84->setText("이용중");
        ui->time84->setStyleSheet("color : red;");
        ui->time84->setText(timetext);
    }
}

void secound_Floor::on_btn85_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn85->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn85->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn85->setText("이용중");
        ui->time85->setStyleSheet("color : red;");
        ui->time85->setText(timetext);
    }
}

void secound_Floor::on_btn86_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn86->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn86->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn86->setText("이용중");
        ui->time86->setStyleSheet("color : red;");
        ui->time86->setText(timetext);
    }
}

void secound_Floor::on_btn87_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn87->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn87->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn87->setText("이용중");
        ui->time87->setStyleSheet("color : red;");
        ui->time87->setText(timetext);
    }
}

void secound_Floor::on_btn88_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn88->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn88->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn88->setText("이용중");
        ui->time88->setStyleSheet("color : red;");
        ui->time88->setText(timetext);
    }
}

void secound_Floor::on_btn89_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn89->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn89->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn89->setText("이용중");
        ui->time89->setStyleSheet("color : red;");
        ui->time89->setText(timetext);
    }
}

void secound_Floor::on_btn90_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn90->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn90->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn90->setText("이용중");
        ui->time90->setStyleSheet("color : red;");
        ui->time90->setText(timetext);
    }
}
//
void secound_Floor::on_btn91_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn91->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn91->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn91->setText("이용중");
        ui->time91->setStyleSheet("color : red;");
        ui->time91->setText(timetext);
    }
}


void secound_Floor::on_btn92_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn92->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn92->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn92->setText("이용중");
        ui->time92->setStyleSheet("color : red;");
        ui->time92->setText(timetext);
    }
}

void secound_Floor::on_btn93_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn93->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn93->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn93->setText("이용중");
        ui->time93->setStyleSheet("color : red;");
        ui->time93->setText(timetext);
    }
}

void secound_Floor::on_btn94_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn94->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn94->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn94->setText("이용중");
        ui->time94->setStyleSheet("color : red;");
        ui->time94->setText(timetext);
    }
}

void secound_Floor::on_btn95_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn95->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn95->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn95->setText("이용중");
        ui->time95->setStyleSheet("color : red;");
        ui->time95->setText(timetext);
    }
}

void secound_Floor::on_btn96_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn96->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn96->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn96->setText("이용중");
        ui->time96->setStyleSheet("color : red;");
        ui->time96->setText(timetext);
    }
}

void secound_Floor::on_btn97_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn97->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn97->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn97->setText("이용중");
        ui->time97->setStyleSheet("color : red;");
        ui->time97->setText(timetext);
    }
}

void secound_Floor::on_btn98_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn98->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn98->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn98->setText("이용중");
        ui->time98->setStyleSheet("color : red;");
        ui->time98->setText(timetext);
    }
}

void secound_Floor::on_btn99_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn99->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn99->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn99->setText("이용중");
        ui->time99->setStyleSheet("color : red;");
        ui->time99->setText(timetext);
    }
}

void secound_Floor::on_btn100_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn100->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn100->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn100->setText("이용중");
        ui->time100->setStyleSheet("color : red;");
        ui->time100->setText(timetext);
    }
}
//
void secound_Floor::on_btn101_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn101->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn101->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn101->setText("이용중");
        ui->time101->setStyleSheet("color : red;");
        ui->time101->setText(timetext);
    }
}


void secound_Floor::on_btn102_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn102->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn102->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn102->setText("이용중");
        ui->time102->setStyleSheet("color : red;");
        ui->time102->setText(timetext);
    }
}

void secound_Floor::on_btn103_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn103->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn103->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn103->setText("이용중");
        ui->time103->setStyleSheet("color : red;");
        ui->time103->setText(timetext);
    }
}

void secound_Floor::on_btn104_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn104->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn104->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn104->setText("이용중");
        ui->time104->setStyleSheet("color : red;");
        ui->time104->setText(timetext);
    }
}

void secound_Floor::on_btn105_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn105->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn105->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn105->setText("이용중");
        ui->time105->setStyleSheet("color : red;");
        ui->time105->setText(timetext);
    }
}

void secound_Floor::on_btn106_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn106->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn106->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn106->setText("이용중");
        ui->time106->setStyleSheet("color : red;");
        ui->time106->setText(timetext);
    }
}

void secound_Floor::on_btn107_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn107->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn107->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn107->setText("이용중");
        ui->time107->setStyleSheet("color : red;");
        ui->time107->setText(timetext);
    }
}

void secound_Floor::on_btn108_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn108->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn108->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn108->setText("이용중");
        ui->time108->setStyleSheet("color : red;");
        ui->time108->setText(timetext);
    }
}

void secound_Floor::on_btn109_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn109->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn109->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn109->setText("이용중");
        ui->time109->setStyleSheet("color : red;");
        ui->time109->setText(timetext);
    }
}

void secound_Floor::on_btn110_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn110->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn110->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn110->setText("이용중");
        ui->time110->setStyleSheet("color : red;");
        ui->time110->setText(timetext);
    }
}
//
void secound_Floor::on_btn111_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn111->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn111->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn111->setText("이용중");
        ui->time111->setStyleSheet("color : red;");
        ui->time111->setText(timetext);
    }
}


void secound_Floor::on_btn112_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn112->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn112->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn112->setText("이용중");
        ui->time112->setStyleSheet("color : red;");
        ui->time112->setText(timetext);
    }
}

void secound_Floor::on_btn113_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn113->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn113->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn113->setText("이용중");
        ui->time113->setStyleSheet("color : red;");
        ui->time113->setText(timetext);
    }
}

void secound_Floor::on_btn114_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn114->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn114->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn114->setText("이용중");
        ui->time114->setStyleSheet("color : red;");
        ui->time114->setText(timetext);
    }
}

void secound_Floor::on_btn115_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn115->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn115->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn115->setText("이용중");
        ui->time115->setStyleSheet("color : red;");
        ui->time115->setText(timetext);
    }
}

void secound_Floor::on_btn116_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn116->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn116->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn116->setText("이용중");
        ui->time116->setStyleSheet("color : red;");
        ui->time116->setText(timetext);
    }
}

void secound_Floor::on_btn117_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn117->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn117->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn117->setText("이용중");
        ui->time117->setStyleSheet("color : red;");
        ui->time117->setText(timetext);
    }
}

void secound_Floor::on_btn118_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn118->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn118->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn118->setText("이용중");
        ui->time118->setStyleSheet("color : red;");
        ui->time118->setText(timetext);
    }
}

void secound_Floor::on_btn119_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn119->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn119->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn119->setText("이용중");
        ui->time119->setStyleSheet("color : red;");
        ui->time119->setText(timetext);
    }
}

void secound_Floor::on_btn120_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn120->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn120->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn120->setText("이용중");
        ui->time120->setStyleSheet("color : red;");
        ui->time120->setText(timetext);
    }
}
//
void secound_Floor::on_btn121_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn121->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn121->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn121->setText("이용중");
        ui->time121->setStyleSheet("color : red;");
        ui->time121->setText(timetext);
    }
}


void secound_Floor::on_btn122_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn122->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn122->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn122->setText("이용중");
        ui->time122->setStyleSheet("color : red;");
        ui->time122->setText(timetext);
    }
}

void secound_Floor::on_btn123_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn123->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn123->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn123->setText("이용중");
        ui->time123->setStyleSheet("color : red;");
        ui->time123->setText(timetext);
    }
}

void secound_Floor::on_btn124_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn124->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn124->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn124->setText("이용중");
        ui->time124->setStyleSheet("color : red;");
        ui->time124->setText(timetext);
    }
}

void secound_Floor::on_btn125_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn125->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn125->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn125->setText("이용중");
        ui->time125->setStyleSheet("color : red;");
        ui->time125->setText(timetext);
    }
}

void secound_Floor::on_btn126_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn126->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn126->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn126->setText("이용중");
        ui->time126->setStyleSheet("color : red;");
        ui->time126->setText(timetext);
    }
}

void secound_Floor::on_btn127_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn127->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn127->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn127->setText("이용중");
        ui->time127->setStyleSheet("color : red;");
        ui->time127->setText(timetext);
    }
}

void secound_Floor::on_btn128_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn128->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn128->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn128->setText("이용중");
        ui->time128->setStyleSheet("color : red;");
        ui->time128->setText(timetext);
    }
}

void secound_Floor::on_btn129_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn129->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn129->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn129->setText("이용중");
        ui->time129->setStyleSheet("color : red;");
        ui->time129->setText(timetext);
    }
}

void secound_Floor::on_btn130_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn130->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn130->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn130->setText("이용중");
        ui->time130->setStyleSheet("color : red;");
        ui->time130->setText(timetext);
    }
}
//
void secound_Floor::on_btn131_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn131->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn131->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn131->setText("이용중");
        ui->time131->setStyleSheet("color : red;");
        ui->time131->setText(timetext);
    }
}


void secound_Floor::on_btn132_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn132->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn132->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn132->setText("이용중");
        ui->time132->setStyleSheet("color : red;");
        ui->time132->setText(timetext);
    }
}

void secound_Floor::on_btn133_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn133->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn133->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn133->setText("이용중");
        ui->time133->setStyleSheet("color : red;");
        ui->time133->setText(timetext);
    }
}

void secound_Floor::on_btn134_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn134->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn134->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn134->setText("이용중");
        ui->time134->setStyleSheet("color : red;");
        ui->time134->setText(timetext);
    }
}

void secound_Floor::on_btn135_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn135->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn135->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn135->setText("이용중");
        ui->time135->setStyleSheet("color : red;");
        ui->time135->setText(timetext);
    }
}

void secound_Floor::on_btn136_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn136->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn136->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn136->setText("이용중");
        ui->time136->setStyleSheet("color : red;");
        ui->time136->setText(timetext);
    }
}

void secound_Floor::on_btn137_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn137->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn137->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn137->setText("이용중");
        ui->time137->setStyleSheet("color : red;");
        ui->time137->setText(timetext);
    }
}

void secound_Floor::on_btn138_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn138->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn138->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn138->setText("이용중");
        ui->time138->setStyleSheet("color : red;");
        ui->time138->setText(timetext);
    }
}

void secound_Floor::on_btn139_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn139->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn139->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn139->setText("이용중");
        ui->time139->setStyleSheet("color : red;");
        ui->time139->setText(timetext);
    }
}

void secound_Floor::on_btn140_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn140->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn140->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn140->setText("이용중");
        ui->time140->setStyleSheet("color : red;");
        ui->time140->setText(timetext);
    }
}
//
void secound_Floor::on_btn141_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn141->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn141->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn141->setText("이용중");
        ui->time141->setStyleSheet("color : red;");
        ui->time141->setText(timetext);
    }
}


void secound_Floor::on_btn142_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn142->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn142->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn142->setText("이용중");
        ui->time142->setStyleSheet("color : red;");
        ui->time142->setText(timetext);
    }
}

void secound_Floor::on_btn143_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn143->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn143->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn143->setText("이용중");
        ui->time143->setStyleSheet("color : red;");
        ui->time143->setText(timetext);
    }
}

void secound_Floor::on_btn144_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn144->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn144->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn144->setText("이용중");
        ui->time144->setStyleSheet("color : red;");
        ui->time144->setText(timetext);
    }
}

void secound_Floor::on_btn145_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn145->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn145->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn145->setText("이용중");
        ui->time145->setStyleSheet("color : red;");
        ui->time145->setText(timetext);
    }
}

void secound_Floor::on_btn146_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn146->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn146->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn146->setText("이용중");
        ui->time146->setStyleSheet("color : red;");
        ui->time146->setText(timetext);
    }
}

void secound_Floor::on_btn147_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn147->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn147->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn147->setText("이용중");
        ui->time147->setStyleSheet("color : red;");
        ui->time147->setText(timetext);
    }
}

void secound_Floor::on_btn148_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn148->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn148->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn148->setText("이용중");
        ui->time148->setStyleSheet("color : red;");
        ui->time148->setText(timetext);
    }
}

void secound_Floor::on_btn149_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn149->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn149->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn149->setText("이용중");
        ui->time149->setStyleSheet("color : red;");
        ui->time149->setText(timetext);
    }
}

void secound_Floor::on_btn150_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn150->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn150->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn150->setText("이용중");
        ui->time150->setStyleSheet("color : red;");
        ui->time150->setText(timetext);
    }
}
//
void secound_Floor::on_btn151_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn151->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn151->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn151->setText("이용중");
        ui->time151->setStyleSheet("color : red;");
        ui->time151->setText(timetext);
    }
}


void secound_Floor::on_btn152_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn152->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn152->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn152->setText("이용중");
        ui->time152->setStyleSheet("color : red;");
        ui->time152->setText(timetext);
    }
}

void secound_Floor::on_btn153_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn153->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn153->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn153->setText("이용중");
        ui->time153->setStyleSheet("color : red;");
        ui->time153->setText(timetext);
    }
}

void secound_Floor::on_btn154_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn154->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn154->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn154->setText("이용중");
        ui->time154->setStyleSheet("color : red;");
        ui->time154->setText(timetext);
    }
}

void secound_Floor::on_btn155_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn155->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn155->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn155->setText("이용중");
        ui->time155->setStyleSheet("color : red;");
        ui->time155->setText(timetext);
    }
}

void secound_Floor::on_btn156_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn156->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn156->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn156->setText("이용중");
        ui->time156->setStyleSheet("color : red;");
        ui->time156->setText(timetext);
    }
}

void secound_Floor::on_btn157_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn157->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn157->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn157->setText("이용중");
        ui->time157->setStyleSheet("color : red;");
        ui->time157->setText(timetext);
    }
}

void secound_Floor::on_btn158_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn158->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn158->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn158->setText("이용중");
        ui->time158->setStyleSheet("color : red;");
        ui->time158->setText(timetext);
    }
}

void secound_Floor::on_btn159_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn159->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn159->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn159->setText("이용중");
        ui->time159->setStyleSheet("color : red;");
        ui->time159->setText(timetext);
    }
}

void secound_Floor::on_btn160_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn10->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn160->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn160->setText("이용중");
        ui->time160->setStyleSheet("color : red;");
        ui->time160->setText(timetext);
    }
}
//
void secound_Floor::on_btn161_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn1->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn161->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn161->setText("이용중");
        ui->time161->setStyleSheet("color : red;");
        ui->time161->setText(timetext);
    }
}


void secound_Floor::on_btn162_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn2->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn162->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn162->setText("이용중");
        ui->time162->setStyleSheet("color : red;");
        ui->time162->setText(timetext);
    }
}

void secound_Floor::on_btn163_clicked()
{
    mysql my;
    timetext = my.MessageBox(ui->btn3->objectName());
    qDebug()<<"timetext : " + timetext;
    if(timetext == "xxx") { QMessageBox::information(this,"Notice","이용할 수 없습니다.");}
    else { if(timetext.length() == 5) { timetext.insert(1,":"); timetext.insert(4,":"); }
        else { timetext.insert(2,":"); timetext.insert(5,":"); }
        ui->btn163->setStyleSheet("background-color : red; font-weight : bold;");
        ui->btn163->setText("이용중");
        ui->time163->setStyleSheet("color : red;");
        ui->time163->setText(timetext);
    }
}







