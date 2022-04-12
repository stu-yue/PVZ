#include "zombie.h"
#include <QMovie>
#include "animation.h"
#include "plants.h"
#include "lawnscene.h"
#include <QDebug>

Zombie::Zombie(lawnScene*lawn,QWidget *parent) : QLabel(parent)
{
    scene=lawn;
}
Zombie::Zombie(darkScene*dark,QWidget *parent) : QLabel(parent)
{
    scene2=dark;
}
void Zombie::todo()
{

}
void Zombie::hit(int damage, bool silence)
{

}
void Zombie::ice()
{

}
bool Zombie::Present()
{
    return present;
}

NormalZombie::NormalZombie(lawnScene*lawn,QWidget *parent, int type) : Zombie(lawn,parent)
{
    //qDebug()<<type;
    this->attackMovie = new QMovie(":/res/ZombieAttack.gif");
    switch (qrand() % 2)
    {
    case 0:
        this->walkMovie = new QMovie(":/res/Zombie.gif");
        break;
    case 1:
        this->walkMovie = new QMovie(":/res/Zombie_2.gif");
        break;
    }
    switch (type)
    {
    //Common Zombie
    case 0:
        this->prop = false;
        this->iron = false;
        break;
    //Flag Zombie
    case 1:
        this->prop = false;
        this->iron = false;
        this->offset = 20;
        delete this->walkMovie;
        delete this->attackMovie;
        this->walkMovie = new QMovie(":/res/ZombieFlag.gif");
        this->attackMovie = new QMovie(":/res/ZombieFlagAttack.gif");
        break;
    //Cone Zombie
    case 2:
        this->prop = true;
        this->iron = false;
        this->prop_strength = 200;
        this->propWalkMovie = new QMovie(":/res/ZombieCone.gif");
        this->propAttackMovie = new QMovie(":/res/ZombieConeAttack.gif");
        this->offset = 20;
        break;
    //Bucket Zombie
    case 3:
        this->prop = true;
        this->iron = true;
        this->prop_strength = 400;
        this->propWalkMovie = new QMovie(":/res/ZombieBucket.gif");
        this->propAttackMovie = new QMovie(":/res/ZombieBucketAttack.gif");
        break;
    //Shield Zombie
    case 4:
        this->prop = true;
        this->iron = true;
        this->hasShield = true;
        this->prop_strength = 400;
        this->propWalkMovie = new QMovie(":/res/ZombieShield.gif");
        this->propAttackMovie = new QMovie(":/res/ZombieShieldAttack.gif");
        break;
    default:
        this->prop = false;
        this->iron = false;
    }
    this->speed = 0.5;//0.5;
    this->HP = 200;
    this->xpos = 910;
    setParent(parent);
    raise();
    if (this->prop)
    {
        this->setMovie(this->propWalkMovie);
        this->walkMovie->start();
        this->propWalkMovie->start();
        this->attackMovie->start();
        this->propAttackMovie->start();
    }
    else
    {
        this->setMovie(this->walkMovie);
        this->walkMovie->start();
        this->attackMovie->start();
    }
    qDebug()<<"zombie";
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
    show();
}

NormalZombie::NormalZombie(darkScene*dark,QWidget *parent, int type) : Zombie(dark,parent)
{
    this->attackMovie = new QMovie(":/res/ZombieAttack.gif");
    switch (type)
    {
    //Common Zombie
    case 0:
        this->prop = false;
        this->iron = false;
        switch (qrand() % 2)
        {
        case 0:
            this->walkMovie = new QMovie(":/res/Zombie.gif");
            break;
        case 1:
            this->walkMovie = new QMovie(":/res/Zombie_2.gif");
            break;
        }
        break;
    //Flag Zombie
    case 1:
        this->prop = false;
        this->iron = false;
        this->offset = 20;
        delete this->walkMovie;
        delete this->attackMovie;
        this->walkMovie = new QMovie(":/res/ZombieFlag.gif");
        this->attackMovie = new QMovie(":/res/ZombieFlagAttack.gif");
        break;
    //Cone Zombie
    case 2:
        this->prop = true;
        this->iron = false;
        this->prop_strength = 200;
        this->propWalkMovie = new QMovie(":/res/ZombieCone.gif");
        this->propAttackMovie = new QMovie(":/res/ZombieConeAttack.gif");
        this->offset = 20;
        break;
    //Bucket Zombie
    case 3:
        this->prop = true;
        this->iron = true;
        this->prop_strength = 400;
        this->propWalkMovie = new QMovie(":/res/ZombieBucket.gif");
        this->propAttackMovie = new QMovie(":/res/ZombieBucketAttack.gif");
        break;
    //Shield Zombie
    case 4:
        this->prop = true;
        this->iron = true;
        this->hasShield = true;
        this->prop_strength = 400;
        this->propWalkMovie = new QMovie(":/res/ZombieShield.gif");
        this->propAttackMovie = new QMovie(":/res/ZombieShieldAttack.gif");
        break;
    }
    this->speed = 1;//0.5;
    this->HP = 200;
    this->xpos = 910;
    setParent(parent);
    raise();
    if (this->prop)
    {
        this->setMovie(this->propWalkMovie);
        this->walkMovie->start();
        this->propWalkMovie->start();
        this->attackMovie->start();
        this->propAttackMovie->start();
    }
    else
    {
        this->setMovie(this->walkMovie);
        this->walkMovie->start();
        this->attackMovie->start();
    }
    qDebug()<<"zombie";
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
    show();
}

