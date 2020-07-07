#include <QApplication>
#include "SnakeGame.h"

SnakeGame* game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    game = new SnakeGame();
    game->show();
    game->start();
    return a.exec();
}
