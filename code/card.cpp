#include "card.h"
#include "lawnscene.h"
#include "darkscene.h"
#include <QDebug>
extern int sunShine;
extern int sunShine2;

Card::Card(lawnScene*lawn,QWidget* parent) : QLabel(parent)
{
    this->setCursor(Qt::PointingHandCursor);
    this->setParent(lawn);
    this->show();
    this->raise();
    scene=lawn;
}

Card::Card(darkScene*dark,QWidget* parent) : QLabel(parent)
{
    this->setCursor(Qt::PointingHandCursor);
    this->setParent(dark);
    this->show();
    this->raise();
    scene2=dark;
}

Card::~Card()
{

}

void Card::todo()
{
    this->raise();
}

void Card::setIndex(int index)
{
    setGeometry(46+52 * index, 8, 50, 70);
}

void Card::mousePressEvent(QMouseEvent* event)
{
    if(scene!=NULL)
    {
        if (scene->currentCard != nullptr)
        {
            return;
        }
        if (event->button() == Qt::LeftButton)
        {
            if (sunShine < sunPoint)
            {
                //QSound::play(":/Sounds/rc/NotEnoughSun.wav");
                scene->currentCard = nullptr;
                return;
            }
            QSound::play(":/res/Place.wav");
            scene->currentPos = this->pos();
            qDebug()<<plantIndex;
            qDebug()<<"x="<<pos().x()<<"y="<<pos().y();
            if(plantIndex>0)
                scene->currentCard = new selectedCard(scene,scene->cardSet[plantIndex-1]);
            else
                scene->currentCard = new selectedCard(scene,scene->cardSet[7]);
            qDebug()<<plantIndex;
            scene->currentCard->setGeometry(QRect(this->pos().x(),this->pos().y(),100,100));
            qDebug()<<plantIndex;
        }
        else
            return;
    }
    else if(scene2!=NULL)
    {
        if (scene2->currentCard != nullptr)
        {
            return;
        }
        if (event->button() == Qt::LeftButton)
        {
            if (sunShine2 < sunPoint)
            {
                //QSound::play(":/Sounds/rc/NotEnoughSun.wav");
                scene2->currentCard = nullptr;
                return;
            }
            QSound::play(":/res/Place.wav");
            scene2->currentPos = this->pos();
            qDebug()<<plantIndex;
            qDebug()<<"x="<<pos().x()<<"y="<<pos().y();
            if(plantIndex>0)
                scene2->currentCard = new selectedCard(scene2,scene2->cardSet[plantIndex-1]);
            else if(plantIndex==0)
                scene2->currentCard = new selectedCard(scene2,scene2->cardSet[7]);
            qDebug()<<plantIndex;
            scene2->currentCard->setGeometry(QRect(this->pos().x(),this->pos().y(),100,100));
            qDebug()<<plantIndex;
        }
        else
            return;
    }
}

//selectedCard
selectedCard::selectedCard(lawnScene*lawn,Card* type,QWidget* parent):Card(lawn,parent)
{
    //qDebug()<<type->plantIndex;
    switch(type->plantIndex)
    {
    case 0:animation=new QMovie(":/res/Shovel.png");break;
    case 1:animation=new QMovie(":/res/plant/sunflower.Png");break;
    case 2:animation=new QMovie(":/res/plant/peashooter.Png");break;
    case 3:animation=new QMovie(":/res/plant/WallNut.gif");break;
    case 4:animation=new QMovie(":/res/plant/repeater_.Png");break;
    case 5:animation=new QMovie(":/res/plant/PotatoMine.gif");break;
    case 6:animation=new QMovie(":/res/plant/cherry_.Png");break;
    case 7:animation=new QMovie(":/res/plant/IcePeaShooter.gif");break;
    //default:animation=new QMovie(":/res/Shovel.png");break;
    }
    setMovie(animation);
    animation->start();
    setParent(lawn);
    plantIndex=type->plantIndex;
    sunPoint=type->sunPoint;
    raise();
    //qDebug()<<"constructor";
}

