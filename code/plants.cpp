#include "plants.h"
#include "lawnscene.h"
#include "bullet.h"
#include "sun.h"
#include <QDebug>

//extern bool canFire[5];

Plants::Plants(lawnScene*lawn,QWidget *parent)
{
    present=true;
    scene=lawn;
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
}
Plants::~Plants()
{

}
bool Plants::Present()
{
    return present;
}
void Plants::hit(int attack)
{
    HP-=attack;
    if(HP<=0){
        present=false;
        qDebug()<<"false";
    }
}
void Plants::todo()
{

}
int Plants::getRow()
{
    return row;
}

//PeaShooter
PeaShooter::PeaShooter(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=200;
    setMovie(animation);
    animation->start();
    setParent(lawn);
    show();
    raise();
    shootCounter=0;
    shootSpeed=100;
}
PeaShooter::~PeaShooter()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=NULL;
    }
//    if(audio!=NULL)
//    {
//        delete audio;
//        audio=NULL;
//    }
}
void PeaShooter::todo()
{
    if(shootCounter==shootSpeed){
        shootCounter=0;
        if(!scene->canFire[this->row])
            return;
        Pea*newPea=new Pea(scene,scene);
        newPea->setGeometry(this->x()+20,this->y()+5,50,70);
        newPea->setRow(this->row);
        //newPea->setParent(scene);
        scene->bulletSet.append(newPea);
        qDebug()<<"fire";
        //audio->play();
        QSound::play(":/res/PeaHit.wav");
    }
    else
        shootCounter++;
}

//Repeater
RePeater::RePeater(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=200;
    setMovie(animation);
    animation->start();
    setParent(lawn);
    show();
    raise();
    shootCounter=0;
    shootSpeed=100;
}
RePeater::~RePeater()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=NULL;
    }
//    if(audio!=NULL)
//    {
//        delete audio;
//        audio=NULL;
//    }
}
void RePeater::todo()
{
    if(shootCounter==shootSpeed||shootCounter==shootSpeed-4){
        if(shootCounter==shootSpeed)
            shootCounter=0;
        else if(shootCounter==shootSpeed-4)
            shootCounter++;
        if(!scene->canFire[this->row])
            return;
        Pea*newPea=new Pea(scene,scene);
        newPea->setGeometry(this->x()+20,this->y()+5,50,70);
        newPea->setRow(this->row);
        scene->bulletSet.append(newPea);
        //audio->play();
        QSound::play(":/res/PeaHit.wav");
    }
    else
        shootCounter++;
}

//SunFlower
SunFlower::SunFlower(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=200;
    setMovie(animation);
    animation->start();
    setParent(lawn);
    show();
    raise();
    Counter=0;
    Speed=300;
}
SunFlower::~SunFlower()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=NULL;
    }
}
void SunFlower::todo()
{
    if(Counter==Speed){
        Counter=0;
        Sun*newSun=new Sun(scene);
        newSun->setGeometry(this->x()+20,this->y()+10-(qrand()%5),76,75);
        newSun->setAltitude(this->y()+45);
        scene->sunSet.append(newSun);
        //audio->play();
    }
    else
        Counter++;
}

//TallNut
TallNut::TallNut(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=1500;
    setMovie(animation1);
    animation1->start();
    animation2->start();
    animation3->start();
    setParent(lawn);
    show();
    raise();
}
TallNut::~TallNut()
{
    if(animation1!=NULL)
    {
        delete animation1;
        animation1=NULL;
    }
    if(animation2!=NULL)
    {
        delete animation2;
        animation2=NULL;
    }
    if(animation3!=NULL)
    {
        delete animation3;
        animation3=NULL;
    }
}
void TallNut::todo()
{
    if(HP>500&&HP<1000)
        setMovie(animation2);
    if(HP<=500)
        setMovie(animation3);
}

//CherryBomb
CherryBomb::CherryBomb(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=1500;
    setMovie(animation);
    animation->start();
    setParent(lawn);
    show();
    raise();
    Counter=0;
    Speed=10;
}
CherryBomb::~CherryBomb()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=NULL;
    }
}
void CherryBomb::todo()
{
    if(Counter==Speed){
        Zombie* zombie;
        foreach (zombie, scene->zombieSet)
            if ((qAbs(zombie->x() - this->x() + zombie->offset + 50) < 140) && (qAbs(this->row - zombie->row) <= 1))
                zombie->hit(1200);
        Animation* boom = new Boom(scene);
        boom->setGeometry(this->x() - 60, this->y() - 50, 200, 150);
        scene->animationSet.append(boom);
        //audio->play();
        QSound::play(":/res/Boom.wav");
        present=false;
    }
    else
        Counter++;
}

//WallNut
WallNut::WallNut(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=1200;
    setMovie(animation1);
    animation1->start();
    animation2->start();
    animation3->start();
    setParent(lawn);
    show();
    raise();
}
WallNut::~WallNut()
{
    if(animation1!=NULL)
    {
        delete animation1;
        animation1=NULL;
    }
    if(animation2!=NULL)
    {
        delete animation2;
        animation2=NULL;
    }
    if(animation3!=NULL)
    {
        delete animation3;
        animation3=NULL;
    }
}
void WallNut::todo()
{
    if(HP>400&&HP<800)
        setMovie(animation2);
    if(HP<=400)
        setMovie(animation3);
}

