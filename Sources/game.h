#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <vector>

#include "player.h"
#include "score.h"
#include "health.h"

class Game : public QObject  /// Класс Игры
{
    Q_OBJECT

    /// Сцена Игры
    QGraphicsScene *scene;

    /// Окно Игры
    QGraphicsView *view;

    /// Счет Игрока
    class Score *score;

    /// Порог Счета Для Получение Бонус-Жизни
    int ScoreTarget;

    /// Сложность Игры
    int Difficulty;
    
    /// Количество Жизней Игрока
    size_t Health;

    /// Жизни Игрока
    std::vector<class Health*> health;

    /// Интервал Между Спавнами Врагов
    int Interval;

    /// Таймер Спавна ВРагов
    QTimer *timer;

public:
    /// Конструктор
    Game();

    /// Декструктор
    ~Game() = default;

    /// Перечисление friend-классов
    friend Player;

    /// Уменьшить Количсетво Жизней
    void DecreaseHealth();

    /// Получить Количество Жихней
    size_t GetHealth();

    /// Увеличить Счет Игрока
    void IncreaseScore();

    /// Уменьшить Время Между Спавнами Врагов
    void DecreaseInterval();

    /// Начать Игру
    void GameStart();

    /// Закончить Игру
    void GameOver();

    /// Здоровье игрока
    size_t getHealth();

    /// Кол-во сердец (проверка логической реализации интерфейса
    size_t getHealthAmount();

    /// Получение интервала генерирования противников
    int getInterval();

public slots:
    /// Заспавнить Врага
    void SpawnEnemy();

signals:
    void exit();

};

#endif // GAME_H