selectedCard::selectedCard(darkScene*dark,Card* type,QWidget* parent):Card(dark,parent)
{
    //qDebug()<<type->plantIndex;
    switch(type->plantIndex)
    {
    case 0:animation=new QMovie(":/res/Shovel.png");break;
    case 1:animation=new QMovie(":/res/plant/sunflower.Png");break;
    case 2:animation=new QMovie(":/res/plant/peashooter.Png");break;
    case 3:animation=new QMovie(":/res/plant/WallNut.gif");break;
    case 4:animation=new QMovie(":/res/plant/repeater_.Png");break;
    case 5:animation=new QMovie(":/res/plant/PotatoMine.gif");break;
    case 6:animation=new QMovie(":/res/plant/cherry_.Png");break;
    case 7:animation=new QMovie(":/res/plant/IcePeaShooter.gif");break;
    //default:animation=new QMovie(":/res/Shovel.png");break;
    }
    setMovie(animation);
    animation->start();
    setParent(dark);
    plantIndex=type->plantIndex;
    sunPoint=type->sunPoint;
    raise();
    //qDebug()<<"constructor";
}

selectedCard::~selectedCard()
{
    if(animation!=NULL)
    {
        delete animation;
        animation=nullptr;
        qDebug()<<"destructor animation";
     }
}

//SunFlowerCard
SunFlowerCard::SunFlowerCard(lawnScene*lawn,QWidget* parent):Card(lawn,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=1;
    sunPoint=50;
    setParent(lawn);
}
SunFlowerCard::SunFlowerCard(darkScene*dark,QWidget* parent):Card(dark,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=1;
    sunPoint=50;
    setParent(dark);
}
SunFlowerCard::~SunFlowerCard()
{
    delete animation;
}

//PeaShooterCard
PeaShooterCard::PeaShooterCard(lawnScene*lawn,QWidget* parent):Card(lawn,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=2;
    sunPoint=100;
}
PeaShooterCard::PeaShooterCard(darkScene*dark,QWidget* parent):Card(dark,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=2;
    sunPoint=100;
}
PeaShooterCard::~PeaShooterCard()
{
    delete animation;
}

//WallNutCard
WallNutCard::WallNutCard(lawnScene*lawn,QWidget* parent):Card(lawn,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=3;
    sunPoint=50;
}
WallNutCard::WallNutCard(darkScene*dark,QWidget* parent):Card(dark,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=3;
    sunPoint=50;
}
WallNutCard::~WallNutCard()
{
    delete animation;
}

//RepeaterCard
RepeaterCard::RepeaterCard(lawnScene*lawn,QWidget* parent):Card(lawn,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=4;
    sunPoint=200;
}
RepeaterCard::RepeaterCard(darkScene*dark,QWidget* parent):Card(dark,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=4;
    sunPoint=200;
}
RepeaterCard::~RepeaterCard()
{
    delete animation;
}

//PotatoMineCard
PotatoMineCard::PotatoMineCard(lawnScene*lawn,QWidget* parent):Card(lawn,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=5;
    sunPoint=25;
}
PotatoMineCard::PotatoMineCard(darkScene*dark,QWidget* parent):Card(dark,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=5;
    sunPoint=25;
}
PotatoMineCard::~PotatoMineCard()
{
    delete animation;
}

//CherryBombCard
CherryBombCard::CherryBombCard(lawnScene*lawn,QWidget* parent):Card(lawn,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=6;
    sunPoint=150;
}
CherryBombCard::CherryBombCard(darkScene*dark,QWidget* parent):Card(dark,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=6;
    sunPoint=150;
}
CherryBombCard::~CherryBombCard()
{
    delete animation;
}

//SnowPeaCard
SnowPeaCard::SnowPeaCard(lawnScene*lawn,QWidget* parent):Card(lawn,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=7;
    sunPoint=175;
}
SnowPeaCard::SnowPeaCard(darkScene*dark,QWidget* parent):Card(dark,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=7;
    sunPoint=175;
}
SnowPeaCard::~SnowPeaCard()
{
    delete animation;
}

//MushroomCard
MushroomCard::MushroomCard(lawnScene*lawn,QWidget* parent):Card(lawn,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=8;
    sunPoint=75;
}
MushroomCard::MushroomCard(darkScene*dark,QWidget* parent):Card(dark,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=100;
    frame=100;
    plantIndex=8;
    sunPoint=75;
}
MushroomCard::~MushroomCard()
{
    delete animation;
}

//Shovel
Shovel::Shovel(lawnScene*lawn,QWidget* parent):Card(lawn,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=1;
    frame=0;
    plantIndex=0;
    sunPoint=0;
}
Shovel::Shovel(darkScene*dark,QWidget* parent):Card(dark,parent)
{
    setMovie(animation);
    animation->start();
    //frontText->setText("50");
    frame_max=1;
    frame=0;
    plantIndex=0;
    sunPoint=0;
}
Shovel::~Shovel()
{
    delete animation;
}

