#include "pearl.h"
#include "game.h"
#include "stdlib.h"
#include <QGraphicsScene>



extern Game* game;




Pearl::Pearl(QGraphicsItem *parent) : QObject(), QGraphicsRectItem() {

    int randX = qrand() %  1972;
    int randY = qrand() % 300 + 1100;

    setRect(randX, randY, 20, 20);
}
