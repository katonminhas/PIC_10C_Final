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
    diverLeft(":/images/scubaLeft.png"), diverUp(":/images/scubaUp.png"), diverDown(":/images/scubaDown.png")

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


    //Code to see if the diver collides with pearl
    QList<QGraphicsItem*> colliding_items = collidingItems();




    //if one of the colliding items is a pearl remove the pearl
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(Pearl)) {

            //remove pearl from the scene
            scene()->removeItem(colliding_items[i]);

            //delete pearl
            delete colliding_items[i];

            //increase the score
            game->increase_score();

            return;
        }

    }

    //if one of the colliding items is a shark, emit hit shark
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(Shark)){

            scene()->removeItem(colliding_items[i]);

            delete colliding_items[i];

            emit hitShark();
        }
    }





    //if the diver surfaces, increase the level and spawn new pearls
    //switch graphic back to scubaRight
    if (pos().y() < 110 && event->key() == Qt::Key_Up){

        //increase the level
        game->increase_level();
        spawnPearl(game->get_level());
        setPixmap(diverRight);

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
        if (pos().y() > 104) {
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

    //create a shark
    Shark* shark = new Shark();
    scene()->addItem(shark);

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
