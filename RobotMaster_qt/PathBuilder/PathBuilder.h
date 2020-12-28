#ifndef __PATHBUILDER_H__
#define __PATHBUILDER_H__
#include <vector>
#include "opencv2/opencv.hpp"
using namespace std;

typedef struct
{
    float x;
    float y;
    char putDown;
} PathPointStruct;

typedef struct
{
    float paperWidth;
    float paperHeight;
    float armOriginalPointX;
    float armOriginalPointY;
    float penWidth;
    float minSectionLen;
} ArmDescription;

typedef struct
{
    float x;
    float y;
    float z;
} PathPointStruct3D;

class PathBuilder
{
public:
    static void init();
    static PathBuilder instance;
    void recalcPointVector(cv::Mat &mat);
    vector<PathPointStruct> pathPointsVector;
    ArmDescription armDesc;

private:
    const double sqrt2 = 1.4142135623731;
    int calcPointVectorLen();
    void convertPosFromLeftUpToArmPos(float &x, float &y);
    int getLineGrayLevel(float x1, float y1, float x2, float y2, cv::Mat &mat);
    bool getPutdownByGrayLevel(int graylevel, int stepLevel);
    void convPaperPos2MatPos(float &x1, float &y1, float &x2, float &y2, cv::Mat &mat);
};
#endif // __PATHBUILDER_H__
