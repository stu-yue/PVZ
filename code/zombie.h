#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QLabel>

class lawnScene;
class darkScene;

class Zombie : public QLabel
{
    Q_OBJECT
public:
    Zombie(lawnScene*lawn,QWidget *parent = nullptr);
    Zombie(darkScene*dark,QWidget *parent = nullptr);

    virtual void todo();
    virtual void hit(int damage, bool silence = false);
    virtual void ice();
    bool Present();
    int row;
    int offset = 0;
    int eatFrame = 0;
    int HP;
    bool isIce = false;
    bool hasShield = false;
    float speed;
    lawnScene*scene=NULL;
    darkScene*scene2=NULL;

protected:
    bool present=true;

signals:

};

class NormalZombie : public Zombie
{
    Q_OBJECT
public:
    NormalZombie(lawnScene*lawn,QWidget* parent = 0, int type = 0);
    NormalZombie(darkScene*dark,QWidget* parent = 0, int type = 0);
    ~NormalZombie();
    void todo();
    void hit(int damage, bool silence = false);
    void ice();
private:
    QMovie* walkMovie = nullptr;
    QMovie* attackMovie = nullptr;
    QMovie* propWalkMovie = nullptr;
    QMovie* propAttackMovie = nullptr;
    bool prop, iron;
    int prop_strength;
    float xpos;
};

#endif // ZOMBIE_H
