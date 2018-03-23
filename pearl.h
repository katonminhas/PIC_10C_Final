#ifndef PEARL_H
#define PEARL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Pearl : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT


public:

    Pearl(QGraphicsItem* parent = 0);


public slots:


    void deletePearl();

};


#endif // PEARL_H
