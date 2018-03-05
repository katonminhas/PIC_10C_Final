#include "shark.h"
#include <QGraphicsScene>
#include "stdlib.h"
#include "game.h"
#include <QTimer>


extern Game* game;


Shark::Shark(QGraphicsItem *parent) : QObject(), QGraphicsRectItem() {



    //set random y position
    int randomY = (rand() % 800) + 100;


    //set start for either left or right of screen
    //0 for left, 1 for right
    startingSide = rand() % 2;

    //spawn a shark from the left
    if (startingSide == 0){
        setRect(0, randomY, 100, 100);
    }
    else{
        setRect(1100, randomY, 100, 100);
    }




    //make and connect a timer to call move()
    //Moves the shark
    QTimer* timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //start the timer (lower # = faster shark speed)
    timer->start(100);
}



void Shark::move() {

    //if the shark is starting from the left, move right
    if (startingSide == 0){
        setPos(x() + 20, y());
    }
    else { //if the shark starts from right, move left
        setPos(x() - 20, y());
    }


    //destroy the shark if it leaves the screen
    //account for leaving to the left or right
    if (pos().x() + 100 < 0 || pos().x() > 1200 ){

        //remove shark from the scene
        scene()->removeItem(this);

        //delete shark from memory

        delete this;
    }

}
