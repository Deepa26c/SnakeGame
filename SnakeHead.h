#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H
#include "SnakeBody.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
#include <QMetaType>

class SnakeHead:public QGraphicsRectItem{
public:
    SnakeHead(QGraphicsItem* parent = NULL);

    void keyPressEvent(QKeyEvent *event);

    void elongate();
    void moveBodies();

private:
    QList<SnakeBody*> snakeBodies;
    QPointF prevPos;

};

#endif // SNAKEHEAD_H
