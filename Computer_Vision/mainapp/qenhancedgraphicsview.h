#ifndef QENHANCEDGRAPHICSVIEW_H
#define QENHANCEDGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QtMath>
#include <QContextMenuEvent>
#include <QMenu>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsEffect>

class QEnhancedGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QEnhancedGraphicsView(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event);

private:
    QPointF sceneMousePos;
signals:

public slots:
};

#endif // QENHANCEDGRAPHICSVIEW_H
