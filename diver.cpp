#include "diver.h"
#include "game.h"
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsPixmapItem>
#include "shark.h"
#include "pearl.h"
#include "endscreen.h"


extern Game* game;
extern End::EndScreen* endMenu;


Diver::Diver(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), diverRight(":/images/scubaRight.png"),
    diverLeft(":/images/scubaLeft.png"), diverUp(":/images/scubaUp.png"), diverDown(":/images/scubaDown.png"),
    hasPearl(false), pearlCount(0)
{
    setPixmap(diverRight);
    setScale(0.3);
}




/****** void Diver::keyPressEvent(QKeyEvent* event) ******
 *
 * public member function, allows the user to change the
 * location of the diver object using the arrow keys
 * Contains code limiting the boundaries of the diver
 * to that of the scene, cutting the diver off at the top
 * to indicate the surface of the water.
 *
 * @param QKeyEvent* event - the key event used to determine
 *                           the correct diver movement
 *
 * Also includes the code to remove Pearl items when the
 * diver collides with them.
 *
 ********************************************************/
void Diver::keyPressEvent(QKeyEvent *event) {


    //Code to see if the diver collides with pearl or shark
    QList<QGraphicsItem*> colliding_items = collidingItems(Qt::IntersectsItemShape);

    //if one of the colliding items is a pearl
    //and the diver doesn't already have a pearl, attach pearl to the diver
    for (size_t i = 0; i < colliding_items.size(); ++i){

        if (typeid(* (colliding_items[i])) == typeid(Pearl)) {
            pickUpPearl(colliding_items[i]);
        }

    }


    //if the diver hits the boat with the pearl, drop the pearl, increase score
    if (hasPearl &&
        pos().y() < 161 &&
        pos().x() > game->boat->x() &&
        pos().x() < game->boat->x() + 300)
    {
        dropPearl();
        game->increase_score();

        if (pearlCount == game->get_level()){
            game->increase_level();
            pearlCount = 0;
            spawnPearl(game->get_level());
        }

    }





    //move the diver
    //Left
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0){
            setPixmap(diverLeft);
            setPos(x() - 10, y());
        }
    }
    //Right
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 1972){
            setPixmap(diverRight);
            setPos(x()+10, y());
        }
    }
    //Down (harder to go down)
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 < 1442){
            setPixmap(diverDown);
            setPos(x(), y() + 5);
        }
    }
    //Up (easier to go up)
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 160) {
            setPixmap(diverUp);
            setPos(x(), y() - 20);
        }
    }

    /*
     * Note for later:
     * https://stackoverflow.com/questions/23816380/using-multiple-keys-in-qt-c
     * ^^ has code for moving multiple directions at the same time
     */

}

void Diver::pickUpPearl(QGraphicsItem* thePearl) {
    thePearl->setPos(x(), y());
    currentPearl = thePearl;
    hasPearl = true;
}

void Diver::dropPearl() {
    game->gameScene->removeItem(currentPearl);
    delete currentPearl;
    //currentPearl = nullptr;
    hasPearl = false;
    pearlCount++;
}

//slot function
void Diver::hitShark(Shark* theShark) {

    game->gameScene->removeItem(theShark);

    delete theShark;

    emit hitShark();
}




/************ void Diver::spawnPearl(int) **************
 *
 * public slot member. Creates a Pearl object and adds it
 * to the scene. Connected to the diverSurfaced() signal
 * (whenever the level increases).
 * Calls the Pearl constructor, then adds the Pearl to
 * the scene
 *
 *****************************************************/
void Diver::spawnShark() {

    if (game->gameScene){
        //create a shark
        Shark* shark = new Shark();
        game->gameScene->addItem(shark);
    }

}



/************ void Diver::spawnPearl(int) **************
 *
 * public slot member. Creates a Pearl object and adds it
 * to the scene. To be called whenever the level increases
 * (when the diver surfaces).
 * Calls the Pearl constructor, then adds the Pearl to
 * the scene
 *
 *****************************************************/

void Diver::spawnPearl(size_t num_pearls_to_spawn) {

    for (size_t i = 0; i < num_pearls_to_spawn; ++i){
        Pearl* pearl = new Pearl();
        scene()->addItem(pearl);
    }

}
