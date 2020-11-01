#include "PathBuilder.h"
#include <QDebug>
#include <algorithm>
PathBuilder PathBuilder::instance;

int PathBuilder::calcPointVectorLen()
{
    float minSectionXLen = armDesc.minSectionLen / sqrt2;
    //curXstep:=minSectionXLen
    int curStepCnt = 0;
    int pointCnt = 0;

    for (;;)
    {
        float curXLen = minSectionXLen + armDesc.penWidth * (curStepCnt);
        if (curXLen > armDesc.paperWidth + armDesc.paperHeight - minSectionXLen)
        {
            break;
        }
        int onePathPointCnt = (int)(min(curXLen, armDesc.paperHeight) / minSectionXLen) + 1;
        if (curXLen > armDesc.paperWidth)
        {
            onePathPointCnt = (int)((armDesc.paperHeight + armDesc.paperWidth - curXLen) / minSectionXLen) + 1;
        }
        pointCnt += onePathPointCnt;
        //curXstep+=armDesc.penWidth
        curStepCnt++;
    }
    return pointCnt;
}

void PathBuilder::convertPosFromLeftUpToArmPos(float &x, float &y)
{
    x = x - armDesc.armOriginalPointX;
    y = armDesc.armOriginalPointY - y;
}

void PathBuilder::recalcPointVector(cv::Mat &mat)
{
    float minSectionXLen = armDesc.minSectionLen / sqrt2;
    int pathPointVectorLen = calcPointVectorLen();
    pathPointsVector.resize(pathPointVectorLen);
    int curStepCnt = 0;
    int addedPointCnt = 0;
    qDebug() << ("pathPointVectorLen!") << pathPointVectorLen;
    float curXLen = minSectionXLen;
    for (;;)
    {
        //        float curXLen = minSectionXLen + armDesc.penWidth * (curStepCnt);

        int onePathPointCnt = (int)(min(curXLen, armDesc.paperHeight) / minSectionXLen) + 1;
        // int onePathPointCnt2 = (int)((curXLen) / minSectionXLen) + 1;
        // max
        if (curXLen > armDesc.paperWidth + armDesc.paperHeight - minSectionXLen)
        {
            break;
        }
        else
        {
        }
        if (curXLen > armDesc.paperWidth)
        {
            onePathPointCnt = (int)((armDesc.paperHeight + armDesc.paperWidth - curXLen) / minSectionXLen) + 1;
        }
        qDebug() << ("onePathPointCnt!") << onePathPointCnt;

        // pathPointsVector[onePathPointCnt - 1].putDown = 0;
        for (int i = 0; i < onePathPointCnt; i++)
        {

            float y;

            if (curXLen > armDesc.paperWidth)
            {
                if (curStepCnt % 2 == 1)
                {
                    y = curXLen - armDesc.paperWidth + (armDesc.paperHeight + armDesc.paperWidth - curXLen) * (onePathPointCnt - i - 1) / (onePathPointCnt - 1);
                }
                else
                {
                    y = curXLen - armDesc.paperWidth + (armDesc.paperHeight + armDesc.paperWidth - curXLen) * (i) / (onePathPointCnt - 1);
                }
                // y = min(curXLen, armDesc.paperHeight) * i / (onePathPointCnt - 1);
            }
            else
            {
                if (curStepCnt % 2 == 1)
                {
                    y = min(curXLen, armDesc.paperHeight) * (onePathPointCnt - i - 1) / (onePathPointCnt - 1);
                }
                else
                {
                    y = min(curXLen, armDesc.paperHeight) * i / (onePathPointCnt - 1);
                }
            }

            float x = curXLen - y;
            // if (curStepCnt % 2 == 1) //如果为奇数。进行xy交换
            // {
            //     float a = y;
            //     y = x;
            //     x = a;
            // }
            // convertPosFromLeftUpToArmPos(y, x);
            pathPointsVector[addedPointCnt].x = x;
            pathPointsVector[addedPointCnt].y = y;

            if (i > 0)
            {
                int grayLevel = getLineGrayLevel(
                    pathPointsVector[addedPointCnt].x,
                    pathPointsVector[addedPointCnt].y,
                    pathPointsVector[addedPointCnt - 1].x,
                    pathPointsVector[addedPointCnt - 1].y,
                    mat);
                pathPointsVector[addedPointCnt - 1].putDown = (char)getPutdownByGrayLevel(grayLevel, curStepCnt);
            }
            addedPointCnt++;
        }
        //        curXLen+= 1.0f;
        curXLen += armDesc.penWidth;
        curStepCnt++;
    }
    //    qDebug()<<("curStepCnt!")<<curStepCnt;
}

int PathBuilder::getLineGrayLevel(float x1, float y1, float x2, float y2, cv::Mat &mat)
{
    //先将点转换到图像坐标下，然后进行
    convPaperPos2MatPos(x1, y1, x2, y2, mat);
    int graySum = 0;
    int sumCnt = 0;
    {
        float delta_x, delta_y, x, y;
        int dx, dy, steps;
        dx = x2 - x1;
        dy = y2 - y1;
        if (abs(dx) > abs(dy))
        {
            steps = abs(dx);
        }
        else
        {
            steps = abs(dy);
        }
        delta_x = (float)dx / (float)steps;
        delta_y = (float)dy / (float)steps;
        x = x1;
        y = y1;
        //  glClear(GL_COLOR_BUFFER_BIT);
        // glBegin(GL_POINTS);
        // glVertex3f(x, y, 0);
        for (int i = 1; i <= steps; i++)
        {
            graySum += mat.at<uint8_t>(y, x);
            sumCnt++;
            x += delta_x;
            y += delta_y;
            // glBegin(GL_POINTS);
            // glVertex3f(x, y, 0);
            // glEnd();
        }
    }

    return graySum / sumCnt;
}

bool PathBuilder::getPutdownByGrayLevel(int graylevel, int stepLevel)
{
    int resolution = 4;
    stepLevel %= resolution;                  //0-3
    graylevel = graylevel * resolution / 255; //0-4

    return stepLevel < graylevel;
}

void PathBuilder::convPaperPos2MatPos(float &x1, float &y1, float &x2, float &y2, cv::Mat &mat)
{
    x1 = x1 / armDesc.paperWidth * mat.cols;
    y1 = y1 / armDesc.paperWidth * mat.cols;
    x2 = x2 / armDesc.paperWidth * mat.cols;
    y2 = y2 / armDesc.paperWidth * mat.cols;
}

void PathBuilder::init()
{
    instance.armDesc.paperHeight = 200;
    instance.armDesc.paperWidth = 200;
    instance.armDesc.penWidth = 0.5;
    instance.armDesc.minSectionLen = 2;
    instance.armDesc.armOriginalPointX = 100;
    instance.armDesc.armOriginalPointY = 100;
}
