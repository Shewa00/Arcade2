#include "bullet.h"

#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet() {
    setPixmap(QPixmap(":/tex/Bullet"));
    setScale(1);

    QTimer *timer = new QTimer(this);
    timer->start(1);
    connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
}

void Bullet::Move() {
    if (y() <= 0 ) {
        scene()->removeItem(this);
        delete this;
        return;
    }

    this->setPos(x(), y() - 2);
}
