#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsScene>



namespace End {

    class EndScreen : public QGraphicsView {

        Q_OBJECT

    public:

        EndScreen(QWidget* parent = 0);

        QGraphicsScene* endScene;

        QPushButton* startButton;

    private:

        QPushButton* exitButton;

        QGraphicsTextItem* endText;

        QGraphicsTextItem* scoreText;

        bool startisPressed;

    };

}
#endif // ENDSCREEN_H
