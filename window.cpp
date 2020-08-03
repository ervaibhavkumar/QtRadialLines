#include "window.h"
#include "line.h"
#include "utilities.h"

#include <QDebug>

Window::Window(QSize size, QGraphicsView *parent)
    : QGraphicsView(parent),
      windowSize(size)
{
     QGraphicsScene *scene = new QGraphicsScene();
     setScene(scene);

     scene->setSceneRect(0,0,windowSize.width(),windowSize.height());
     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setWindowTitle("Radial Lines Example");

     draw();
}

void Window::draw() {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(drawLines()));
    timer->start(50);
}

void Window::drawLines() {
    Line *l = new Line(QCursor::pos(), theta);
    theta += Utilities::getRandomNum(1, 100);
    scene()->addItem(l);
    scene()->update();
}

void Window::mousePressEvent(QMouseEvent *event) {
    scene()->clear();

    int r = Utilities::getRandomNum(100,220);
    int g = Utilities::getRandomNum(100,220);
    int b = Utilities::getRandomNum(100,220);

    scene()->setBackgroundBrush(QColor(r, g, b));
}
