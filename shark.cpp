#include "shark.h"
#include <QGraphicsScene>
#include <qglobal.h>
#include "stdlib.h"
#include "game.h"
#include <QTimer>
#include <QTime>
#include <QImage>
#include <QGraphicsPixmapItem>


extern Game* game;



Shark::Shark(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {



    //set random y position
    int randomY = qrand() % 860 + 220;


    //set start for either left or right of screen
    //0 for left, 1 for right
    startingSide = qrand() % 2;



    //spawn a shark from the left (start them off screen)
    if (startingSide == 0){
        setPos(-400, randomY);
        setPixmap(QPixmap(":/images/rightSharkImage.png"));
    }
    //spawn a shark from the right
    else {
        setPos(1972, randomY);
        setPixmap(QPixmap(":/images/leftSharkImage.png"));
    }

    setScale(0.6);



    //make and connect a timer to call move()
    //Moves the shark
    QTimer* timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //start the timer (call move every 50 ms)
    timer->start(50);




}




/***************** void Shark::move() ***************************
 *
 * public slot member function containing code to move the shark
 * Allows for variable shark speed
 * moves left side sharks right and vice versa
 * contains code to remove and delete sharks once they exit the screen
 *
 ***************************************************************/
void Shark::move() {

     QObject::connect(this, SIGNAL(hitADiver(Shark*)), game->diver, SLOT(hitShark(Shark*)));

    //indicates the speed of a shark
    int speed = 5;


    //if the shark is starting from the left, move right
    if (startingSide == 0){
        setPos(x() + speed, y());
    }
    else { //if the shark starts from right, move left
        setPos(x() - speed, y());
    }


    //Handle Collision with Diver
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (size_t i = 0; i < colliding_items.size(); ++i){


        if (typeid(*(colliding_items[i])) == typeid(Diver)){

            emit hitADiver(this);

        }

    }






    //destroys left-moving sharks
    if (startingSide == 1 && pos().x() < -400){

        //remove the shark from the scene
        scene()->removeItem(this);

        //delete shark from memory
        delete this;
    }

    //destroy right-moving sharks
    else if (startingSide == 0 && pos().x() > 1972){

        //remove shark from the scene
        scene()->removeItem(this);

        //delete shark from memory
        delete this;
    }


}
