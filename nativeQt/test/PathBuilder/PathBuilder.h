#ifndef __PATHBUILDER_H__
#define __PATHBUILDER_H__
#include <vector>
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

class PathBuilder
{
public:
    static void init();
    void RecalcPointVector();

private:
    const double sqrt2 = 1.4142135623731;
    int calcPointVectorLen();
    vector<PathPointStruct> *PathPointsVector;
    ArmDescription armDesc;
}
#endif // __PATHBUILDER_H__