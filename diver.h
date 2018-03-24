#ifndef DIVER_H
#define DIVER_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>

#include "pearl.h"
#include "shark.h"



class Diver : public QObject, public QGraphicsPixmapItem{

Q_OBJECT

public:

    Diver(QGraphicsItem* parent = 0);


    void keyPressEvent(QKeyEvent* event);


    void pickUpPearl(QGraphicsItem* thePearl);


    void dropPearl();



signals:


    void grabPearl();

    void hitShark();


public slots:



    /*********** void Diver::spawnShark() *******************
     *
     * public slot member. Creates a Shark object connected
     * to the timeout() of a QTimer object.
     * Calls the Shark constructor, then adds the Shark to
     * the scene
     *
     *******************************************************/
    void spawnShark();



    void hitShark(Shark* theShark);





    /************ void Diver::spawnPearl(int) **************
     *
     * public slot member. Creates a Pearl object and adds it
     * to the scene. Connected to the diverSurfaced() signal
     * (whenever the level increases).
     * Calls the Pearl constructor, then adds the Pearl to
     * the scene
     *
     *****************************************************/
    void spawnPearl(size_t);


private:


    //all possible diver images
    QPixmap diverRight, diverLeft, diverUp, diverDown;

    QPixmap currentDiver;

    QGraphicsItem* currentPearl;

    QGraphicsItem* currentShark;

    bool hasPearl;

    int pearlCount;

};


#endif // DIVER_H
