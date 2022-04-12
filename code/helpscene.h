#ifndef HELPSCENE_H
#define HELPSCENE_H

#include <QWidget>

class helpScene : public QWidget
{
    Q_OBJECT
public:
    explicit helpScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:
    void backToMenu();

};

#endif // HELPSCENE_H
