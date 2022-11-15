#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "Game.h"


Game * mygame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mygame = new Game();
    mygame->show();

    return a.exec();
}
