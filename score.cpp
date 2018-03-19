#include "score.h"

#include <QFont>





Score::Score(QGraphicsItem *parent) : score(0) {

    //set position
    setPos(20, 20);

    //draw the text
    setPlainText(QString("Pearls: ") + QString::number(score));

    //set color
    setDefaultTextColor(Qt::blue);

    //set font
    setFont(QFont("times", 16));


}




void Score::increase() {
    ++score;
    setPlainText(QString("Score: ") + QString::number(score));
}




int Score::getScore() const{
   return score;
}




