#ifndef CARD_H
#define CARD_H

#include <QLabel>
#include <QMovie>
#include <QSound>
#include <QMouseEvent>

//#include "zObject.h"
//#include "lawnscene.h"
class lawnScene;
class darkScene;

class Card : public QLabel
{
public:
    Card(lawnScene*lawn,QWidget* parent = nullptr);
    Card(darkScene*dark,QWidget* parent = nullptr);
    ~Card();
    int plantIndex;
    int sunPoint = 50;
    int frame_max = 1, frame = 1;
    lawnScene*scene=NULL;
    darkScene*scene2=NULL;
    virtual void todo();
    void setIndex(int index);
protected:
    bool present=true;
    void mousePressEvent(QMouseEvent* event);
};

class selectedCard : public Card
{
public:
    selectedCard(lawnScene*lawn,Card* type,QWidget* parent = nullptr);
    selectedCard(darkScene*dark,Card* type,QWidget* parent = nullptr);
    ~selectedCard();
private:
    QMovie* animation = nullptr;
};

class SunFlowerCard : public Card
{
public:
    SunFlowerCard(lawnScene*lawn,QWidget* parent = nullptr);
    SunFlowerCard(darkScene*dark,QWidget* parent = nullptr);
    ~SunFlowerCard();
private:
    QMovie* animation = new QMovie(":/res/plant/flowercard.png");
};

class PeaShooterCard : public Card
{
public:
    PeaShooterCard(lawnScene*lawn,QWidget* parent = nullptr);
    PeaShooterCard(darkScene*dark,QWidget* parent = nullptr);
    ~PeaShooterCard();
private:
    QMovie* animation = new QMovie(":/res/plant/Peashootercard.gif");
};

class WallNutCard : public Card
{
public:
    WallNutCard(lawnScene*lawn,QWidget* parent = nullptr);
    WallNutCard(darkScene*dark,QWidget* parent = nullptr);
    ~WallNutCard();
private:
    QMovie* animation = new QMovie(":/res/plant/WallNutCard.gif");
};

class RepeaterCard: public Card
{
public:
    RepeaterCard(lawnScene*lawn,QWidget* parent = nullptr);
    RepeaterCard(darkScene*dark,QWidget* parent = nullptr);
    ~RepeaterCard();
private:
    QMovie* animation = new QMovie(":/res/plant/repeater.png");
};

class PotatoMineCard: public Card
{
public:
    PotatoMineCard(lawnScene*lawn,QWidget* parent = nullptr);
    PotatoMineCard(darkScene*dark,QWidget* parent = nullptr);
    ~PotatoMineCard();
private:
    QMovie* animation = new QMovie(":/res/plant/potatocard.gif");
};

class CherryBombCard: public Card
{
public:
    CherryBombCard(lawnScene*lawn,QWidget* parent = nullptr);
    CherryBombCard(darkScene*dark,QWidget* parent = nullptr);
    ~CherryBombCard();
private:
    QMovie* animation = new QMovie(":/res/plant/cherrybomb.png");
};

class SnowPeaCard: public Card
{
public:
    SnowPeaCard(lawnScene*lawn,QWidget* parent = nullptr);
    SnowPeaCard(darkScene*dark,QWidget* parent = nullptr);
    ~SnowPeaCard();
private:
    QMovie* animation = new QMovie(":/res/plant/snowpea.png");
};

class MushroomCard : public Card
{
public:
    MushroomCard(lawnScene*lawn,QWidget* parent = nullptr);
    MushroomCard(darkScene*dark,QWidget* parent = nullptr);
    ~MushroomCard();
private:
    QMovie* animation = new QMovie(":/res/plant/puffshroom.png");
};

class Shovel : public Card
{
public:
    Shovel(lawnScene*lawn,QWidget* parent = nullptr);
    Shovel(darkScene*dark,QWidget* parent = nullptr);
    ~Shovel();
private:
    QMovie* animation = new QMovie(":/res/Shovel.png");
};

#endif // CARD_H
