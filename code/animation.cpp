#include "animation.h"
#include <QDebug>

Animation::Animation(QWidget *parent) : QLabel(parent)
{
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
}

bool Animation::Present()
{
    return present;
}

Animation::~Animation()
{

}

void Animation::todo()
{
    if(timer>0)
        timer--;
    else
        present=false;
}

//Mashed
Mashed::Mashed(QWidget* parent):Animation(parent)
{
    setMovie(animation);
    animation->start();
    show();
    timer = 20;
}
Mashed::~Mashed()
{
    delete animation;
    animation=NULL;
}

//Boom
Boom::Boom(QWidget* parent):Animation(parent)
{
    setMovie(animation);
    animation->start();
    show();
    timer = 20;
}
Boom::~Boom()
{
    delete animation;
    animation=NULL;
}

//Dashed
Dashed::Dashed(QWidget* parent):Animation(parent)
{
    setMovie(animation);
    animation->start();
    show();
    timer = 20;
}
Dashed::~Dashed()
{
    delete animation;
    animation=NULL;
}

//PeaHit
PeaHit::PeaHit(QWidget* parent):Animation(parent)
{
    setMovie(animation);
    animation->start();
    show();
    timer = 3;
}
PeaHit::~PeaHit()
{
    delete animation;
    animation=NULL;
}

//SnowHit
SnowHit::SnowHit(QWidget* parent):Animation(parent)
{
    setMovie(animation);
    animation->start();
    show();
    timer = 3;
}
SnowHit::~SnowHit()
{
    delete animation;
    animation=NULL;
}

//BurnDie
BurnDie::BurnDie(QWidget* parent ):Animation(parent)
{
    setMovie(animation);
    animation->start();
    show();
    timer = 80;
}
BurnDie::~BurnDie()
{
    delete animation;
    animation=NULL;
}

//ZombieDie
ZombieDie::ZombieDie(QWidget* parent ):Animation(parent)
{
    setMovie(animation);
    animation->start();
    show();
    timer = 30;
}
ZombieDie::~ZombieDie()
{
    delete animation;
    animation=NULL;
}

//ZombieHead
ZombieHead::ZombieHead(QWidget* parent ):Animation(parent)
{
    setMovie(animation);
    animation->start();
    show();
    timer = 30;
}
ZombieHead::~ZombieHead()
{
    delete animation;
    animation=NULL;
}
