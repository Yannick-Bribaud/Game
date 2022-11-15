#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>


extern Game * mygame;

Enemy::Enemy()
{
    int random_Number = rand()% 700;
    setPos(random_Number,0);
    setPixmap(QPixmap(":/Images/Enemy.jpg"));
    setTransformOriginPoint(50,50);
    setRotation(180);

         // connection signal
      QTimer * timer = new QTimer();
      connect(timer,SIGNAL(timeout()),this, SLOT(move()));
      timer->start(50);
}

void Enemy::move()
{
    // enemy move
    setPos(x(),y()+5);
    if(pos().y() > 600)
    {
      mygame->health->Decrease();
      scene()->removeItem(this);
      delete  this;
    }
}
