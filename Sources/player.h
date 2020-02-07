#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player : public QGraphicsPixmapItem   /// Класс Игрока
{
public:
    /// Конструктор
    Player();

    /// Функция ввода с клавиатуры
    void keyPressEvent(QKeyEvent *event);

    /// Передвижение Вправо/Влево
    void MoveRight(int scale);

    /// Выстрел
    void Fire();

    /// Стартовое значение генерации пули
    QPointF getStartBulletPosition();
};

#endif // PLAYER_H
