#ifndef __IMGCONV_H__
#define __IMGCONV_H__
#include <QImage>
#include "opencv2/opencv.hpp"
namespace ImgConv
{
    QImage cvMat2QImage(const cv::Mat &mat);
    cv::Mat QImage2cvMat(QImage image);
} // namespace ImgConv

#endif // __IMGCONV_H__