#include "diver.h"
#include <QGraphicsScene>
#include "shark.h"


Diver::Diver(QGraphicsItem *parent) {

    setRect(0, 0, 100, 100);
}

void Diver::keyPressEvent(QKeyEvent *event) {

    //move the player


    //Left
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0){
            setPos(x()-10, y());
        }
    }
    //Right
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 1200){
            setPos(x()+10, y());
        }
    }
    //Down (harder to go down)
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 < 900){
            setPos(x(), y() + 5);
        }
    }
    //Up (easier to go up)
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 50){
            setPos(x(), y() -20);
        }

    }

    /*
     * Note for later:
     * https://stackoverflow.com/questions/23816380/using-multiple-keys-in-qt-c
     * ^^ has code for moving multiple directions at the same time
     */

}

void Diver::spawn() {

    //create a number of shark
    Shark* shark = new Shark();
    scene()->addItem(shark);

}
