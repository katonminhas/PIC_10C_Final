#include "boat.h"
#include "game.h"
#include <QGraphicsPixmapItem>
#include <QObject>


extern Game* game;

Boat::Boat(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(QPixmap(":/images/boat.png"));
}
