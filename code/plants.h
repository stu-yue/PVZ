#ifndef PLANTS_H
#define PLANTS_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QSound>

class lawnScene;
class darkScene;

class Plants : public QLabel
{
    Q_OBJECT
public:
    Plants(lawnScene*lawn,QWidget *parent = nullptr);
    virtual ~Plants();
    virtual void todo();
    void hit(int attack);
    bool Present();
    int getRow();

protected:
    int HP;
    bool present;
    int row,col;//to paint animation exactly
    lawnScene *scene;
    darkScene *scene_1;

    friend class lawnScene;
    friend class darkScene;
};

class PeaShooter:public Plants
{
    Q_OBJECT
public:
    PeaShooter(lawnScene*lawn,QWidget *parent=nullptr);
    ~PeaShooter();
    void todo();

private:
    QMovie*animation=new QMovie(":/res/plant/Peashooter.gif");
    //QSound*audio=new QSound(":/res/PeaHit.wav");
    int shootCounter,shootSpeed;
};

class RePeater:public Plants
{
    Q_OBJECT
public:
    RePeater(lawnScene*lawn,QWidget *parent = nullptr);
    ~RePeater();
    void todo();

private:
    QMovie*animation=new QMovie(":/res/plant/Repeater.gif");
    int shootCounter,shootSpeed;
};

class SunFlower:public Plants
{
    Q_OBJECT
public:
    SunFlower(lawnScene*lawn,QWidget *parent = nullptr);
    ~SunFlower();
    void todo();

private:
    QMovie*animation=new QMovie(":/res/plant/s3.gif");
    int Counter,Speed;
};

class TallNut:public Plants
{
    Q_OBJECT
public:
    TallNut(lawnScene*lawn,QWidget *parent = nullptr);
    ~TallNut();
    void todo();

private:
    QMovie*animation1=new QMovie(":/res/plant/tallnut.gif");
    QMovie*animation2=new QMovie(":/res/plant/tallnut1.gif");
    QMovie*animation3=new QMovie(":/res/plant/tallnut2.gif");
    //int shootCounter,shooterSpeed;
};

class CherryBomb:public Plants
{
    Q_OBJECT
public:
    CherryBomb(lawnScene*lawn,QWidget *parent = nullptr);
    ~CherryBomb();
    void todo();

private:
    QMovie*animation=new QMovie(":/res/plant/CherryBomb.gif");
    int Counter,Speed;
};

class WallNut:public Plants
{
    Q_OBJECT
public:
    WallNut(lawnScene*lawn,QWidget *parent = nullptr);
    ~WallNut();
    void todo();

private:
    QMovie*animation1=new QMovie(":/res/plant/WallNut.gif");
    QMovie*animation2=new QMovie(":/res/plant/WallNut1.gif");
    QMovie*animation3=new QMovie(":/res/plant/Wallnut2.gif");;
    //int shootCounter,shooterSpeed;
};

class SnowPea:public Plants
{
    Q_OBJECT
public:
    SnowPea(lawnScene*lawn,QWidget *parent = nullptr);
    ~SnowPea();
    void todo();

private:
    QMovie*animation=new QMovie(":/res/plant/IcePeaShooter.gif");
    int shootCounter,shootSpeed;
};

class PotatoMine:public Plants
{
    Q_OBJECT
public:
    PotatoMine(lawnScene*lawn,QWidget *parent = nullptr);
    ~PotatoMine();
    void todo();

private:
    QMovie*animation1=new QMovie(":/res/plant/PotatoMine1.gif");
    QMovie*animation2=new QMovie(":/res/plant/PotatoMine.gif");
    int Counter,Speed;
};

class Squash:public Plants
{
    Q_OBJECT
public:
    Squash(lawnScene*lawn,QWidget *parent = nullptr);
    ~Squash();
    void todo();

private:
    QMovie*animation=new QMovie(":/res/plant/squash.gif");
    //int shootCounter,shooterSpeed;
};

class FumeShroom:public Plants
{
    Q_OBJECT
public:
    FumeShroom(lawnScene*lawn,QWidget *parent = nullptr);
    ~FumeShroom();
    void todo();

private:
    QMovie*animation=new QMovie(":/res/plant/fumeshroom.gif");
    int shootCounter,shootSpeed;
};

class PuffShroom:public Plants
{
    Q_OBJECT
public:
    PuffShroom(lawnScene*lawn,QWidget *parent = nullptr);
    ~PuffShroom();
    void todo();

private:
    QMovie*animation=new QMovie(":/res/plant/Mushroom.gif");
    int shootCounter,shootSpeed;
};
//need rewrite gif
class SunShroom:public Plants
{
    Q_OBJECT
public:
    SunShroom(lawnScene*lawn,QWidget *parent = nullptr);
    ~SunShroom();
    void todo();

private:
    QMovie*animation1=new QMovie(":/res/plant/sunshroom1.gif");
    QMovie*animation2=new QMovie(":/res/plant/sunshroom2.gif");
    int Counter,Speed;
    int growCounter,growSpeed;
};





#endif // PLANTS_H
