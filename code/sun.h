#ifndef SUN_H
#define SUN_H

#include <QLabel>
#include <QMovie>
#include <QWidget>
#include <QMouseEvent>
#include <QSound>


class Sun : public QLabel
{
    Q_OBJECT
public:
    explicit Sun(QWidget *parent = nullptr);
    ~Sun();
    void setAltitude(int x);
    void todo();
    //void perform();
    void mousePressEvent(QMouseEvent*event);
    bool Present();

private:
    int countDown,altitude;
    float speed;
    bool present;
    bool collected;
    QMovie*animation=new QMovie(":/res/Sun.gif");
    QSound*audio=new QSound(":/res/Sun.wav");

signals:

};

#endif // SUN_H
