#ifndef WINDOW_H
#define WINDOW_H

#include <QGraphicsView>
#include <QTimer>

class Window : public QGraphicsView
{
    Q_OBJECT
public:
    Window(QSize size, QGraphicsView *parent = nullptr);

public slots:
    void drawLines();

private:
    void mousePressEvent(QMouseEvent *event) override;
    QSize windowSize;
    void draw();

    int theta = 0;
};

#endif // WINDOW_H
