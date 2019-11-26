#ifndef LIBRARY_LIST_H
#define LIBRARY_LIST_H

#include <QWidget>

namespace Ui {
class Library_list;
}

class Library_list : public QWidget
{
    Q_OBJECT

public:
    explicit Library_list(QWidget *parent = 0);
    ~Library_list();

private slots:
    void on_radioButton_1_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Library_list *ui;
};

#endif // LIBRARY_LIST_H
