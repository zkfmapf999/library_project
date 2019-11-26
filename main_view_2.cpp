#include "main_view_2.h"
#include "ui_main_view_2.h"
#include <QDesktopServices>
#include <QUrl>
#include <QString>

main_view_2::main_view_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::main_view_2)
{
    ui->setupUi(this);

    setWindowTitle("공지사항");

    ui->label_1->setText("1. 국치일 상기 및 UN의 날 기념 PT경진대회 안내");
    ui->label_3->setText("2. 2019년 서부 위피스쿨 6기 대학생 멘토 모집");
    ui->label_4->setText("3. 제 20회 강원도 대학생 창업 경진대회(창업캠프)참가자 모집");
    ui->label_5->setText("4. 사회봉사활동 실적 입력방법 안내 - 학생용");
    ui->label_6->setText("5. 캠퍼스별 시험기간 중 자료실 열람실 운영시간 안내");
    ui->label_7->setText("6. 2019 전자정보전시회 당첨자 명단안내");
    ui->label_8->setText("7. 중앙도서관 카카오톡 계정 개설");
}

main_view_2::~main_view_2()
{
    delete ui;
}

void main_view_2::on_pushButton_clicked()
{
    QString link = "http://kduniv.ac.kr/www/index.php?pCode=1327028726&pg=1&mode=view&idx=8450";
    QDesktopServices::openUrl(QUrl(link));
}
