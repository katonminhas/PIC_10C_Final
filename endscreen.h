#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsScene>

namespace End {
    class EndScreen : public QGraphicsView {


    public:


        EndScreen(QWidget* parent = 0);

        QGraphicsScene* endScene;


    private:

        QPushButton* startButton;

        QPushButton* exitButton;

        QGraphicsTextItem* endText;

        QGraphicsTextItem* scoreText;

    };

}
#endif // ENDSCREEN_H
