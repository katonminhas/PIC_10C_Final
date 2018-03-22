#include "endscreen.h"


#include <QPushButton>
#include <QString>
#include <QGraphicsTextItem>
#include <QObject>
#include <QImage>
#include "game.h"




extern Game* game;



namespace End {

    void setUpButton(QPushButton* button, int xPos, int yPos, QString text){
        button->setGeometry(xPos, yPos, 350, 150);
        button->setText(text);
    }
}





End::EndScreen::EndScreen(QWidget *parent) :
    QGraphicsView(parent),
    endScene(new QGraphicsScene()),
    startButton(new QPushButton()),
    exitButton(new QPushButton()),
    endText(new QGraphicsTextItem(QString("Game Over!")))
{
    //set the size of the view
    setFixedSize(1972, 1442);

    //********************  Set the Scene  **********************//
    //set the size of the scene
    endScene->setSceneRect(0, 0, 1972, 1442);


    //****************** Load Background Image *******************//

    //Background image is 986x721
    QImage backgroundImage(":/images/OceanBackground.png");

    QImage backgroundImageScaled = backgroundImage.scaled(1972, 1442, Qt::IgnoreAspectRatio);

    QBrush* backBrush = new QBrush(backgroundImageScaled);
    endScene->setBackgroundBrush(*backBrush);

    int midpoint = width() / 2;

    //******************* Add the score text *************************//
    QString scoreString;
    if (game->gameScore){
        scoreString = QString("Score: ") + QString::number(game->get_score());
    }
    else{
        scoreString = QString("Score: 0");
    }

    scoreText = new QGraphicsTextItem(scoreString);
    QFont scoreFont("impact", 24);
    scoreText->setFont(scoreFont);
    int widthOfScore = scoreText->boundingRect().width();
    scoreText->setPos(midpoint - widthOfScore/2, 500);  //center the text
    endScene->addItem(scoreText);


    //******************** Add the Title Text **********************//
    QFont endFont("impact", 36);
    endText->setFont(endFont);
    int widthOfText = endText->boundingRect().width();
    //center the text
    endText->setPos(midpoint - widthOfText/2, 350);
    endScene->addItem(endText); //add to scene


    //******************* Add the Buttons **************************//
    int firstThird = width() / 3;
    const int widthOfButton = 350;
    End::setUpButton(startButton, firstThird - widthOfButton/2, 650, "Start");
    End::setUpButton(exitButton, firstThird*2 - widthOfButton/2, 650, "Exit");
    endScene->addWidget(startButton); //add to scene
    endScene->addWidget(exitButton);  //add to scene


    //****************** Visualize the scene ************************//
    setScene(endScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //if shark gets hit show the end screen
    QObject::connect(game->diver, SIGNAL(hitShark()), this, SLOT(show()));

    //Connect buttons
    QObject::connect(startButton, SIGNAL(pressed()), game, SLOT(resetGame()));
    QObject::connect(startButton, SIGNAL(pressed()), this, SLOT(close()));

    QObject::connect(exitButton, SIGNAL(pressed()), this, SLOT(close()));

}
