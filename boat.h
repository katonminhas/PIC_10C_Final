#ifndef BOAT_H
#define BOAT_H

#include <QGraphicsPixmapItem>


class Boat : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

public:

    Boat(QGraphicsItem* parent = 0);



};

#endif // BOAT_H
