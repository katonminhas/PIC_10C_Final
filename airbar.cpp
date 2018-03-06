#include "airbar.h"

#include "game.h"

#include <QGraphicsRectItem>

#include <QTimer>


extern Game* game;



AirBar::AirBar(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent), height(800) {

    //set position and height of the rectangle
    setRect(20, 220, 30, height);

    //fill in color
    setBrush(QBrush(Qt::green));

    setZValue(1);
}





void AirBar::decrease() {


    if (height > 0){

        height -= 5;

        return;
    }


}
