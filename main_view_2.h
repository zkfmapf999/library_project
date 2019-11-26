#ifndef MAIN_VIEW_2_H
#define MAIN_VIEW_2_H

#include <QWidget>

namespace Ui {
class main_view_2;
}

class main_view_2 : public QWidget
{
    Q_OBJECT

public:
    explicit main_view_2(QWidget *parent = 0);
    ~main_view_2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::main_view_2 *ui;
};

#endif // MAIN_VIEW_2_H
