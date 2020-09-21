#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "MainWindow.h"

class myQGraphicsView : public QGraphicsView
{
    Q_OBJECT
    MainWindow* myParentWindow;
public:
    myQGraphicsView(QWidget *parent = 0);
    ~myQGraphicsView();
    int x,y;
    void setMyParentWindow(MainWindow*);



protected:
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MYQGRAPHICSVIEW_H
