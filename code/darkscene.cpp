#include "darkscene.h"
#include <QIcon>
#include <QPainter>
#include <QImage>
#include "mypushbutton.h"
#include <QTimer>
#include <QSound>
#include <QDebug>

int sunShine2=5500;

darkScene::~darkScene()
{
    //qDebug()<<"call destructor";
    while (!zombieSet.empty())
    {
        delete zombieSet[0];                 //delete QList
        zombieSet.removeAt(0);
    }
    while (!plantSet.empty())
    {
        delete plantSet[0];
        plantSet.removeAt(0);
    }
    while (!bulletSet.empty())
    {
        delete bulletSet[0];
        bulletSet.removeAt(0);
    }
    while (!animationSet.empty())
    {
        delete animationSet[0];
        animationSet.removeAt(0);
    }
    while (!sunSet.empty())
    {
        delete sunSet[0];
        sunSet.removeAt(0);
    }
    while (!cardSet.empty())
    {
        delete cardSet[0];
        cardSet.removeAt(0);
    }
    if (!(this->timer == nullptr))delete this->timer;
    if(sunNum!=NULL)delete sunNum;
    if(loseMovie!=NULL)delete loseMovie;
    if(selectedPlant!=NULL)delete selectedPlant;
    if(selectedPlantMovie!=NULL)delete selectedPlantMovie;
}


QPoint darkScene::getGridSize()
{
    if (this->rect.contains(this->grid))
    {
        //qDebug()<<"in";
        //qDebug()<<"r="<<(this->grid.y() - this->rect.top()) / this->gridSize.y()<<"c="<<(this->grid.x() - this->rect.left()) / this->gridSize.x();
        return QPoint((this->grid.x() - this->rect.left()) / this->gridSize.x(),
                      (this->grid.y() - this->rect.top()) / this->gridSize.y());
    }
    else
    {
        //qDebug()<<"out";
        //qDebug()<<"x="<<grid.x()<<"y="<<grid.y();
        return QPoint(-1, -1);
    }
}

void darkScene::mouseMoveEvent(QMouseEvent* event)
{
    grid = event->pos();
    if (this->currentCard != nullptr)
    {
        this->currentCard->move(grid + QPoint(-40, 1));
        this->currentCard->raise();
    }
    getGridSize();//
}

void darkScene::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"x="<<event->x()<<",y="<<event->y();
    QPoint grid = this->getGridSize();
    if (event->button() == Qt::LeftButton)
    {
        if ((grid.x() > -1) && (this->currentCard != nullptr))
        {
            for (int i = 0; i < plantSet.count(); i++)
            {
                if ((plantSet[i]->row == grid.y()) && (plantSet[i]->col == grid.x()) && this->currentCard->plantIndex > 0)
                {
                    //QSound::play(":/Sounds/rc/NotEnoughSun.wav");
                    qDebug()<<"emit";
                    return;
                }
            }
            this->currentCard->move(this->currentPos);
            //this->selectedPlant->move(this->currentPos);
            this->plantPlants(grid);
            QSound::play(":/res/Place.wav");
        }
    }
    else
    {
        if (this->currentCard != nullptr)
        {
            this->currentCard->move(this->currentPos);
        }
        if(currentCard!=nullptr)
            delete currentCard;
        this->currentCard = nullptr;
    }
}

void darkScene::plantPlants(QPoint grid)
{
    Plants* plant;
    switch (this->currentCard->plantIndex)
    {
    case 0:
        for (int i = 0; i < plantSet.count(); i++)
        {
            if ((plantSet[i]->row == grid.y()) && (plantSet[i]->col == grid.x()))
            {
                delete plantSet[i];
                plantSet.removeAt(i);
                this->currentCard->move(this->currentPos);
                if(currentCard!=nullptr)
                    delete currentCard;
                this->currentCard = nullptr;
                return;
            }
        }
        if(currentCard!=nullptr)
            delete currentCard;
        this->currentCard = nullptr;
        return;
        break;
//    case 1:
//        plant = new SunFlower(this);
//        break;
//    case 2:
//        plant = new PeaShooter(this);
//        break;
//    case 3:
//        plant = new WallNut(this);
//        break;
//    case 4:
//        plant = new RePeater(this);
//        break;
//    case 5:
//        plant = new PotatoMine(this);
//        break;
//    case 6:
//        plant = new CherryBomb(this);
//        break;
//    case 7:
//        plant = new SnowPea(this);
//        break;
//    case 8:
//        plant = new FumeShroom(this);
//        break;
//    case 9:
//        plant = new zMushroom(this);
//        break;
    }
    plant->setGeometry(rect.x() + 10 + gridSize.x() * grid.x(), rect.y() - 15 + gridSize.y() * grid.y(), 120, 100);
    plant->row = grid.y();
    plant->col = grid.x();
    this->plantSet.append(plant);
    sunShine2 -= this->currentCard->sunPoint;
    if(currentCard!=nullptr)
        delete currentCard;
    this->currentCard = nullptr;
}

