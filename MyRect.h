#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class MyRect: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    MyRect(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();

private:
    QMediaPlayer * bulletSound;








};

#endif // MYRECT_H
