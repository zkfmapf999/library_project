#ifndef LIBRARY_FIND_3_H
#define LIBRARY_FIND_3_H

#include <QWidget>
#include "library_find.h"
#include "mysql.h"
#include "header.h"

namespace Ui {
class library_find_3;
}

class library_find_3 : public QWidget
{
    Q_OBJECT

public:
    explicit library_find_3(QWidget *parent = 0);
    ~library_find_3();

private slots:
    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::library_find_3 *ui;

    QString cellText;
};

#endif // LIBRARY_FIND_3_H
