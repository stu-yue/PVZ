#include "sun.h"
#include <QLabel>

extern int sunShine;

Sun::~Sun()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=NULL;
    }
    if(audio!=NULL)
    {
        delete audio;
        audio=NULL;
    }
}

Sun::Sun(QWidget *parent) : QLabel(parent)
{
    this->setGeometry(qrand()%300+200,50,76,75);
    this->setMovie(animation);
    animation->start();
    this->show();
    present=true;
    speed=5;
    collected=false;
    countDown=500;
    altitude=qrand()%50+400;
}

void Sun::setAltitude(int x)
{
    altitude=x;
}

void Sun::todo()
{
    this->raise();
    countDown--;
    if(countDown<=0)
        present=false;
    else if(this->y()<=this->altitude)
        this->move(QPoint(this->x(),this->y()+this->speed));
    if(collected)
    {
        if(this->x()>15&&this->y()>30)
            this->move(QPoint(this->x()/2,this->y()/2));
        else
            present=false;
    }
}

void Sun::mousePressEvent(QMouseEvent*event)
{
    this->collected=true;
    sunShine+=25;
    //audio->play();
    QSound::play(":/res/Sun.wav");
}

bool Sun::Present()
{
    return present;
}