//僵尸产生机制
void darkScene::createZombie()
{
    if (this->threat < 9001)
    {
        this->threat ++;
    }
    if (this->zombieSet.count() < (this->threat / 60))
    {
        if (this->threat < 3000)
        {
            this->putZombie(qrand() % 5, 0);
            this->putZombie(qrand() % 5, 0);
            this->putZombie(qrand() % 5, 0);
        }
        else
        {
            this->putZombie(qrand() % 5, qrand() % 5);
        }
    }
}

void darkScene::putZombie(int row, int type)
{
    Zombie* zombie;
    switch(type)
    {
    case 0:
        zombie = new NormalZombie(this,this, 0);
        break;
    case 1:
        zombie = new NormalZombie(this,this, 1);
        break;
    case 2:
        zombie = new NormalZombie(this,this, 2);
        break;
    case 3:
        zombie = new NormalZombie(this,this, 3);
        break;
    case 4:
        zombie = new NormalZombie(this,this, 4);
        break;
//    case 5:
//        zombie = new zPoleZombie(this);
//        break;
//    case 6:
//        zombie = new zNewsZombie(this);
//        break;
    }
    zombie->row = row;
    zombie->setGeometry(910, zombie->row * 100 - 25 + qrand() % 5, 340, 200);
    zombie->setParent(this);
    zombie->raise();
    this->zombieSet.append(zombie);
    qDebug()<<"1";
}


void darkScene::invadeOK()
{
    Zombie* zombie;
    foreach(zombie, zombieSet)
    {
        if (zombie->x() < 0)
        {
            this->currentCard = nullptr;
            while (!cardSet.empty())
            {
                delete cardSet[0];
                cardSet.removeAt(0);
            }
            //this->move(0, 0);
            //QSound::play(":/Sounds/rc/Lose.wav");
            QMovie*gameOver=new QMovie(":/res/ZombiesWon.png");
            loseMovie->setMovie(gameOver);
            gameOver->start();
            loseMovie->raise();
            loseMovie->setGeometry(200,0,600,600);
            lose=true;
            return;
        }
    }
}



















void darkScene::setUI()
{
    //configure basic information
    //set fixed size
    this->setFixedSize(900,600);
    //set window title
    this->setWindowTitle("Plants vs. Zombies");
    //set window icon
    this->setWindowIcon(QIcon(":/res/mainlogo.png"));
    //go back to mode select
    MyPushButton*backBtn=new MyPushButton(":/res/Leave.png");
    backBtn->setParent(this);
    backBtn->move(830,0);
    //back to menu
    connect(backBtn,&MyPushButton::clicked,[=](){
        backBtn->bouncing();
        backBtn->bounced();
        QSound::play(":/res/clicked.wav");
        QTimer::singleShot(300,this,[=](){
            this->hide();
            emit this->backToMenu();
        });
    });

    //card slot show
    QLabel*cardSlot= new QLabel(this);
    QMovie*pix=new QMovie(":/res/card_select.jpg");
    cardSlot->setMovie(pix);
    pix->start();
    cardSlot->setGeometry(20,0,446,87);
    //shovel slot show
    QLabel*shovelSlot= new QLabel(this);
    QMovie*pix2=new QMovie(":/res/shovel.jpg.png");
    shovelSlot->setMovie(pix2);
    pix2->start();
    shovelSlot->setGeometry(466,0,74,76);
    //sunShine count
    //QLabel*sunNum=new QLabel(this);
    sunNum->setText(QString::number(sunShine2));
    sunNum->setGeometry(10,55,100,50);
    sunNum->setFont(QFont("Consolas",10));
    sunNum->setAlignment(Qt::AlignHCenter);
    sunNum->show();
    sunNum->raise();

    Card *card = new SunFlowerCard(this);
    card->setIndex(1);
    cardSet.append(card);
    Card *card_2 = new PeaShooterCard(this);
    card_2->setIndex(2);
    cardSet.append(card_2);
    Card *card_3 = new WallNutCard(this);
    card_3->setIndex(3);
    cardSet.append(card_3);
    Card *card_4 = new RepeaterCard(this);
    card_4->setIndex(4);
    cardSet.append(card_4);
    Card *card_5 = new PotatoMineCard(this);
    card_5->setIndex(5);
    cardSet.append(card_5);
    Card *card_6 = new CherryBombCard(this);
    card_6->setIndex(6);
    cardSet.append(card_6);
    Card *card_7 = new SnowPeaCard(this);
    card_7->setIndex(7);
    cardSet.append(card_7);
    Card *shovel = new Shovel(this);
    shovel->setGeometry(460,0,80,80);
    cardSet.append(shovel);

    Car *car_1 = new Car(this,this);
    car_1->setGeometry(70,90,80,80);
    car_1->setRow(0);
    carSet.append(car_1);
    Car *car_2 = new Car(this,this);
    car_2->setGeometry(70,185,80,80);
    car_2->setRow(1);
    carSet.append(car_2);
    Car *car_3 = new Car(this,this);
    car_3->setGeometry(70,280,80,80);
    car_3->setRow(2);
    carSet.append(car_3);
    Car *car_4 = new Car(this,this);
    car_4->setGeometry(70,375,80,80);
    car_4->setRow(3);
    carSet.append(car_4);
    Car *car_5 = new Car(this,this);
    car_5->setGeometry(70,470,80,80);
    car_5->setRow(4);
    carSet.append(car_5);

    MyPushButton*pauseBtn=new MyPushButton(":/res/pause_2.png");
    pauseBtn->setParent(this);
    pauseBtn->move(630,0);\
    connect(pauseBtn,&MyPushButton::clicked,[=](){
        pauseBtn->bouncing();
        pauseBtn->bounced();
        QSound::play(":/res/clicked.wav");
        QTimer::singleShot(300,this,[=](){
            still?still=false:still=true;
        });
    });
}

