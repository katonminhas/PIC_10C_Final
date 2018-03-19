#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsScene>

#include "match.h"

namespace End {

    class EndScreen : public QGraphicsView {


    public:

        EndScreen(QWidget* parent = 0);

        QGraphicsScene* endScene;

        QPushButton* startButton;

    signals:

        void buttonPressed();

    private:

        QPushButton* exitButton;

        QGraphicsTextItem* endText;

        QGraphicsTextItem* scoreText;

        bool startisPressed;

    };

}
#endif // ENDSCREEN_H
