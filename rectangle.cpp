#include "rectangle.h"
#include <QKeyEvent>
void rectangle::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        setPos(x()-100,y());}
    if(event->key() == Qt::Key_Right){
        setPos(x()+100,y());}
    if(event->key() == Qt::Key_Up){
        setPos(x(),y()-100);}
    if(event->key() == Qt::Key_Down){
        setPos(x(),y()+100);}
}
