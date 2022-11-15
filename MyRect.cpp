#include "MyRect.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Enemy.h"


MyRect::MyRect(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sons/Would You Still Love Me - Brian Nhira (Official Video).mp3"));
    setPixmap(QPixmap(":/Images/Player.jpg"));
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x()> 0)
        {
          setPos(x()-20,y());
        }
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(pos().x() + 100 < 800)
        {
           setPos(x()+20,y());
        }

    }
    else if(event->key()==Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+40,y());
        scene()->addItem(bullet);

        //play bulletSound
        if(bulletSound->state()==QMediaPlayer::PlayingState)
        {
            bulletSound->setPosition(0);
        }
        else if(bulletSound->state()==QMediaPlayer::StoppedState)
        {
            bulletSound->play();
        }
    }

}

void MyRect::spawn()
{
   Enemy * enemy = new Enemy();
   scene()->addItem(enemy);


}
