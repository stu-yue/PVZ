#include "bullet.h"
#include "lawnscene.h"
#include <QDebug>

Bullet::Bullet(lawnScene*Lawn,QWidget *parent) : QLabel(parent)
{
    lawn=Lawn;
}

Bullet::~Bullet()
{

}

bool Bullet::Present()
{
    return present;
}

void Bullet::setRow(int r)
{
    row=r;
}

//Pea
Pea::Pea(lawnScene*Lawn,QWidget *parent):Bullet(Lawn,parent)
{
    this->setMovie(animation);
    animation->start();
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
    show();
    this->speed = 10;//5
    qDebug()<<"hit";
    //this->canFire = true;
}
void Pea::todo()
{
    this->raise();
    if (/*!(lawn->rect.contains(this->pos()))*/this->x()>=LAWN_W)
    {
        present = false;
        qDebug()<<"false";
    }
    //qDebug()<<lawn->x();
    this->move(this->x() + this->speed , this->y());
    Zombie* zombie;
    foreach (zombie, lawn->zombieSet)
    {
        if ((qAbs(zombie->x() - this->x() + zombie->offset + 60) < 20) && ((this->row) == (zombie->row)) && zombie->Present())
        {
             qDebug()<<qAbs(zombie->x() - this->x() + zombie->offset + 60);
            present = false;
            Animation* pea_anim = new PeaHit(lawn);
            pea_anim->setGeometry(this->x() + 20, this->y(), 60, 50);
            lawn->animationSet.append(pea_anim);
            zombie->hit(50);
            qDebug()<<"hit";
            return;
        }
    }
}
Pea::~Pea()
{
    if(animation!=NULL)
        delete animation;
}

//IcePea
IcePea::IcePea(lawnScene*Lawn,QWidget *parent):Bullet(Lawn,parent)
{
    this->setMovie(animation);
    animation->start();
    setParent(Lawn);
    raise();
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
    show();
    this->speed = 10;
}
void IcePea::todo()
{
    this->raise();
    if (!(lawn->rect.contains(this->pos())))
    {
        present = false;
    }
    this->move(this->x() + this->speed , this->y());
    Zombie* zombie;
    foreach (zombie, lawn->zombieSet)
    {
        if ((qAbs(zombie->x() - this->x() + zombie->offset + 60) < 20) && ((this->row) == (zombie->row)) && present)
        {
            present = false;
            Animation* pea_anim = new SnowHit(lawn);
            pea_anim->setGeometry(this->x() + 20, this->y(), 40, 40);
            lawn->animationSet.append(pea_anim);
            zombie->ice();
            zombie->hit(10);
            return;
        }
    }
}
IcePea::~IcePea()
{
    if(animation!=NULL)
        delete animation;
}

//Mush
Mush::Mush(lawnScene*Lawn,QWidget* parent):Bullet(Lawn,parent)
{
    setMovie(animation);
    animation->start();
    this->raise();
    show();
    speed = 12;
    TimerFly = 22;
}
Mush::~Mush()
{
    if(animation!=NULL)
        delete animation;
}
void Mush::todo()
{
    this->raise();
    this->TimerFly --;
    if (this->TimerFly < 0)
        present = false;
    if (!(lawn->rect.contains(this->pos())))
        present = false;
    this->move(this->x() + this->speed , this->y());
    Zombie* zombie;
    foreach (zombie, lawn->zombieSet)
        if ((qAbs(zombie->x() - this->x() + zombie->offset + 60) < 20) && ((this->row) == (zombie->row)) && present)
        {
            present = false;
            zombie->hit(10);
            return;
        }
}

//pMush
pMush::pMush(lawnScene*Lawn,QWidget* parent):Bullet(Lawn,parent)
{
    setMovie(animation);
    animation->start();
    this->raise();
    show();
    speed = 12;
    TimerFly = 22;
}
pMush::~pMush()
{
    if(animation!=NULL)
        delete animation;
}
void pMush::todo()
{
    this->raise();
    this->TimerFly --;
    if (this->TimerFly < 0)
        present = false;
    if (!(lawn->rect.contains(this->pos())))
        present = false;
    this->move(this->x() + this->speed , this->y());
    Zombie* zombie;
    foreach (zombie, lawn->zombieSet)
        if ((qAbs(zombie->x() - this->x() + zombie->offset + 60) < 20) && ((this->row) == (zombie->row)) && present)
        {
            present = false;
            zombie->hit(10);
            return;
        }
}
