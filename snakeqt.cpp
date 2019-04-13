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
    dots = 3;
    for(int i = 0; i < dots; i++){
        snake.push_back(snakepart(40+i,10));
    }
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

void snakeqt::game_over(QPainter &qp){
    QString message = "game over!";
    int h = height();
    int w = width();
    qp.translate(QPoint(w/2,h/2));
}
void snakeqt::checkfood(){
    if((x[0] == food_x) && (y[0] == food_y)){
        dots++;
        putfood();
    }
}

void snakeqt::movesnake(){
    for( int i = dots; i > 0; i--){
        x[i] = x[i-1];
        y[i] = y[i-1];
    }
    if(left){
        x[0] -= dot_size;
    }
    if(right)
}
