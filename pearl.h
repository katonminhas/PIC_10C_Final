#ifndef PEARL_H
#define PEARL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>


class Pearl : public QObject, public QGraphicsRectItem {

    Q_OBJECT


public:

    Pearl(QGraphicsItem* parent = 0);



};


#endif // PEARL_H
