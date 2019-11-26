#ifndef LIBRARY_RECOMMAND_H
#define LIBRARY_RECOMMAND_H

#include <QWidget>
#include <mysql.h>
#include <main_view.h>

namespace Ui {
class library_recommand;
}

class library_recommand : public QWidget
{
    Q_OBJECT

public:
    explicit library_recommand(QWidget *parent = 0);
    ~library_recommand();

private:
    Ui::library_recommand *ui;
};

#endif // LIBRARY_RECOMMAND_H
