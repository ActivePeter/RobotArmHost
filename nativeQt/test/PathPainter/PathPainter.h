#ifndef __PATHPAINTER_H__
#define __PATHPAINTER_H__

#include <QQuickPaintedItem>

class PathPainter : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit PathPainter(QQuickItem *parent = nullptr);

    virtual void paint(QPainter *painter);
};

#endif // __PATHPAINTER_H__
