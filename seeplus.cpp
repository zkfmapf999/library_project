#include "seeplus.h"
#include "ui_seeplus.h"

seeplus::seeplus(QString name,QString Title, QString txt) :
    ui(new Ui::seeplus)
{
    ui->setupUi(this);
    ui->labelName->setText("작성자 : " + name);
    ui->label->setText("제목 : " + Title);
    ui->text1->setText(txt);
}

seeplus::~seeplus()
{
    delete ui;
}

void seeplus::on_pushButton_clicked()
{
    seeboard *see = new seeboard();
    see->show();
    close();
}
