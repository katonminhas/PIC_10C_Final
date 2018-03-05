#include "game.h"
#include "diver.h"

#include <QTimer>



Game::Game(QWidget *parent) : gameScene(new QGraphicsScene()), diver(new Diver()), level(1) {

    //change the size of the scene
    gameScene->setSceneRect(0, 0, 1200, 900);


    //make the scene the scene to visualize
    setScene(gameScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(1200, 900);



    //set starting position for the diver (middle-top)
    diver->setPos(550, 50);

    //make the diver focusable/set it to be the current focus
    diver->setFlag(QGraphicsItem::ItemIsFocusable);
    diver->setFocus();


    //add the diver to the scene
    gameScene->addItem(diver);


    //spawn sharks
    QTimer* spawnTimer = new QTimer();

    //connect the spawning of sharks to the timeout of a timer
    QObject::connect(spawnTimer, SIGNAL(timeout()), diver, SLOT(spawn()));


    //start the timer to spawn sharks every 2 seconds
    //(***For Later - have the sharks spawn faster in higher levels
    spawnTimer->start(2000);

}
