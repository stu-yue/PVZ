#ifndef CAR_H
#define CAR_H

#include <QWidget>
#include <QMovie>
#include <QLabel>

class lawnScene;
class darkScene;

class Car : public QLabel
{
    Q_OBJECT
public:
    Car(lawnScene*Lawn,QWidget *parent = nullptr);
    Car(darkScene*Dawn,QWidget *parent = nullptr);
    ~Car();
    bool Present();
    void todo();
    void setRow(int r);
    lawnScene*lawn=NULL;
    darkScene*dark=NULL;


private:
    bool present=true;
    int row;
    int speed;
    bool Drive=false;
    QMovie*animation=new QMovie(":/res/LawnMower.gif");

signals:

};

#endif // CAR_H
