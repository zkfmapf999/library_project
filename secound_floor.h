#ifndef SECOUND_FLOOR_H
#define SECOUND_FLOOR_H

#include "library_seat.h"
#include "header.h"
#include "mysql.h"
#include <QWidget>
#include "ui_secound_floor.h"
#include <QPushButton>
#include <QLabel>

namespace Ui {
class secound_Floor;
}

class secound_Floor : public QWidget
{
    Q_OBJECT

public:
    explicit secound_Floor(QWidget *parent = 0);
    ~secound_Floor();

private slots:
    void on_pushButton_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
    void on_btn10_clicked();
    //
    void on_btn11_clicked();
    void on_btn12_clicked();
    void on_btn13_clicked();
    void on_btn14_clicked();
    void on_btn15_clicked();
    void on_btn16_clicked();
    void on_btn17_clicked();
    void on_btn18_clicked();
    void on_btn19_clicked();
    void on_btn20_clicked();
    //
    void on_btn21_clicked();
    void on_btn22_clicked();
    void on_btn23_clicked();
    void on_btn24_clicked();
    void on_btn25_clicked();
    void on_btn26_clicked();
    void on_btn27_clicked();
    void on_btn28_clicked();
    void on_btn29_clicked();
    void on_btn30_clicked();
    //
    void on_btn31_clicked();
    void on_btn32_clicked();
    void on_btn33_clicked();
    void on_btn34_clicked();
    void on_btn35_clicked();
    void on_btn36_clicked();
    void on_btn37_clicked();
    void on_btn38_clicked();
    void on_btn39_clicked();
    void on_btn40_clicked();
    //
    void on_btn41_clicked();
    void on_btn42_clicked();
    void on_btn43_clicked();
    void on_btn44_clicked();
    void on_btn45_clicked();
    void on_btn46_clicked();
    void on_btn47_clicked();
    void on_btn48_clicked();
    void on_btn49_clicked();
    void on_btn50_clicked();
    //
    void on_btn51_clicked();
    void on_btn52_clicked();
    void on_btn53_clicked();
    void on_btn54_clicked();
    void on_btn55_clicked();
    void on_btn56_clicked();
    void on_btn57_clicked();
    void on_btn58_clicked();
    void on_btn59_clicked();
    void on_btn60_clicked();
    //
    void on_btn61_clicked();
    void on_btn62_clicked();
    void on_btn63_clicked();
    void on_btn64_clicked();
    void on_btn65_clicked();
    void on_btn66_clicked();
    void on_btn67_clicked();
    void on_btn68_clicked();
    void on_btn69_clicked();
    void on_btn70_clicked();
    //
    void on_btn71_clicked();
    void on_btn72_clicked();
    void on_btn73_clicked();
    void on_btn74_clicked();
    void on_btn75_clicked();
    void on_btn76_clicked();
    void on_btn77_clicked();
    void on_btn78_clicked();
    void on_btn79_clicked();
    void on_btn80_clicked();
    //
    void on_btn81_clicked();
    void on_btn82_clicked();
    void on_btn83_clicked();
    void on_btn84_clicked();
    void on_btn85_clicked();
    void on_btn86_clicked();
    void on_btn87_clicked();
    void on_btn88_clicked();
    void on_btn89_clicked();
    void on_btn90_clicked();
    //
    void on_btn91_clicked();
    void on_btn92_clicked();
    void on_btn93_clicked();
    void on_btn94_clicked();
    void on_btn95_clicked();
    void on_btn96_clicked();
    void on_btn97_clicked();
    void on_btn98_clicked();
    void on_btn99_clicked();
    void on_btn100_clicked();
    //
    void on_btn101_clicked();
    void on_btn102_clicked();
    void on_btn103_clicked();
    void on_btn104_clicked();
    void on_btn105_clicked();
    void on_btn106_clicked();
    void on_btn107_clicked();
    void on_btn108_clicked();
    void on_btn109_clicked();
    void on_btn110_clicked();
    //
    void on_btn111_clicked();
    void on_btn112_clicked();
    void on_btn113_clicked();
    void on_btn114_clicked();
    void on_btn115_clicked();
    void on_btn116_clicked();
    void on_btn117_clicked();
    void on_btn118_clicked();
    void on_btn119_clicked();
    void on_btn120_clicked();
    //
    void on_btn121_clicked();
    void on_btn122_clicked();
    void on_btn123_clicked();
    void on_btn124_clicked();
    void on_btn125_clicked();
    void on_btn126_clicked();
    void on_btn127_clicked();
    void on_btn128_clicked();
    void on_btn129_clicked();
    void on_btn130_clicked();
    //
    void on_btn131_clicked();
    void on_btn132_clicked();
    void on_btn133_clicked();
    void on_btn134_clicked();
    void on_btn135_clicked();
    void on_btn136_clicked();
    void on_btn137_clicked();
    void on_btn138_clicked();
    void on_btn139_clicked();
    void on_btn140_clicked();
    //
    void on_btn141_clicked();
    void on_btn142_clicked();
    void on_btn143_clicked();
    void on_btn144_clicked();
    void on_btn145_clicked();
    void on_btn146_clicked();
    void on_btn147_clicked();
    void on_btn148_clicked();
    void on_btn149_clicked();
    void on_btn150_clicked();
    //
    void on_btn151_clicked();
    void on_btn152_clicked();
    void on_btn153_clicked();
    void on_btn154_clicked();
    void on_btn155_clicked();
    void on_btn156_clicked();
    void on_btn157_clicked();
    void on_btn158_clicked();
    void on_btn159_clicked();
    void on_btn160_clicked();
    //
    void on_btn161_clicked();
    void on_btn162_clicked();
    void on_btn163_clicked();

public:
    QString str;
    QString timetext;

private:
    Ui::secound_Floor *ui;
    bool boolean;


};

#endif // SECOUND_FLOOR_H