darkScene::darkScene(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    //configure basic information
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &darkScene::onTimer);
    timer->start(20);
    setUI();
}

void darkScene::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //QPixmap pix(":/res/background1.jpg");
    QImage backImg(":/res/background2.jpg");
    painter.drawImage(0,0,backImg,120,0);
}

void darkScene::remove()
{
    int p = 0;
    //plant
    for(p = 0; p < plantSet.count(); p++)
    {
        if (!(plantSet[p]->Present()))
        {
            delete (plantSet[p]);
            plantSet.removeAt(p);
        }
    }
    //zombie
    for (int i = 0; i < 5; i++)
    {
        this->canFire[i] = false;
    }
    for(p=0;p<zombieSet.count();p++)
    {
        if (!(zombieSet[p]->Present()))
        {
            delete (zombieSet[p]);
            zombieSet.removeAt(p);
        }
        else if(zombieSet[p]->x()<(LAWN_W-50))
        {
            this->canFire[zombieSet[p]->row] = true;
            //qDebug()<<zombieSet[p]->x();
        }
    }
    //bullet
    for(p = 0; p < bulletSet.count(); p++)
    {
        if (!(bulletSet[p]->Present()))
        {
            delete (bulletSet[p]);
            bulletSet.removeAt(p);
        }
    }
    //animation
    for(p = 0; p < animationSet.count(); p++)
    {
        if (!(animationSet[p]->Present()))
        {
            delete (animationSet[p]);
            animationSet.removeAt(p);
        }
    }
    //sun
    for(p = 0; p < sunSet.count(); p++)
    {
        if (!(sunSet[p]->Present()))
        {
            delete (sunSet[p]);
            sunSet.removeAt(p);
        }
    }
    //car
    for(p = 0; p < carSet.count(); p++)
    {
        if (!(carSet[p]->Present()))
        {
            delete (carSet[p]);
            carSet.removeAt(p);
        }
    }
}

void darkScene::todo()
{
    Zombie* i;
    foreach(i, zombieSet)
    {
        i->todo();
    }
    Plants*j;
    foreach(j, plantSet)
    {
        j->todo();
    }
    Bullet*k;
    foreach(k, bulletSet)
    {
        k->todo();
    }
    Animation*l;
    foreach(l, animationSet)
    {
        l->todo();
    }
    Sun*m;
    foreach(m, sunSet)
    {
        m->todo();
    }
    Car*n;
    foreach(n, carSet)
    {
        n->todo();
    }
    //qDebug()<<carSet.count();
}

void darkScene::onTimer()
{
    if(!lose&&still)
    {
        remove();
        todo();
        //QLabel*sunNum=new QLabel(this);
        sunNum->setText(QString::number(sunShine2));
        sunNum->raise();
        sunNum->show();
        createZombie();
        if(counter==100)
        {
            Sun* sun = new Sun(this);
            sunSet.append(sun);
            counter=0;
        }
        else
            counter++;
        //invadeOK();
    }
}
