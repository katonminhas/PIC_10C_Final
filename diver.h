#ifndef DIVER_H
#define DIVER_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>



class Diver : public QObject, public QGraphicsPixmapItem{

Q_OBJECT

public:

    Diver(QGraphicsItem* parent = 0);


    void keyPressEvent(QKeyEvent* event);


signals:


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

};


#endif // DIVER_H
