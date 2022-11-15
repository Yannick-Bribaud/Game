#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initialisation
    health = 10;

    setPlainText(QString("Health :") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::Decrease()
{
    health--;
    setPlainText(QString("Health :") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
