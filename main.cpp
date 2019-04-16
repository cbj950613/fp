#include "snakeqt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // could add a menu here if wanted
    QApplication a(argc, argv);
    snakeqt w;
    w.show();

    return a.exec();
}
