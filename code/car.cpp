#include "car.h"
#include <QDebug>
#include "lawnscene.h"

Car::Car(lawnScene*Lawn,QWidget *parent) : QLabel(parent)
{
    lawn=Lawn;
    this->setMovie(animation);
    animation->start();
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
    show();
    this->speed = 30;//5
    //qDebug()<<"hit";
}

Car::Car(darkScene*Dark,QWidget *parent) : QLabel(parent)
{
    dark=Dark;
    this->setMovie(animation);
    animation->start();
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
    show();
    this->speed = 30;//5
    //qDebug()<<"hit";
}

Car::~Car()
{
    if(animation!=NULL)
        delete animation;
    animation=nullptr;
}

bool Car::Present()
{
    return present;
}

void Car::todo()
{
    Zombie* zombie;

    foreach (zombie, lawn->zombieSet)
    {
        if (qAbs(zombie->x() - this->x() + zombie->offset + 60)<30 && ((this->row) == (zombie->row)) && present)
        {
            Drive=true;
        }
    }
    if(!Drive)
        return;
    this->raise();
    if (this->x()>=LAWN_W)
    {
        present = false;
        //qDebug()<<"false";
    }
    this->move(this->x() + this->speed , this->y());
    foreach (zombie, lawn->zombieSet)
    {
        if ((qAbs(zombie->x() - this->x() + zombie->offset + 60) < 20) && ((this->row) == (zombie->row)) && present)
        {
            zombie->hit(15000);
            //qDebug()<<"101";
        }
    }
}

void Car::setRow(int r)
{
    row=r;
}
