#include "game.h"
#include "diver.h"
#include "pearl.h"
#include "airbar.h"

#include <QTimer>
#include <QTime>
#include <QGraphicsScene>
#include <QPushButton>

#include <QImage>



Game::Game(QWidget *parent) : gameScene(new QGraphicsScene()), diver(new Diver()), bar(new AirBar()), level(1),
    score(new Score())
{


    //****************** Load Background Image ******************* //
    //Background image is 986x721
    QImage backgroundImage(":/images/OceanBackground.png");

    QImage backgroundImageScaled = backgroundImage.scaled(1972, 1442, Qt::IgnoreAspectRatio);

    QBrush* backBrush = new QBrush(backgroundImageScaled);
    gameScene->setBackgroundBrush(*backBrush);



    //seed the random number generator
    qsrand(QTime::currentTime().msecsSinceStartOfDay());


    //********************  Set the Scene  **********************//

    //set the size of the scene
    gameScene->setSceneRect(0, 0, 1972, 1442);

    setScene(gameScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set the size of the view
    setFixedSize(1972, 1442);
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


void Game::startGame() {


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



void Game::displayMainMenu() {


    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Title of the Game!!!"));

    titleText->setPos(986 - (titleText->boundingRect().width() / 2), 250);

    QFont titleFont("times", 48);

    titleText->setFont(titleFont);

    //add to scene
    gameScene->addItem(titleText);


    //Establish a font for the buttons (font = times, 16pt, demibold, italics = false)
    QFont buttonFont("times", 16, 63, false);


    //make the start button
    QPushButton* startButton = new QPushButton();
    //make the exit button
    QPushButton* exitButton = new QPushButton();


    // ******************* add buttons to the scene ******************//
    //split screen into thirds
    startButton->setGeometry(507, 920, 300, 150);
    startButton->setFont(buttonFont);
    startButton->setText("Start Game");

    exitButton->setGeometry(1014, 920, 300, 150);
    exitButton->setFont(buttonFont);
    exitButton->setText("Exit");

    gameScene->addWidget(startButton);
    gameScene->addWidget(exitButton);


    //connect buttons to slots
    QObject::connect(startButton, SIGNAL(pressed()), this, SLOT(startGame()));
    QObject::connect(exitButton, SIGNAL(pressed()), this, SLOT(close()));

}





















