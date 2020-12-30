#ifndef __PATHPAINTER_H__
#define __PATHPAINTER_H__

#include <QQuickPaintedItem>
#include "PathBuilder/PathBuilder.h"
class PathPainter : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit PathPainter(QQuickItem *parent = nullptr);
    Q_INVOKABLE void transmitImagePath(QString qstring);
    virtual void paint(QPainter *painter);
    PathBuilder &pathBuilder = PathBuilder::instance;
    static PathPainter *instance;
};

#endif // __PATHPAINTER_H__
