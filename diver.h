#ifndef DIVER_H
#define DIVER_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>



class Diver : public QObject, public QGraphicsRectItem{

Q_OBJECT

public:

    Diver(QGraphicsItem* parent = 0);


    void keyPressEvent(QKeyEvent* event);



public slots:

    void spawn();


private:



};


#endif // DIVER_H
