#ifndef ANIMATION_H
#define ANIMATION_H

#include <QWidget>
#include <QLabel>
#include <QMovie>

class Animation : public QLabel
{
    Q_OBJECT
public:
    Animation(QWidget *parent = nullptr);
    ~Animation();
    void todo();
    bool Present();

protected:
    int timer;
    bool present=true;

signals:

};

class Mashed : public Animation
{
public:
    Mashed(QWidget* parent = nullptr);
    ~Mashed();
private:
    QMovie* animation = new QMovie(":/res/plant/mashed.gif");
};

class Boom : public Animation
{
public:
    Boom(QWidget* parent = nullptr);
    ~Boom();
private:
    QMovie* animation = new QMovie(":/res/plant/boom_p2.gif");
};

class Dashed : public Animation
{
public:
    Dashed(QWidget* parent = nullptr);
    ~Dashed();
private:
    QMovie* animation = new QMovie(":/res/plant/dash.gif");
};

class PeaHit : public Animation
{
public:
    PeaHit(QWidget* parent = nullptr);
    ~PeaHit();
private:
    QMovie* animation = new QMovie(":/res/plant/PeaHit.gif");
};

class SnowHit : public Animation
{
public:
    SnowHit(QWidget* parent = nullptr);
    ~SnowHit();
private:
    QMovie* animation = new QMovie(":/res/plant/PeaHit.gif");
};

class BurnDie : public Animation
{
public:
    BurnDie(QWidget* parent = nullptr);
    ~BurnDie();
private:
    QMovie* animation = new QMovie(":/res/BurnDie.gif");
};

class ZombieDie : public Animation
{
public:
    ZombieDie(QWidget* parent = nullptr);
    ~ZombieDie();
private:
    QMovie* animation = new QMovie(":/res/ZombieDie.gif");
};

class ZombieHead : public Animation
{
public:
    ZombieHead(QWidget* parent = nullptr);
    ~ZombieHead();
private:
    QMovie* animation = new QMovie(":/res/ZombieHead.gif");
};


#endif // ANIMATION_H

