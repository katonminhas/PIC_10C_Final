#include "titlescreen.h"

#include <QPushButton>
#include <QString>
#include <QGraphicsTextItem>
#include <QImage>

#include "game.h"

extern Game* game;

namespace Title {

    void setUpButton(QPushButton* button, int xPos, int yPos, QString text){
        button->setGeometry(xPos, yPos, 350, 150);
        button->setText(text);
    }
}



Title::TitleScreen::TitleScreen(QWidget *parent) :
    QGraphicsView(parent),
    titleScene(new QGraphicsScene()),
    startButton(new QPushButton()),
    exitButton(new QPushButton()),
    titleText(new QGraphicsTextItem(QString("Diver vs Sharks")))
{

    //set the size of the view
    setFixedSize(1972, 1442);

    //********************  Set the Scene  **********************//
    //set the size of the scene
    titleScene->setSceneRect(0, 0, 1972, 1442);


    //****************** Load Background Image *******************//

    //Background image is 986x721
    QImage backgroundImage(":/images/OceanBackground.png");

    QImage backgroundImageScaled = backgroundImage.scaled(1972, 1442, Qt::IgnoreAspectRatio);

    QBrush* backBrush = new QBrush(backgroundImageScaled);
    titleScene->setBackgroundBrush(*backBrush);


    //******************** Add the Title Text **********************//
    QFont titleFont("impact", 44);
    titleText->setFont(titleFont);
    int midpoint = width() / 2;
    int widthOfText = titleText->boundingRect().width();
    //center the text
    titleText->setPos(midpoint - widthOfText/2, 350);
    titleScene->addItem(titleText); //add to scene


    //******************* Add the Buttons **************************//
    int firstThird = width() / 3;
    const int widthOfButton = 350;
    Title::setUpButton(startButton, firstThird - widthOfButton/2, 650, "Start");
    Title::setUpButton(exitButton, firstThird*2 - widthOfButton/2, 650, "Exit");
    titleScene->addWidget(startButton); //add to scene
    titleScene->addWidget(exitButton);  //add to scene



    //****************** Visualize the scene ************************//
    setScene(titleScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}
