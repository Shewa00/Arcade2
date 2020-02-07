#ifndef SCORE_H
#define SCORE_H


#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem   /// Класс Счет Игрока
{
    /// Счет Игрока
    int score;
public:
    /// Конструктор
    Score(QGraphicsItem *parent = nullptr);

    /// Вывести Счет На Экран
    void DrawScore();

    /// Получить Счет
    int GetScore();

    /// Увеличить Счет
    void IncreaseScore();

    /// Обнулить Счет
    void Zero();
};

#endif // SCORE_H
