#ifndef SNAKEQT_H
#define SNAKEQT_H
#include <QKeyEvent>
#include <QWidget>
#include <vector>
#include <iostream>
#include <cstdlib>

namespace Ui {
class snakeqt;
}

struct snakepart{
    int x,y;
    snakepart(int col, int row);
    snakepart();
};

class snakeqt : public QWidget
{
    Q_OBJECT

public:
    snakeqt(QWidget *parent = 0);
    std::vector<snakepart> snake;
    ~snakeqt();
    void start();


    int points, del, maxwidth, maxheight;
    char direction, partchar, oldalchar, foo;
    bool get;
    snakepart food;

    void putfood();
    bool collision();
    void movesnake();
/*
protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent*);
    void keyPressEvent(QKeyEvent *);

private:
    static const int maxwidth = 500;
    static const int maxheight = 500;
    static const int dot_size = 10;
    static const int del = 100;
    static const int thedots = 900;
    static const int rando = 29;

    QImage food;
    QImage snakeparts;
    QImage snakehead;

    int dots;
    int food_x;
    int food_y;
    int time;
    int x[thedots];
    int y[thedots];
    bool left;
    bool right;
    bool up;
    bool down;
    bool alive;

    void loadimage();
    void startgame();
    void putfood();
    void collision();
    void checkfood();
    void movesnake();
    void draw();
    void game_over(QPainter &);

    Ui::snakeqt *ui;
    */
};

#endif // SNAKEQT_H
