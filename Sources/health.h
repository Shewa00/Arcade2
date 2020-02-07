#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsPixmapItem>

class Health : public QGraphicsPixmapItem   /// Класс Жизней Игрока
{
    int Position;
public:
    /// Конструктор
    Health(int Shift);

    /// Деструктор
    ~Health() = default;

    /// Получение стартовой позиции отрисовки
    int getPosition();
};

#endif // HEALTH_H
