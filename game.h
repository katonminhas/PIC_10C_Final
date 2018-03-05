#ifndef GAME_H
#define GAME_H


#include "diver.h"

#include <QGraphicsView>
#include <QGraphicsScene>




class Game : public QGraphicsView {

public:


    Game(QWidget* parent = 0);


    QGraphicsScene* gameScene;


    Diver* diver;


private:

    /* Integer variable indicating the current level
     * of the game. This is equal to the amount of
     * pearls that the diver must collect before
     * resurfacing
     */
    int level;


};


#endif // GAME_H
