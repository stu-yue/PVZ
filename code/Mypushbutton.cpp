#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QSound>

MyPushButton::MyPushButton(const QString normalImg,const QString selectImg)
{
    normalImgPath=normalImg;
    selectImgPath=selectImg;
    QPixmap pixmap;
    if(!pixmap.load(normalImgPath))
    {
        qDebug()<<normalImg<<"加载图片失败!";
    }
    //set pix fixedsize
    this->setFixedSize(pixmap.width(),pixmap.height());
    //set the style sheet for irregular img
    this->setStyleSheet("QPushButton{border:0px;}");
    //set icon
    this->setIcon(pixmap);
    //set icon size
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    this->setCursor(Qt::PointingHandCursor);
    QMediaPlayer*player = new QMediaPlayer(this);
    //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile("D:/source/qt_repos/PVZ/res/music.mp3"));
    player->play();
}

void MyPushButton::enterEvent(QEvent *event)
{
    if(selectImgPath != "") //选中路径不为空，显示选中图片
    {
        QPixmap pixmap;
        bool ret = pixmap.load(selectImgPath);
        if(!ret)
        {
            qDebug() << selectImgPath << "加载图片失败!";
        }

        this->setFixedSize( pixmap.width(), pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
    QSound::play(":/res/strength.wav");
    //QSound::play(":/res/clicked.wav");
    //qDebug()<<"点击了";
    //交给父类执行按下事件
    //return QPushButton::mousePressEvent(e);
}

void MyPushButton::leaveEvent(QEvent *event)
{
    if(normalImgPath != "") //选中路径不为空，显示选中图片
    {
        QPixmap pixmap;
        bool ret = pixmap.load(normalImgPath);
        if(!ret)
        {
            qDebug() << normalImgPath << "加载图片失败!";
        }

        this->setFixedSize( pixmap.width(), pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
    //交给父类执行按下事件
    //return QPushButton::mousePressEvent(e);
}

void MyPushButton::bouncing()
{
    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
    //set interval
    animation->setDuration(200);
    //start position
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //end position
    animation->setEndValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    //set easement curve(QEasingCurve::OutBounce is bounce effect)
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //start execute animation
    animation->start();
}
void MyPushButton::bounced()
{
    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
    //set interval
    animation->setDuration(200);
    //start position
    animation->setStartValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    //end position
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //set easement curve(QEasingCurve::OutBounce is bounce effect)
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //start execute animation
    animation->start();
}
