#ifndef LINE_H
#define LINE_H

#include <QGraphicsWidget>

class Line : public QGraphicsWidget
{
public:
    Line(QPoint mouse, int angle, QGraphicsWidget *widget = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QPoint cursor;
    int lineAngle;
};

#endif // LINE_H
