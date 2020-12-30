#include "PathPainter.h"
#include <QPainter>
#include "opencv2/opencv.hpp"
#include "pa_CommonLibOnOS/DataConv/ImgConv/ImgConv.h"
#include "pa_CommonLibOnOS/DataConv/StrConv/StrConv.h"
#include "SerialManager/SerialManager.h"
// #include "SerialManager/SerialManager.h"
using namespace cv;
PathPainter *PathPainter::instance;
PathPainter::PathPainter(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    pathBuilder.init();
    instance = this;
    // SerialManager::instance.init();
}

// Q_INVOKABLE void PathPainter::recalcPath()
// {
//     //    qDebug()<<("recalcPath!");
//     pathBuilder.recalcPointVector();
//     this->update();
// }

Q_INVOKABLE void PathPainter::transmitImagePath(QString path)
{
    Mat mat;
    string realPath = StrConv::qstr2str(path);
    mat = imread(realPath.substr(8));
    std::cout << (realPath.substr(8)) << std::endl;
    // QImage image;
    // if (image.load(path))
    // {
    // mat = ImgConv::QImage2cvMat(image);

    cvtColor(mat, mat, COLOR_BGR2GRAY);
    imshow("load", mat);
    pathBuilder.recalcPointVector(mat);

    this->update();
    // }
}
void PathPainter::paint(QPainter *painter)
{
    // painter->save();
    // painter.re
    // painter->begin();
    // painter->eraseRect(0, 0, 1000, 1000);
    // this
    painter->setRenderHint(QPainter::SmoothPixmapTransform);
    painter->setPen(QPen(Qt::black, 1));
    painter->setRenderHints(QPainter::Antialiasing, true);
    qDebug() << ("paint!") << pathBuilder.pathPointsVector.size();
    int pathPointsVectorLen = pathBuilder.pathPointsVector.size();
    for (int i = 0; i < (SerialManager::instance.pointReadStep / 2) - 1; i++)
    {
        painter->setPen(QPen(Qt::black, 1));
        //        if (i % 2 == 0)
        {
            if (pathBuilder.pathPointsVector[i].putDown)
            {
                QPointF p1(pathBuilder.pathPointsVector[i].x * 1,
                           pathBuilder.pathPointsVector[i].y * 1);
                QPointF p2(pathBuilder.pathPointsVector[i + 1].x * 1,
                           pathBuilder.pathPointsVector[i + 1].y * 1);
                // painter->drawLine(p1 * 10, p2 * 10);
                painter->drawLine(p1, p2);
            }

            // painter->drawLine(
            //     ,
            //     ,
            //     pathBuilder.pathPointsVector[i + 1].x *1,
            //     pathBuilder.pathPointsVector[i + 1].y *1);
        }
        // else
        // {
        //     painter->setPen(Qt::blue);
        // }
        qDebug() << ("painti!") << i;
        //        painter->drawText(pathBuilder.pathPointsVector[i].x * 50, pathBuilder.pathPointsVector[i].y * 50,i);
        // painter->drawPoint(pathBuilder.pathPointsVector[i].x * 50, pathBuilder.pathPointsVector[i].y * 50);
        // painter->drawPoint(pathBuilder.pathPointsVector[i+1].x * 50, pathBuilder.pathPointsVector[i+1].y * 50);

        // pathBuilder.armDesc.armOriginalPointX +
        //     pathBuilder.armDesc.armOriginalPointY -
        //     pathBuilder.armDesc.armOriginalPointX +
        //     pathBuilder.armDesc.armOriginalPointY -
    }
}
