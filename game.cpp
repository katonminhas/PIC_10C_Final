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
    gameScene(new QGraphicsScene()),
    diver(new Diver()),
    bar(new AirBar()),
    level(1),
    score(new Score())
{
    //seed the random number generator
    qsrand(QTime::currentTime().msecsSinceStartOfDay());


    //********************  Set the Scene  **********************//

    //set the size of the scene
    gameScene->setSceneRect(0, 0, 1972, 1442);


    //****************** Load Background Image *******************//

    //Background image is 986x721
    QImage backgroundImage(":/images/OceanBackground.png");

    QImage backgroundImageScaled = backgroundImage.scaled(1972, 1442, Qt::IgnoreAspectRatio);

    QBrush* backBrush = new QBrush(backgroundImageScaled);
    gameScene->setBackgroundBrush(*backBrush);



    //make the scene the scene to visualize
    setScene(gameScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set the size of the view
    setFixedSize(1972, 1442);

    //*******************  Make the Diver  *******************/

    //set starting position for the diver (middle-top)
    diver->setPos(936, 105);

    //make the diver focusable/set it to be the current focus
    diver->setFlag(QGraphicsItem::ItemIsFocusable);
    diver->setFocus();

    //add the diver to the scene
    gameScene->addItem(diver);


    //add the airbar to scene
    gameScene->addItem(bar);



    //********************  Spawn the first Pearl  ********************/

    Pearl* firstPearl = new Pearl();
    gameScene->addItem(firstPearl);


    //********************  Spawn the Sharks  ********************//
    QTimer* sharkSpawnTimer = new QTimer();
    //connect the spawning of sharks to the timeout of a timer
    QObject::connect(sharkSpawnTimer, SIGNAL(timeout()), diver, SLOT(spawnShark()));

    //start the timer to spawn sharks every 5 seconds
    sharkSpawnTimer->start(5000);

    //********************* Add the scoreboard *********************//
    gameScene->addItem(score);


    //closes game if diver hit's a shark
    QObject::connect(diver, SIGNAL(hitShark()), this, SLOT(close()));


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
    score->increase();
}


// Accessor member function accessing the score of the game
int Game::get_score() {
    return score->getScore();
}





void Game::resetGame() {

    scene()->removeItem(diver);
    delete diver;
    diver = new Diver();

    scene()->removeItem(bar);
    delete bar;
    bar = new AirBar();


    scene()->removeItem(score);
    delete score;
    score = new Score();

}











