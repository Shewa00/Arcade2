#include "player.h"
#include "bullet.h"
#include "game.h"


extern Game *game;

Player::Player()
{
    setPixmap(QPixmap(":/tex/Player"));
    setScale(1);
    setPos(200, 880);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A)
    {
        if (x() > 0)
            MoveRight(-1);
    }

    if (event->key() == Qt::Key_D)
    {
        if (x() < 700)
            MoveRight(1);
    }

    if (event->key() == Qt::Key_Space)
    {
        Fire();
    }
}


void Player::MoveRight(int scale)
{
    this->setPos(x() + 50 * scale, y());
}

void Player::Fire()
{
    Bullet *bullet = new Bullet();
    bullet->setPos(this->x()+44, this->y()-30);
    game->scene->addItem(bullet);
}

QPointF Player::getStartBulletPosition()
{
    return QPointF(this->x() + 44, this->y() - 30);
}

