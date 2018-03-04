#ifndef SHARK_H
#define SHARK_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>



class Shark : public QObject, public QGraphicsRectItem{

    Q_OBJECT


public:


    Shark(QGraphicsItem* parent = 0);


public slots:


    void move();


};


#endif // SHARK_H
