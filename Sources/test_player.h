#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H
#include <QObject>


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
    void testEnemy();
    void testMainWindow();
    void testPlayer();
};

#endif // TEST_PLAYER_H
