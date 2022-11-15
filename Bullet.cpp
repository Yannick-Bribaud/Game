
#include "Bullet.h"
#include <QTimer>
#include <QDebug>
#include "Enemy.h"
#include "Game.h"


extern Game * mygame;

Bullet::Bullet(): QObject(), QGraphicsPixmapItem()
{
    //dessin du rectangle
       setPixmap(QPixmap(":/Images/bulletImag.png"));


    // connection signal
       QTimer * timer = new QTimer();
       connect(timer,SIGNAL(timeout()),this, SLOT(move()));
       timer->start(50);
}



void Bullet::move()
{
    QList<QGraphicsItem *>Colliding_items = collidingItems();
    for(int i=0,n=Colliding_items.size(); i< n; ++i)
    {
        if(typeid(*(Colliding_items[i]))==typeid (Enemy))
        {
            mygame->score->increase();
            //remove them
            scene()->removeItem(Colliding_items[i]);
            scene()->removeItem(this);
            delete Colliding_items[i];
            delete this;
            return;

        }
    }
    // bouge vers haut
    setPos(x(),y()-10);
    if(pos().y() + 100< 0)
    {
        scene()->removeItem(this);
        delete  this;
    }

}