NormalZombie::~NormalZombie()
{
    if(this->walkMovie!=NULL)delete (this->walkMovie);
    if(this->attackMovie!=NULL)delete (this->attackMovie);
    if(this->propWalkMovie!=NULL)delete (this->propWalkMovie);
    if(this->propAttackMovie!=NULL)delete (this->propAttackMovie);
}

void NormalZombie::todo()
{
    this->raise();
    Plants* plant;
    foreach (plant, this->scene->plantSet)
    {
        if ((qAbs(plant->x() - this->x() - 55 - this->offset) < 40) && ((this->row) == (plant->getRow())) && present)
        {
            if (this->eatFrame <= 0)
            {
                QSound::play(":/res/Eat.wav");
                this->eatFrame = 20;
            }
            this->eatFrame --;
            if (this->prop)
            {
                this->setMovie(this->propAttackMovie);
            }
            else
            {
                this->setMovie(this->attackMovie);
            }
            plant->hit(1);
            return;
        }
    }
    if (this->prop)
    {
        this->setMovie(this->propWalkMovie);
    }
    else
    {
        this->setMovie(this->walkMovie);
    }
    this->xpos -= this->speed;
    this->move(this->xpos, this->y());
    //setGeometry(this->xpos,this->y(),150,70);
    //qDebug()<<"walk";
}

void NormalZombie::hit(int damage, bool silence)
{
    if (damage >= 200&&damage<15000)
    {
        qDebug()<<"2";
        this->present = false;
        Animation* death_anim = new BurnDie(scene);
        death_anim->setGeometry(this->x() - 30, this->y() + 25, 180, 150);
        this->scene->animationSet.append(death_anim);
        if (!(this->propWalkMovie == nullptr))
        {
            delete this->propWalkMovie;
            propWalkMovie=nullptr;
        }
        if (!(this->propAttackMovie == nullptr))
        {
            delete this->propAttackMovie;
            propAttackMovie=nullptr;
        }
        return;
    }
    if (!(silence))
    {
        if ((this->prop) && (this->iron))
        {
            QSound::play(":/res/ShieldHit.wav");
        }
        else
        {
            QSound::play(":/res/Pea.wav");
        }
    }
    if (this->prop&&damage<15000)
    {
        this->prop_strength -= damage;
        if (this->prop_strength <= 0)
        {
            this->prop = false;
            this->xpos += this->offset;
            this->todo();
            this->setMovie(this->walkMovie);
            this->walkMovie->start();
            delete this->propWalkMovie;
            delete this->propAttackMovie;
            this->propWalkMovie = nullptr;
            this->propAttackMovie = nullptr;
            this->hasShield = false;
        }
    }
    else
    {
        this->HP -= damage;
    }
    if (this->HP <= 0)
    {
        this->present = false;
        Animation* death_anim = new ZombieDie(scene);
        death_anim->setGeometry(this->x() - 30, this->y() + 25, 180, 150);
        this->scene->animationSet.append(death_anim);
        Animation* death_head = new ZombieHead(scene);
        death_head->setGeometry(this->x() + 50, this->y() + 25, 180, 200);
        this->scene->animationSet.append(death_head);
        if (!(this->propWalkMovie == nullptr))
        {
            delete this->propWalkMovie;
            propWalkMovie=nullptr;
        }
        if (!(this->propAttackMovie == nullptr))
        {
            delete this->propAttackMovie;
            propAttackMovie=nullptr;
        }
    }
}

void NormalZombie::ice()
{
    if ((!isIce) && (!hasShield))
    {
        this->isIce = true;
        this->speed /= 2;
        if (!(this->walkMovie == nullptr))
        {
            this->walkMovie->setSpeed(40);
        }
        if (!(this->attackMovie == nullptr))
        {
            this->attackMovie->setSpeed(40);
        }
        if (!(this->propWalkMovie == nullptr))
        {
            this->propWalkMovie->setSpeed(40);
        }
        if (!(this->propAttackMovie == nullptr))
        {
            this->propAttackMovie->setSpeed(40);
        }
    }
}

