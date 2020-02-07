#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "game.h"

extern Game *game;

Enemy::Enemy(int Difficulty)
{
    Health = Difficulty;
    setPixmap(QPixmap(":/tex/Enemy"));
    setScale(1);

    int Position = rand() % 600 + 100;
    setPos(Position, 0);

    timer = new QTimer(this);
    timer->start(1);
    connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
}


void Enemy::Move()
{
    setPos(x(), y() + 0.5);

    if (this->y() >= 1000)
    {
        scene()->removeItem(this);

        game->DecreaseHealth();

        delete this;
        return;
    }

    QList<QGraphicsItem*> collide = collidingItems();
        for (int i = 0 , n = collide.size(); i < n; i++)
        {            
            if (typeid(*collide[i]) == typeid(Bullet))
            {
                scene()->removeItem(collide[i]);
                delete collide[i];
                
                Health--;
                if (Health <= 0) 
                {
                    scene()->removeItem(this);

                    game->IncreaseScore();
                    game->DecreaseInterval();

                    delete this;
                }
                return;
            }

            if (typeid(*collide[i]) == typeid(Player))
            {
                scene()->removeItem(this);

                game->DecreaseHealth();

                delete this;
                return;
            }
        }
}

void Enemy::minusHealth()
{
    --Health;
}

int Enemy::getDifficulty()
{
    return Health;
}

int Enemy::getHealth()
{
    return Health;
}

