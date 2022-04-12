#ifndef CHOOSEMODE_H
#define CHOOSEMODE_H

#include <QWidget>
#include <QLabel>
#include "lawnscene.h"
#include "darkscene.h"

class ChooseMode : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseMode(QWidget *parent = nullptr);
    ~ChooseMode();

    void paintEvent(QPaintEvent *event);
    lawnScene*lawn=NULL;
    darkScene*dark=NULL;

private:
//    lawnScene*lawn=NULL;
//    darkScene*dark=NULL;

signals:
    void backToMenu();

};

#endif // CHOOSEMODE_H
