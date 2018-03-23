#include "game.h"
#include "diver.h"
#include "pearl.h"
#include "airbar.h"
#include "titlescreen.h"
#include "endscreen.h"

#include <QTimer>
#include <QTime>
#include <QGraphicsScene>

#include <QImage>



extern Title::TitleScreen* mainMenu;
extern End::EndScreen* endMenu;



Game::Game(QWidget *parent) :
    QGraphicsView(parent),
    gameScene(nullptr),
    diver(nullptr),
    gameScore(nullptr),
    bar(nullptr),
    boat(nullptr),
    sharkSpawnTimer(new QTimer())
{
    //set up the scene
    setUpScene();

    //make the scene the scene to visualize
    setScene(gameScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set the size of the view
    setFixedSize(1972, 1442);


    //start the timer to spawn sharks every 5 seconds
    sharkSpawnTimer->start(5000);

}




void Game::setUpDiver(){

    diver = new Diver();

    //*******************  Make the Diver  *******************/
    //set starting position for the diver (middle-top)
    diver->setPos(936, 160);
    //make the diver focusable/set it to be the current focus
    diver->setFlag(QGraphicsItem::ItemIsFocusable);
    diver->setFocus();
    //add the diver to the scene
    gameScene->addItem(diver);
}


void Game::setUpScore() {

    gameScore = new Score();

    gameScene->addItem(gameScore);

}


void Game::setUpAirBar() {

    bar = new AirBar();

    //add the airbar to scene
    gameScene->addItem(bar);
}


void Game::setUpBoat(){

    boat = new Boat();
    boat->setPos(275, 5);
    boat->setScale(0.3);
    gameScene->addItem(boat);

}


void Game::spawnFirstPearl() {
    Pearl* firstPearl = new Pearl();
    gameScene->addItem(firstPearl);
}


void Game::setUpScene(){

    gameScene = new QGraphicsScene();

    gameScene->setSceneRect(0,0, 1972, 1442);


    //****************** Load Background Image *******************//
    //Background image is 986x721
    QImage backgroundImage(":/images/OceanBackground.png");

    QImage backgroundImageScaled = backgroundImage.scaled(1972, 1442, Qt::IgnoreAspectRatio);

    QBrush* backBrush = new QBrush(backgroundImageScaled);
    gameScene->setBackgroundBrush(*backBrush);
}




//increases the level of the game
void Game::increase_level() {
    ++level;
}


//Accessor member function accessing the level of the game
int Game::get_level() const {
    return level;
}


//increases the score
void Game::increase_score() {
    gameScore->increase();
}


// Accessor member function accessing the score of the game
int Game::get_score() {
    if (gameScore)
        return gameScore->score;
    else return 0;
}




void Game::startGame() {

    //seed the random number generator
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    level = 1;

    setUpDiver();

    setUpScore();

    setUpAirBar();

    setUpBoat();

    spawnFirstPearl();

    //connect the spawning of sharks to the timeout of a timer
    QObject::connect(sharkSpawnTimer, SIGNAL(timeout()), diver, SLOT(spawnShark()));

    //closes game if diver hit's a shark
    QObject::connect(diver, SIGNAL(hitShark()), this, SLOT(close()));
    QObject::connect(diver, SIGNAL(hitShark()), endMenu, SLOT(show()));


    show();     //show the view
}


void Game::resetGame() {

    //seed the random number generator
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    gameScene->removeItem(diver);
    gameScene->removeItem(bar);
    gameScene->removeItem(gameScore);
    delete diver;
    delete bar;
    delete gameScore;

    startGame();
/*
    setUpDiver();
    setUpAirBar();
    setUpScore();
    spawnFirstPearl();
    level = 1;

    setUpScene();

    sharkSpawnTimer->start(5000);
    //connect the spawning of sharks to the timeout of a timer
    QObject::connect(sharkSpawnTimer, SIGNAL(timeout()), diver, SLOT(spawnShark()));

    //closes game if diver hit's a shark
    QObject::connect(diver, SIGNAL(hitShark()), this, SLOT(close()));
    QObject::connect(diver, SIGNAL(hitShark()), endMenu, SLOT(show()));

    show();
    */

}











