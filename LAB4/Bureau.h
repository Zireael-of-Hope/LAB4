#pragma once
#include <iostream>
#include <conio.h>

struct Bureau {
	int level;
	float fabrication;
	float buildTime;
	float qualityControl;
	float resourcePointGeneration;
};

void initBureau(Bureau& bureau);

int BureauGetLevel(Bureau& bureau);
float BureauGetFabrication(Bureau& bureau);
float BureauGetBuildTime(Bureau& bureau);
float BureauGetQualityControl(Bureau& bureau);
float BureauGetResourcePointGeneration(Bureau& bureau);
void BureauUpgrade(Bureau& bureau);