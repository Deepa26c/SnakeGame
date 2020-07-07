#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class SnakeGame: public QGraphicsView{
public:
    SnakeGame(QWidget* parent=NULL);
    void start();

    QGraphicsScene* scene;

};

#endif // SNAKEGAME_H
