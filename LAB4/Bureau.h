#pragma once
#include <iostream>
#include <conio.h>

class Bureau {
	int level;
	float fabrication;
	float buildTime;
	float qualityControl;
	float resourcePointGeneration;
public:
	Bureau();
	~Bureau();

	int GetLevel();
	float GetFabrication();
	float GetBuildTime();
	float GetQualityControl();
	float GetResourcePointGeneration();

	void UpgradeBureau();
};

