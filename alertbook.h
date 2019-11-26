#ifndef ALERTBOOK_H
#define ALERTBOOK_H

#include <QWidget>
#include "mysql.h"

namespace Ui {
class AlertBook;
}

class AlertBook : public QWidget
{
    Q_OBJECT

public:
    explicit AlertBook(quint64 endTime);
    ~AlertBook();

private:
    Ui::AlertBook *ui;
};

#endif // ALERTBOOK_H
