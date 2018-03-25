#include "pearl.h"
#include "stdlib.h"
#include <QGraphicsScene>
#include "game.h"

extern Game* game;


Pearl::Pearl(QGraphicsItem *parent) :
    QObject(),
    QGraphicsPixmapItem(parent)
{
    int randX = qrand() %  1920;
    int randY = qrand() % 350 + 1050;

    setPixmap(QPixmap(":/images/pearlPic.png"));
    setPos(randX, randY);

    setScale(0.6);

    //removes all the pearls when the game is over
    QObject::connect(game->diver, SIGNAL(hitShark()), this, SLOT(deletePearl()));
    QObject::connect(game->bar, SIGNAL(outOfAir()), this, SLOT(deletePearl()));
}


void Pearl::deletePearl() {

    if (game->gameScene){
        game->gameScene->removeItem(this);
        delete this;
    }
}
