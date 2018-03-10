#include "titlescreen.h"
#include <QPushButton>



TitleScreen::TitleScreen(QWidget *parent) : startButton(new QPushButton()), exitButton(new QPushButton())

{
    //********************  Set the Scene  **********************//

    //set the size of the scene
    setSceneRect(0, 0, 1972, 1442);


    //Establish a font (font = times, 16pt, demibold, italics = false)
    QFont buttonFont("times", 16, 63, false);




    // ******************* add buttons to the scene ******************//
    startButton->setGeometry(507, 920, 300, 150);
    startButton->setFont(buttonFont);
    startButton->setText("Start Game");

    exitButton->setGeometry(1164, 920, 300, 150);
    exitButton->setFont(buttonFont);
    exitButton->setText("Exit");

    addWidget(startButton);
    addWidget(exitButton);


    // For later - add title graphic below vvvv



    //****************** Load Background Image *******************//

    //Background image is 986x721
    QImage backgroundImage(":/images/OceanBackground.png");

    QImage backgroundImageScaled = backgroundImage.scaled(1972, 1442, Qt::IgnoreAspectRatio);

    QBrush* backBrush = new QBrush(backgroundImageScaled);
    setBackgroundBrush(*backBrush);

}
