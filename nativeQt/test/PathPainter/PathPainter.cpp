#include "PathPainter.h"
#include <QPainter>

PathPainter::PathPainter(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}
void PathPainter::paint(QPainter *painter)
{
    painter->setPen(Qt::yellow);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawLine(0, 0, 100, 100);
}
