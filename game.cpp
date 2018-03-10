#include "game.h"
#include "diver.h"
#include "pearl.h"
#include "airbar.h"

#include <QTimer>
#include <QTime>
#include <QGraphicsScene>

#include <QImage>



Game::Game(QWidget *parent) : gameScene(new QGraphicsScene()), titleScene(new TitleScreen()), diver(new Diver()), bar(new AirBar()), level(1), score(new Score()) {


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



    //make title scene the scene to visualize
    setScene(titleScene);


    QObject::connect(titleScene->startButton, SIGNAL(pressed()), this, SLOT(startGame());


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

    //add the diver to game scene
    gameScene->addItem(diver);


    //add the airbar to game scene
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
int Game::get_score() const {
    return score->getScore();
}




//Displays the game to the screen
void Game::startGame()
{

    setScene(gameScene);
}









