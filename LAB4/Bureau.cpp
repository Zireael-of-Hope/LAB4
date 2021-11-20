#include "Bureau.h"

Bureau::Bureau()
{
    level = 1;
    fabrication = 1;
    buildTime = 1;
    qualityControl = 0.2;
    resourcePointGeneration = 1;
}

Bureau::~Bureau()
{
}

int Bureau::GetLevel()
{
    return level;
}

float Bureau::GetFabrication()
{
    return fabrication;
}

float Bureau::GetBuildTime()
{
    return buildTime;
}

float Bureau::GetQualityControl()
{
    return qualityControl;
}

float Bureau::GetResourcePointGeneration()
{
    return resourcePointGeneration;
}

void Bureau::UpgradeBureau()
{
    level++;
    fabrication = fabrication - 0.15;
    buildTime = buildTime - 0.15;
    qualityControl = qualityControl - 0.06;
    resourcePointGeneration = resourcePointGeneration + 0.2;
}
