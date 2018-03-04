#ifndef DIVER_H
#define DIVER_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>



class Diver : public QObject, public QGraphicsRectItem{

Q_OBJECT

public:

    Diver(QGraphicsItem* parent = 0);


    void keyPressEvent(QKeyEvent* event);




private:



};


#endif // DIVER_H
