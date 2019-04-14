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
    food.x = 0;
    food.y = 0;
    for(int i = 0; i < 5; i++){
        snake.push_back(snakepart(40+i,10));
    }
    points = 0;
    del = 200;
    get = 0;
    direction = 'l';
    srand(time(0));
    putfood();

    /*
    left = true;
    right = false;
    up = false;
    down = false;
    alive = true;

    resize(maxwidth, maxheight);
    loadimage();
    startgame();*/
}

void snakeqt::loadimage(){
    food.load("/Users/timcho/Downloads/images/reddot.png");
    snakehead.load("/Users/timcho/Downloads/images/greendot.png");
    snakeparts.load("/Users/timcho/Downloads/images/greendot.png");
}

void snakeqt::startgame(){
    dots = 3;
    for(int i = 0; i < dots; i++){
        x[i] = 50 - i * 10;
        y[i] = 50;
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
    if(right){
        x[0] += dot_size;
    }
    if(up){
        y[0] -= dot_size;
    }
    if(down){
        y[0] += dot_size;
    }
}

void snakeqt::collision(){
    for(int i = dots; i > 0; i--){
        if((i>4) && (x[0] == x[i]) && (y[0] == y[i])){
            alive = false;
        }
    }
    if (y[0] >= maxheight) {
            alive = false;
        }

        if (y[0] < 0) {
            alive = false;
        }

        if (x[0] >= maxwidth) {
            alive = false;
        }

        if (x[0] < 0) {
            alive = false;
        }

        if(!alive) {
            killTimer(time);
        }
}

void snakeqt::putfood(){
    QTime timetime = QTime::currentTime();
    qsrand((uint) timetime.msec());
    int a = qrand()%rando;
    food_x = (a*dot_size);
    a = qrand()%rando;
    food_y = (a*dot_size);
}

void snakeqt::timerEvent(QTimerEvent *e){
    Q_UNUSED(e);
    if(alive){
        checkfood();
        collision();
        movesnake();
    }
    repaint();
}

void snakeqt::keyPressEvent(QKeyEvent *e){
    int key = e->key();
    if ((key == Qt::Key_Left) && (!right)) {
           left = true;
           up = false;
           down = false;
       }

       if ((key == Qt::Key_Right) && (!left)) {
           right = true;
           up = false;
           down = false;
       }

       if ((key == Qt::Key_Up) && (!down)) {
           up = true;
           right = false;
           left = false;
       }

       if ((key == Qt::Key_Down) && (!up)) {
           down = true;
           right = false;
           left = false;
       }

       QWidget::keyPressEvent(e);
}
