#ifndef TITLESCREEN_H
#define TITLESCREEN_H


#include <QGraphicsView>
#include <QPushButton>


class TitleScreen : public QGraphicsScene {

public:


    TitleScreen(QWidget* parent = 0);


    QPushButton* startButton;

    QPushButton* exitButton;

private:



};

#endif // TITLESCREEN_H