//SnowPea
SnowPea::SnowPea(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=200;
    setMovie(animation);
    animation->start();
    setParent(lawn);
    show();
    raise();
    shootCounter=0;
    shootSpeed=100;
}
SnowPea::~SnowPea()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=NULL;
    }
}
void SnowPea::todo()
{
    if(shootCounter==shootSpeed){
        shootCounter=0;
        if(!scene->canFire[this->row])
            return;
        IcePea*newBullet=new IcePea(scene,scene);
        newBullet->setGeometry(this->x()+20,this->y()+5,50,70);
        newBullet->setRow(this->row);
        scene->bulletSet.append(newBullet);
        //audio->play();
        QSound::play(":/res/PeaHit.wav");
    }
    else
        shootCounter++;
}

//PatatoMine
PotatoMine::PotatoMine(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=1500;
    setMovie(animation1);
    animation1->start();
    animation2->start();
    setParent(lawn);
    show();
    raise();
    Counter=0;
    Speed=500;
}
PotatoMine::~PotatoMine()
{
    if(animation1!=NULL)
    {
        delete animation1;
        animation1=NULL;
    }
    if(animation2!=NULL)
    {
        delete animation2;
        animation2=NULL;
    }
}
void PotatoMine::todo()
{
    if(Counter==Speed){
        this->setMovie(animation2);
        Zombie* zombie;
        foreach (zombie, scene->zombieSet)
        {
            if ((qAbs(zombie->x() - this->x() + zombie->offset + 50) < 40) && ((this->row) == (zombie->row)))
            {
                if (present)
                {
                    Animation* mashed = new Mashed(scene);
                    mashed->setGeometry(this->x() - 40, this->y(), 150, 100);
                    scene->animationSet.append(mashed);
                    QSound::play(":/res/Potato.wav");
                }
                present = false;
                zombie->hit(2000);
            }
        }
    }
    else
        Counter++;
}

//Squash
Squash::Squash(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=1500;
    setMovie(animation);
    animation->start();
    setParent(lawn);
    show();
    raise();
}
Squash::~Squash()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=NULL;
    }
}
void Squash::todo()
{
    Zombie* zombie;
    foreach (zombie, scene->zombieSet)
    {
        if ((qAbs(zombie->x() - this->x() + zombie->offset + 50) < 40) && ((this->row) == (zombie->row)))
        {
            if (present)
            {
                Animation* dashed = new Dashed(scene);
                dashed->setGeometry(this->x() - 40, this->y(), 150, 100);
                scene->animationSet.append(dashed);
                //QSound::play(":/Sounds/rc/Potato.wav");
            }
            present = false;
            zombie->hit(2000);
        }
    }
}

//FumeShroom
FumeShroom::FumeShroom(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=400;
    setMovie(animation);
    animation->start();
    setParent(lawn);
    show();
    raise();
    shootCounter=0;
    shootSpeed=100;
}
FumeShroom::~FumeShroom()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=NULL;
    }
}
void FumeShroom::todo()
{
    if(shootCounter==shootSpeed){
        shootCounter=0;
        if(!scene->canFire[this->row])
            return;
        Zombie* zombie;
        foreach (zombie, scene->zombieSet)
            if ((qAbs(zombie->x() - this->x() + zombie->offset + 50) < 300) && ((this->row) == (zombie->row)))
                if (present)
                {
                    Mush* mush = new Mush(scene,scene);
                    mush->setGeometry(this->x() - 40, this->y(), 150, 100);
                    mush->setRow(this->row);
                    scene->bulletSet.append(mush);
                    //QSound::play(":/Sounds/rc/Potato.wav");
                }
        //audio->play();
    }
    else
        shootCounter++;
}

//PuffShroom
PuffShroom::PuffShroom(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=200;
    setMovie(animation);
    animation->start();
    setParent(lawn);
    show();
    raise();
    shootCounter=0;
    shootSpeed=100;
}
PuffShroom::~PuffShroom()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=NULL;
    }
}
void PuffShroom::todo()
{
    if(shootCounter==shootSpeed){
        shootCounter=0;
        if(!scene->canFire[this->row])
            return;
        Zombie* zombie;
        foreach (zombie, scene->zombieSet)
            if ((qAbs(zombie->x() - this->x() + zombie->offset + 50) < 300) && ((this->row) == (zombie->row)))
                if (present)
                {
                    pMush* pmush = new pMush(scene,scene);
                    pmush->setGeometry(this->x() - 40, this->y(), 150, 100);
                    pmush->setRow(this->row);
                    scene->bulletSet.append(pmush);
                    //QSound::play(":/Sounds/rc/Potato.wav");
                }
        //audio->play();
    }
    else
        shootCounter++;
}

//SunShroom
SunShroom::SunShroom(lawnScene*lawn,QWidget *parent):Plants(lawn,parent)
{
    HP=200;
    setMovie(animation1);
    animation1->start();
    animation2->start();
    setParent(lawn);
    show();
    raise();
    Counter=0;
    Speed=100;
    growCounter=0;
    growSpeed=500;
}
SunShroom::~SunShroom()
{
    if(animation1!=NULL)
    {
        delete animation1;
        animation1=NULL;
    }
    if(animation2!=NULL)
    {
        delete animation2;
        animation2=NULL;
    }
}
void SunShroom::todo()
{
    if(Counter==Speed){
        Counter=0;
        Sun*newSun=new Sun(scene);
        newSun->setGeometry(this->x()+20,this->y()+10-(qrand()%5),76,75);
        newSun->setAltitude(this->x()+40);
        scene->sunSet.append(newSun);
        //audio->play();
    }
    else
        Counter++;
}
