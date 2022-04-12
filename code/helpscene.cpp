#include "helpscene.h"
#include <QPainter>
#include <QIcon>
#include <QLabel>
#include<QMovie>
#include "mypushbutton.h"
#include <QTimer>
#include <QSound>

helpScene::helpScene(QWidget *parent) : QWidget(parent)
{
    //configure basic information
    //set fixed size
    this->setFixedSize(900,600);
    //set window title
    this->setWindowTitle("Plants vs. Zombies");
    //set window icon
    this->setWindowIcon(QIcon(":/res/mainlogo.png"));

    //Tip
    QLabel*tip= new QLabel(this);
    QMovie*tipPix=new QMovie(":/res/Help.png");
    tip->setMovie(tipPix);
    tipPix->setScaledSize(QSize(500,400));
    tipPix->start();
    tip->setGeometry(207,5,600,500);

    //
    MyPushButton*backBtn2=new MyPushButton(":/res/helpback1.jpg",":/res/helpback2.jpg");
    backBtn2->setParent(this);
    backBtn2->move(380,500);

    //back to menu
    connect(backBtn2,&MyPushButton::clicked,[=](){
        backBtn2->bouncing();
        backBtn2->bounced();
        QSound::play(":/res/clicked.wav");
        QTimer::singleShot(300,this,[=](){
            this->hide();
            emit this->backToMenu();
        });
    });
}

void helpScene::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix(":/res/helpbackground.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
