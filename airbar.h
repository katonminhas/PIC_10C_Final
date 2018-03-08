#ifndef AIRBAR_H
#define AIRBAR_H

#include <QObject>
#include <QGraphicsRectItem>



class AirBar : public QObject, public QGraphicsRectItem {

    Q_OBJECT

public:

    AirBar(QGraphicsItem* parent = 0);


public slots:


    void decrease();


private:



    size_t height;
    size_t yPos;

    QTimer* airTimer;



};


#endif // AIRBAR_H
