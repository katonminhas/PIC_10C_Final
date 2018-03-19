#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsScene>

namespace Title{

    class TitleScreen : public QGraphicsView {


    public:


        TitleScreen(QWidget* parent = 0);

        QGraphicsScene* titleScene;

        QPushButton* startButton;

        QPushButton* exitButton;

    private:



        QGraphicsTextItem* titleText;

    };

}



#endif // TITLESCREEN_H
