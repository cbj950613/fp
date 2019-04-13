#ifndef SNAKEQT_H
#define SNAKEQT_H
#include <QKeyEvent>
#include <QWidget>

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
protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent*);
    void keyPressEvent(QKeyEvent *);

private:
    static const int maxwidth = 500;
    static const int maxheight = 500;
    int dot_size = 10;
    int del = 100;
    int dots = 900;

    QImage food;
    QImage snakeparts;
    QImage snakehead;

    int points;
    int food_x;
    int food_y;
    int time;
    int x[dots];
    int y[dots];
    bool left;
    bool right;
    bool up;
    bool down;
    bool alive;

    void startgame();
    void putfood();
    void movesnake();
    void draw();
    void game_over(QPainter &);

    Ui::snakeqt *ui;
};

#endif // SNAKEQT_H
