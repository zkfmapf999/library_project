#include "sign_up.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sign_up w;
    w.show();

    return a.exec();
}
