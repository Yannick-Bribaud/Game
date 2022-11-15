#include "Game.h"
#include <QMediaPlayer>

Game::Game(QWidget *parent)
{
    // creation de la scene
      scene = new QGraphicsScene();
      scene->setBackgroundBrush(QBrush(QImage(":/Images/AppIMage.jpg")));

    // création d'un item dans le graphic scene
    player = new MyRect();

   //  ajouter l'item dans le graphics scene;
    scene->addItem(player);

   player->setFlags(QGraphicsItem::ItemIsFocusable);
   player->setFocus();

    // ajouter un view pour visualiser;
     setScene(scene);

     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


     setFixedSize(800,600);
     scene->setSceneRect(0,0,800,600);

     player->setPos(400,500);

      // la frayée de l'enemie
      QTimer * timer = new QTimer();
      QObject::connect(timer,SIGNAL(timeout()),player, SLOT(spawn()));
      timer->start(1000);
      score = new Score();
      health = new Health();
      health->setPos(health->x(), health->y()+25);
      scene->addItem(score);
      scene->addItem(health);

      //background Music

    QMediaPlayer * bg_music = new QMediaPlayer();
     bg_music->setMedia(QUrl("qrc:/sons/Maroon 5 - Memories.mp3"));
    // bg_music->play();

      show();

}
