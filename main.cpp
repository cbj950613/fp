
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <rectangle.h>

int main(int argc, char *argv[])
{
    //setFocusPolicy ( Qt::StrongFocus );
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene();
    rectangle *rect = new rectangle();

    rect->setRect(0,0,10,10);
    scene->addItem(rect);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    QApplication::focusWidget();
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    return a.exec();
}
