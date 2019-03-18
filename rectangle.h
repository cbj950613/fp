#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsRectItem>

class rectangle : public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // RECTANGLE_H
