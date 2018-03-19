#include "pearl.h"
#include "stdlib.h"
#include <QGraphicsScene>
#include "game.h"

extern Game* game;


Pearl::Pearl(QGraphicsItem *parent) :
    QObject(),
    QGraphicsRectItem(parent)
{

    int randX = qrand() %  1972;
    int randY = qrand() % 300 + 1100;

    setRect(randX, randY, 20, 20);
}
