#include "Bureau.h"

void initBureau(Bureau& bureau)
{
    bureau.level = 1;
    bureau.fabrication = 1;
    bureau.buildTime = 1;
    bureau.qualityControl = 0.2;
    bureau.resourcePointGeneration = 1;
}

int BureauGetLevel(Bureau& bureau)
{
    return  bureau.level;
}

float BureauGetFabrication(Bureau& bureau)
{
    return  bureau.fabrication;
}

float BureauGetBuildTime(Bureau& bureau)
{
    return  bureau.buildTime;
}

float BureauGetQualityControl(Bureau& bureau)
{
    return  bureau.qualityControl;
}

float BureauGetResourcePointGeneration(Bureau& bureau)
{
    return  bureau.resourcePointGeneration;
}

void BureauUpgrade(Bureau& bureau)
{
    bureau.level++;
    bureau.fabrication = bureau.fabrication - 0.15;
    bureau.buildTime = bureau.buildTime - 0.15;
    bureau.qualityControl = bureau.qualityControl - 0.06;
    bureau.resourcePointGeneration = bureau.resourcePointGeneration + 0.2;
}
