#include "snakeqt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    snakeqt w;
    w.show();

    return a.exec();
}
