#include "PathBuilder.h"

int PathBuilder::calcPointVectorLen()
{
    float minSectionXLen = armDesc.minSectionLen / sqrt2;
    //curXstep:=minSectionXLen
    int curStepCnt = 0;
    int pointCnt = 0;

    for (;;)
    {
        float curXLen = minSectionXLen + armDesc.penWidth * (curStepCnt);
        pointCnt += (int)(curXLen / minSectionXLen) + 1;
        //curXstep+=armDesc.penWidth
        curStepCnt++;
        if (curXLen > armDesc.paperWidth)
        {
            break;
        }
    }
    return pointCnt;
}

void PathBuilder::RecalcPointVector()
{
    int pathPointVectorLen =
}
