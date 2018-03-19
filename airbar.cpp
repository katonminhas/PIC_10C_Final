#include "airbar.h"

#include "game.h"

#include <QGraphicsRectItem>

#include <QTimer>


extern Game* game;


AirBar::AirBar(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent), height(800), yPos(220), airTimer(new QTimer()) {

    //set position and height of the rectangle
    setRect(20, yPos, 30, height);

    //fill in color
    setBrush(QBrush(Qt::green));


    QObject::connect(airTimer, SIGNAL(timeout()), this, SLOT(decrease()));
    airTimer->start(50);

    setZValue(1);
}





void AirBar::decrease() {


    //if there is height to decrease, decrease it
    if (height > 0){

        if (game->diver->pos().y() > 105){
            height --;
            yPos++;
            setRect(20, yPos, 30, height);
        }

        else{
            height = 800;
            yPos = 220;
            setRect(20, yPos, 30, height);
        }
    }

}
