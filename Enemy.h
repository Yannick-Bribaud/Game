#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
#include <QGraphicsRectItem>
#include "Game.h"


class Enemy: public QObject,public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Enemy();
public slots:
    void move();



};




#endif // ENEMY_H
