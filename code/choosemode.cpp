#include "choosemode.h"
#include <QIcon>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QMovie>
#include <QPushButton>
#include <QDebug>
#include <QSound>

ChooseMode::~ChooseMode()
{
    if(lawn!=NULL)
        delete lawn;
    if(dark!=NULL)
        delete dark;
}

ChooseMode::ChooseMode(QWidget *parent) : QWidget(parent)
{
    //configure basic information
    //set fixed size
    this->setFixedSize(900,600);
    //set window title
    this->setWindowTitle("Plants vs. Zombies");
    //set window icon
    this->setWindowIcon(QIcon(":/res/mainlogo.png"));

    //set title
    QLabel*title=new QLabel(this);
    title->setText("Select Mode");
    title->setGeometry(355,6,300,100);
    title->setFont(QFont("Consolas",12));
    title->show();
    //back button
    MyPushButton*backBtn=new MyPushButton(":/res/Leave.png");
    backBtn->setParent(this);
    backBtn->move(788,507);

    //day scene
    QLabel*dayBtn= new QLabel(this);
    QMovie*daypix=new QMovie(":/res/zombatar_background_crazydave.png");
    dayBtn->setMovie(daypix);
    daypix->setScaledSize(QSize(375,210));
    daypix->start();
    dayBtn->setGeometry(47,145,400,300);
    QPushButton*chooseDay=new QPushButton(this);
    chooseDay->setFixedSize(375,210);
    chooseDay->move(47,190);
    chooseDay->setStyleSheet("background:transparent");
    //dark scene
    QLabel*darkBtn= new QLabel(this);
    QMovie*darkpix=new QMovie(":/res/zombatar_background_menu.png");
    darkBtn->setMovie(darkpix);
    darkpix->setScaledSize(QSize(350,200));
    darkpix->start();
    darkBtn->setGeometry(490,150,400,300);
    QPushButton*chooseDark=new QPushButton(this);
    chooseDark->setFixedSize(350,205);
    chooseDark->move(490,195);
    chooseDark->setStyleSheet("background:transparent");
    //QSound*music=new QSound(":/res/music.mp3",this);
    //QSound::play(":/res/music.mp3");

    //back to menu
    connect(backBtn,&MyPushButton::clicked,[=](){
        backBtn->bouncing();
        backBtn->bounced();
        QSound::play(":/res/clicked.wav");
        QTimer::singleShot(500,this,[=](){
            this->hide();
            emit this->backToMenu();
        });
    });

    //instantiate lawn
    lawn=new lawnScene;
    //instantiate dark
    dark=new darkScene;

    //go to lawn
    connect(chooseDay,&QPushButton::clicked,[=](){
        //qDebug()<<"clicked";
        QSound::play(":/res/clicked.wav");
        QTimer::singleShot(100,this,[=](){
            //hide main scene
            this->hide();
            //show the select mode scene
            lawn->show();
            lawn->still=true;
        });
    });
    //go back from lawn
    connect(lawn,&lawnScene::backToMenu,[=](){
        this->show();
    });

    //go to dark
    connect(chooseDark,&QPushButton::clicked,[=](){
        //qDebug()<<"clicked";
        QSound::play(":/res/clicked.wav");
        QTimer::singleShot(100,this,[=](){
            //hide main scene
            this->hide();
            //show the select mode scene
            dark->show();
            //dark->still=true;
        });
    });
    //go back from dark
    connect(dark,&darkScene::backToMenu,[=](){
        this->show();
    });

}

void ChooseMode::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix(":/res/Title.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
