#include <QTest>
#include "game.h"
#include "score.h"
#include "health.h"
#include "mainwindow.h"
#include "enemy.h"
#include "player.h"
#include "bullet.h"

class Test_Player: public QObject
{
Q_OBJECT
public:
    explicit Test_Player(QObject *parent = nullptr);
private slots:
    void testGame();
    void testHealth();
    void testBullet();
    void testScore();
    void testMainWindow();
    void testEnemy();
    void testPlayer();
};

Game *game;

Test_Player::Test_Player(QObject *parent) :
    QObject(parent)
{
    game = new Game();
}

void Test_Player::testGame()
{
    QCOMPARE(true, true);
    Game* newGame = new Game();
    QCOMPARE(newGame->getHealth(), 0);
    QCOMPARE(newGame->getHealthAmount(), 0);
    newGame->GameStart();
    QCOMPARE(newGame->getHealthAmount(), 3);
    QCOMPARE(newGame->getHealth(), 3);
    newGame->DecreaseHealth();
    QCOMPARE(newGame->getHealth(), 2);
    newGame->DecreaseHealth();
    QCOMPARE(newGame->getHealth(), 1);
    QCOMPARE(newGame->getInterval(), 2000);
    newGame->DecreaseInterval();
    QCOMPARE(newGame->getInterval(), 1950);
    newGame->GameOver();
}

void Test_Player::testScore()
{
    Score* score = new Score();
    QCOMPARE(score->GetScore(), 0);
    score->IncreaseScore();
    QCOMPARE(score->GetScore(), 100);
    score->IncreaseScore();
    QCOMPARE(score->GetScore(), 200);
    score->Zero();
    QCOMPARE(score->GetScore(), 0);

}
void Test_Player::testMainWindow()
{
    MainWindow *m = new MainWindow();
    m->show();
    QCOMPARE(m->isVisible(), true);
    m->close();
    QCOMPARE(m->isVisible(), false);
    m->deleteLater();
}

void Test_Player::testHealth()
{
    Health* heath1 = new Health(12);
    QCOMPARE(heath1->getPosition(), 637);

    Health* heath2 = new Health(-12);
    QCOMPARE(heath2->getPosition(), 613);
}

void Test_Player::testBullet()
{
    Bullet *nbullet = new Bullet();
    nbullet->setPos(0,0);
    QCOMPARE(nbullet->pos(), QPointF(0, 0));
    nbullet->deleteLater();
}

void Test_Player::testEnemy()
{
    Enemy* enemy = new Enemy(10);
    QCOMPARE(enemy->getDifficulty(), 10);
    QCOMPARE(enemy->getHealth(), 10);
    enemy->minusHealth();
    QCOMPARE(enemy->getHealth(), 9);
    enemy->minusHealth();
    QCOMPARE(enemy->getHealth(), 8);
    enemy->minusHealth();
    enemy->deleteLater();
}

void Test_Player::testPlayer()
{

    Player* player1 = new Player();
    player1->setPos(0,0);
    QCOMPARE(player1->getStartBulletPosition(), QPointF(44, -30));

}

QTEST_MAIN(Test_Player)
#include "tests.moc"