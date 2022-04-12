#ifndef OPTPUSHBUTTON_H
#define OPTPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit optPushButton(QWidget *parent = nullptr);

    //rewrite a new constructor
    MyPushButton(const QString normalImg,const QString selectImg="");
    //
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void bouncing();
    void bounced();


private:
    QString normalImgPath;
    QString selectImgPath;

signals:

};

#endif // OPTPUSHBUTTON_H
