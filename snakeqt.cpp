#include "snakeqt.h"
#include <QPainter>
#include <QTime>
snakepart::snakepart(int col, int row){
    x = col;
    y = row;
}

snakepart::snakepart(){
    x = 0;
    y = 0;
}

snakeqt::snakeqt(QWidget *parent) :
    QWidget(parent)
{
    left = true;
    right = false;
    up = false;
    down = false;
    alive = true;

    resize(maxwidth, maxheight);
    startgame();
}

void snakeqt::startgame(){
    for(int i = 0; i < points; i++){
        snake.push_back(snakepart(40+i,10));
    }
    points = 0;
    putfood();
    time = startTimer(del);
}

void snakeqt::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    draw();
}

void snakeqt::draw(){
    QPainter qp(this);
    if(alive){
        qp.drawImage(food_x, food_y,food);
        for(int i = 0; i < dots; i++){
            if(i == 0){
                qp.drawImage(x[i], y[i], snakehead);
            }
            else{
                qp.drawImage(x[i],y[i], snakeparts);
            }
        }
        }
    else{
        game_over(qp);

    }
}
