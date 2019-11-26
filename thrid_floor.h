#ifndef THRID_FLOOR_H
#define THRID_FLOOR_H

#include <QWidget>

namespace Ui {
class thrid_floor;
}

class thrid_floor : public QWidget
{
    Q_OBJECT

public:
    explicit thrid_floor(QWidget *parent = 0);
    ~thrid_floor();

private slots:
    void on_pushButton_clicked();

private:
    Ui::thrid_floor *ui;
};

#endif // THRID_FLOOR_H
