#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QIcon>
#include <QPainter>
#include <mypushbutton.h>
#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //set fixed size
    this->setFixedSize(900,600);
    //set window title
    this->setWindowTitle("Plants vs. Zombies");
    //set window icon
    this->setWindowIcon(QIcon(":/res/mainlogo.png"));

    //creat start button
    MyPushButton*startBtn=new MyPushButton(":/res/button4.png",":/res/button5.png");
    startBtn->setParent(this);
    startBtn->move(470,70);
    //creat opt button
    MyPushButton*optBtn=new MyPushButton(":/res/737710798054372194.png",":/res/788903915979209709.png");
    optBtn->setParent(this);
    optBtn->move(645,485);
    //creat help button
    MyPushButton*helpBtn=new MyPushButton(":/res/823249062371359778.png",":/res/852826060440591248.png");
    helpBtn->setParent(this);
    helpBtn->move(708,507);
    //creat quit button
    MyPushButton*quitBtn=new MyPushButton(":/res/766833144404674037.png",":/res/294010253395912388.png");
    quitBtn->setParent(this);
    quitBtn->move(790,500);

    //instantiate the select mode scenario
    chooseScene=new ChooseMode;
    //instantiate help scenario
    helpInterface=new helpScene;
    //go to mode select
    connect(startBtn,&MyPushButton::clicked,[=](){
        //qDebug()<<"点击了";
        startBtn->bouncing();
        startBtn->bounced();
        QSound::play(":/res/clicked.wav");
        //go to mode select interface
        //delay goto mode select interface
        QTimer::singleShot(500,this,[=](){
            //hide main scene
            this->hide();
            //show the select mode scene
            chooseScene->show();
        });

    });
    //go back from mode select
    connect(chooseScene,&ChooseMode::backToMenu,[=](){
        this->show();
    });

    connect(optBtn,&MyPushButton::clicked,[=](){
        qDebug()<<"点击了";
        optBtn->bouncing();
        optBtn->bounced();
        QSound::play(":/res/clicked.wav");
    });
    //go to help
    connect(helpBtn,&MyPushButton::clicked,[=](){
        //qDebug()<<"点击了";
        helpBtn->bouncing();
        helpBtn->bounced();
        QSound::play(":/res/clicked.wav");
        QTimer::singleShot(500,this,[=](){
            //hide main scene
            this->hide();
            //show the select mode scene
            helpInterface->show();
        });
    });
    //go back from help
    connect(helpInterface,&helpScene::backToMenu,[=](){
        this->show();
    });
    //go to quit
    connect(quitBtn,&MyPushButton::clicked,[=](){
        //qDebug()<<"点击了";
        quitBtn->bouncing();
        quitBtn->bounced();
        QSound::play(":/res/clicked.wav");
        QTimer::singleShot(500,this,[=](){
            //close widget
            this->close();
        });
    });

//    QMediaPlayer*player = new QMediaPlayer(this);
//    connect(player,&QMediaPlayer::, this, &QMediaPlayer::play);
//    player->setMedia(QUrl::fromLocalFile("D:/source/qt_repos/PVZ/res/music.mp3"));
//    player->play();
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("D:/source/qt_repos/PVZ/res/music.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->setVolume(50);
    music->play();

}

void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix(":/res/Surface.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

Widget::~Widget()
{
    if(chooseScene!=NULL)
        delete chooseScene;
    delete ui;
}

