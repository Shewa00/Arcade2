#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem   /// Класс Пули
{
    Q_OBJECT
public:
    /// Конструктор
    Bullet();

    /// Деструктор
    ~Bullet() = default;

public slots:
    /// Передвижение
    void Move();
};

#endif // BULLET_H
