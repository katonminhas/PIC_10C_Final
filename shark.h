#ifndef SHARK_H
#define SHARK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>



class Shark : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT


public:


    Shark(QGraphicsItem* parent = 0);


public slots:


    void move();


signals:

    void hitADiver(Shark*);


private:


    /* Integer variable indicating which side
     * of the screen the shark spawns from
     * 0 indicates left side
     * 1 indicates right side
     */
    int startingSide;

};


#endif // SHARK_H
