#include "mainwindow.h"
#include "game.h"
#include "enemy.h"

extern MainWindow *Menu;

Game::Game()
{
}

void Game::DecreaseHealth()
{
    Health--;
    delete health[Health];
    if (Health <= 0)
    {
        GameOver();
    }
}

size_t Game::GetHealth()
{
    return Health;
}

void Game::IncreaseScore()
{
    score->IncreaseScore();
    if (score->GetScore() >= ScoreTarget)
    {
        ScoreTarget *= 2;

        if (Health < 3)
        {
            Health++;
            health.resize(Health);
            health[health.size() - 1] = new class Health(50 * (health.size() - 1));
            scene->addItem(health[health.size() - 1]);
        }
        
        Difficulty++;
    }
}

void Game::DecreaseInterval()
{
    if (Interval > 1100) {
        Interval -= 50;
        timer->setInterval(Interval);
    }
}

void Game::SpawnEnemy()
{
    Enemy *enemy = new Enemy(Difficulty);
    scene->addItem(enemy);
}

void Game::GameStart()
{
    srand(time(nullptr));

    /// Создание сцены
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 1000);
    scene->setBackgroundBrush(QImage(":/tex/Bckg"));

    /// Создание окна
    view = new QGraphicsView();
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->resize(800, 1000);

    view->show();

    /// Создание Игрока
    Player *player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    /// Создание Жизней Игрока
    Health = 3;
    health.resize(Health);
    for (size_t i = 0; i < health.size(); i++) {
        health[i] = new class Health(50 * i);
        scene->addItem(health[i]);
    }

    /// Спавн Врагов  по таймеру
    Interval = 2000;
    Difficulty = 1;
    timer = new QTimer();
    timer->setInterval(Interval);
    connect(timer, SIGNAL(timeout()), this, SLOT(SpawnEnemy()));
    timer->start();

    /// Создание Счета Игрока
    score = new Score();
    scene->addItem(score);
    score->DrawScore();
    ScoreTarget = 1000;
}


void Game::GameOver()
{
    emit exit();
    timer->stop();

    //Menu->show();

    scene->clear();
    view->close();

}

size_t Game::getHealth()
{
    return Health;
}

int Game::getInterval()
{
    return Interval;
}

size_t Game::getHealthAmount()
{
    return health.size();
}

