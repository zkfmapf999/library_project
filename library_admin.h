#ifndef LIBRARY_ADMIN_H
#define LIBRARY_ADMIN_H

#include <QWidget>
#include "header.h"
#include "mysql.h"

namespace Ui {
class library_admin;
}

class library_admin : public QWidget
{
    Q_OBJECT

public:
    explicit library_admin(QWidget *parent = 0);
    ~library_admin();

private slots:
    void on_studentFindBtn_clicked();

private:
    Ui::library_admin *ui;
};

#endif // LIBRARY_ADMIN_H
