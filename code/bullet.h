#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include <QLabel>
#include <QMovie>

class lawnScene;

class Bullet : public QLabel
{
    Q_OBJECT
public:
    Bullet(lawnScene*Lawn,QWidget *parent = nullptr);
    virtual void todo()=0;
    virtual ~Bullet();
    void setRow(int r);
    bool Present();
    lawnScene*lawn=NULL;

protected:
    bool present=true;
    int row;
signals:

};

class Pea:public Bullet
{
    Q_OBJECT
public:
    Pea(lawnScene*Lawn,QWidget *parent = nullptr);
    void todo();
    ~Pea();

private:
    QMovie*animation=new QMovie(":/res/plant/Pea.gif");
    int speed;

signals:

};

class IcePea:public Bullet
{
    Q_OBJECT
public:
    IcePea(lawnScene*Lawn,QWidget *parent = nullptr);
    void todo();
    ~IcePea();

private:
    QMovie*animation=new QMovie(":/res/plant/PeaIce.gif");
    int speed;

signals:

};

class Mush : public Bullet
{
public:
    Mush(lawnScene*Lawn,QWidget* parent = nullptr);
    ~Mush();
    void todo();
private:
    QMovie* animation = new QMovie(":/res/plant/Mush.gif");
    int speed;
    int TimerFly;
};
class pMush : public Bullet
{
public:
    pMush(lawnScene*Lawn,QWidget* parent = nullptr);
    ~pMush();
    void todo();
private:
    QMovie* animation = new QMovie(":/res/plant/Mush.gif");
    int speed;
    int TimerFly;
};

#endif // BULLET_H
