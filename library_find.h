#ifndef LIBRARY_FIND_H
#define LIBRARY_FIND_H

#include <QWidget>
#include "library_find_3.h"
#include "mysql.h"

namespace Ui {
class library_find;
}

class library_find : public QWidget
{
    Q_OBJECT

public:
    explicit library_find(QWidget *parent = 0);
    ~library_find();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

private:
    Ui::library_find *ui;

protected:
    QString cellText;
};

#endif // LIBRARY_FIND_H
