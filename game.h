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


    void increase_level();



    int get_level() const;


    void increase_score();


    int get_score() const;


signals:






private:



    /* Integer variable indicating the current level
     * of the game. The level will increase each time
     * the diver surfaces. Each increasing level will
     * generate that number of new pearls for the diver
     * to collect.
     */
    int level;


    /* Integer variable indicating the number of pearls
     * the diver has collected.
     *
     * ***For Later: Add another variable keeping track
     *               of the local high score
     */
    int score;


};


#endif // GAME_H
