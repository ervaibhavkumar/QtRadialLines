#include "line.h"
#include "utilities.h"

#include <QPainter>
#include <QtMath>

Line::Line(QPoint mouse, int angle, QGraphicsWidget *parent)
    : QGraphicsWidget(parent),
      cursor(mouse),
      lineAngle(angle) {}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    int r = Utilities::getRandomNum(150,200);
    int g = Utilities::getRandomNum(150,200);
    int b = Utilities::getRandomNum(150,200);

    int radius = Utilities::getRandomNum(40,100);

    int startX = cursor.x() - radius * qCos(qDegreesToRadians((double) lineAngle));
    int startY = cursor.y() - radius * qSin(qDegreesToRadians((double) lineAngle));
    int finalX = cursor.x() + radius * qCos(qDegreesToRadians((double) lineAngle));
    int finalY = cursor.y() + radius * qSin(qDegreesToRadians((double) lineAngle));

    painter->setPen(QPen(QColor(r,g,b), 3));
    painter->drawLine(startX, startY, finalX, finalY);
}
