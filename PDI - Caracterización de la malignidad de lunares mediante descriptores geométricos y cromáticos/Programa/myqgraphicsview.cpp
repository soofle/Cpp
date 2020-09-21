#include "myqgraphicsview.h"

myQGraphicsView::myQGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    setAttribute(Qt::WA_StaticContents);
}

myQGraphicsView::~myQGraphicsView()
{

}

void myQGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    x = event->x();
    y = event->y();
}

void myQGraphicsView::setMyParentWindow(MainWindow* m)
{
    myParentWindow = m;
}
