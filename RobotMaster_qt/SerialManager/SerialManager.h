#ifndef __SERIALMANAGER_H__
#define __SERIALMANAGER_H__

class SerialManager
{
public:
    static void init();
    static PathBuilder *instance;
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

#endif // __SERIALMANAGER_H__