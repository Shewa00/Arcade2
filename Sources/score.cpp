#include "score.h"

#include <QGraphicsScene>
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem (parent)
{
    score = 0;
}

void Score::DrawScore()
{
    setPos(525, 100);
    setDefaultTextColor(Qt::white);
    setFont(QFont("Helvetica", 16));
    setPlainText(QString("SCORE: ") + QString::number(score));
}

int Score::GetScore()
{
    return score;
}

void Score::IncreaseScore()
{
    score +=100;
    setPlainText(QString("SCORE: ") + QString::number(score));
}

void Score::Zero()
{
    score = 0;
    setPlainText(QString("SCORE: ") + QString::number(score));
}
