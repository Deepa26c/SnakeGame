#include "SnakeGame.h"
#include "SnakeHead.h"
#include "Food.h"

SnakeGame::SnakeGame(QWidget *parent): QGraphicsView(parent){
    scene = new QGraphicsScene(0,0,800,600);
    setScene(scene);
  }

void SnakeGame::start(){

    SnakeHead* snakeHead = new SnakeHead();
    scene->addItem(snakeHead);
    snakeHead->setFocus();

    Food* f1 = new Food();
    f1->setPos(300,300);
    scene->addItem(f1);
}
