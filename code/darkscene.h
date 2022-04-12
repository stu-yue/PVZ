#ifndef DARKSCENE_H
#define DARKSCENE_H

#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QSound>
#include "sun.h"
#include "plants.h"
#include "bullet.h"
#include "zombie.h"
#include "card.h"
#include "animation.h"
#include "car.h"
#include "lawnscene.h"


class darkScene : public QWidget
{
    Q_OBJECT
public:
    darkScene(QWidget *parent = nullptr);
    ~darkScene();

    QList<Sun*>sunSet;
    QList<Plants*>plantSet;
    QList<Zombie*>zombieSet;
    QList<Bullet*>bulletSet;
    QList<Animation*>animationSet;
    QList<Card*>cardSet;
    QList<Car*>carSet;
    void paintEvent(QPaintEvent *event);
    void setUI();

    QPoint grid;
    QPoint gridSize = QPoint(83, 95);
    QRect rect = QRect(120, 90, LAWN_W-120, 560-90);

    QTimer*timer=NULL;
    QSound*music=NULL;

    void remove();
    void todo();
    void onTimer();
    void createZombie();
    void invadeOK();
    QPoint getGridSize();
    void plantPlants(QPoint t_cell);
    void putZombie(int raw, int type);

    bool canFire[5];
    int threat = 0;
    bool lose=false;
    bool still=false;
    Card* currentCard = nullptr;
    QLabel*selectedPlant=new QLabel(this);
    QMovie*selectedPlantMovie=new QMovie(this);
    QPoint currentPos;

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);

private:
    QLabel*sunNum=new QLabel(this);
    QLabel*loseMovie=new QLabel(this);
    int counter;

signals:
    void backToMenu();
};

#endif // DARKSCENE_H
