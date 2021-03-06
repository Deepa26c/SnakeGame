#include "SnakeHead.h"
#include <QBrush>
#include "Food.h"
#include "SnakeBody.h"
#include "SnakeGame.h"
#include <typeinfo>

extern SnakeGame* game;

SnakeHead::SnakeHead(QGraphicsItem* parent){
    setRect(0,0,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    setFlag(QGraphicsItem::ItemIsFocusable,true);

    SnakeBody* b1=new SnakeBody();
    b1->setPos(0,50);
    game->scene->addItem(b1);
    snakeBodies.prepend(b1);
}

void SnakeHead::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up)
    {
        prevPos=pos();
        int xPos=x();
        int yPos=y() - boundingRect().height();
        setPos(xPos,yPos);
        moveBodies();
    }

    else if(event->key() == Qt::Key_Down)
    {
        prevPos=pos();
        int xPos=x();
        int yPos=y()- boundingRect().height();
        setPos(xPos,yPos);
        moveBodies();
    }

    else if(event->key() == Qt::Key_Right)
    {
        prevPos=pos();
        int xPos=x();
        int yPos=y() - boundingRect().width();
        setPos(xPos,yPos);
        moveBodies();
    }

    else if(event->key() == Qt::Key_Left)
    {
        prevPos=pos();
        int xPos=x();
        int yPos=y() - boundingRect().width();
        setPos(xPos,yPos);
        moveBodies();
    }

    QList<QGraphicsItem*> cItems =collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
            if (typeid(*(cItems[i])) == typeid(Food)){
                // fruit found in collision list
                elongate();
            }
        }
}

void SnakeHead::elongate(){
    // add new SnakeBody to list
    SnakeBody* body = new SnakeBody();
    snakeBodies.prepend(body);

    // properly position the body
    body->setPos(-200,-200); // TODO
    game->scene->addItem(body);
}

void SnakeHead::moveBodies(){
    // traverses through list of bodies and moves them properly

    // move all bodies from back to front
    for (size_t i = 0, n = snakeBodies.size()-1; i < n; ++i){
        snakeBodies[i]->setPos(snakeBodies[i+1]->pos());
    }

    // move front body to previous position of head
    snakeBodies.last()->setPos(prevPos);
}
