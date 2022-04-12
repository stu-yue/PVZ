#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "choosemode.h"
#include "helpscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //rewrite paintEvent function
    void paintEvent(QPaintEvent *event) override;
    //
    ChooseMode* chooseScene=NULL;
    helpScene* helpInterface=NULL;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
