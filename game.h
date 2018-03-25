#ifndef GAME_H
#define GAME_H


#include "diver.h"
#include "airbar.h"
#include "score.h"
#include "boat.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>




class Game : public QGraphicsView {

    Q_OBJECT

public:


    Game(QWidget* paren5t = 0);


    virtual ~Game() {}


    //The following members set up each element of the game
    void setUpDiver();

    void setUpScore();

    void setUpAirBar();

    void setUpBoat();

    void spawnFirstPearl();

    void setUpScene();

    void setUpGame();


    QGraphicsScene* gameScene;

    Diver* diver;

    AirBar* bar;

    Score* gameScore;

    Boat* boat;

    void increase_level();

    int get_level() const;

    void increase_score();

    int get_score();


signals:


    void endGame();


public slots:


    void startGame();


    void resetGame();


private:


    /* Integer variable indicating the current level
     * of the game. The level will increase each time
     * the diver surfaces. Each increasing level will
     * generate that number of new pearls for the diver
     * to collect.
     */
    int level;

    QTimer* sharkSpawnTimer;


};


#endif // GAME_H
