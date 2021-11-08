#pragma once
#include <iostream>
#include <conio.h>
#include "Color.h"
using namespace std;

struct Bureau
{
	int level;
	float fabrication;
	float buildTime;
	float qualityControl;
	float resourcePointGeneration;
};

class Facility
{
private:
	Bureau aerodynamics_;
	Bureau powertrain_;
	Bureau chassis_;
	Bureau durability_;

public:
	Facility();
	~Facility();

	void getInfoBureauAerodynamics();
	void getInfoBureauPowertrain();
	void getInfoBureauChassis();
	void getInfoBureauDurability();
	void setFacilityBureausLevel_interface();

	int returnAerodynamicsLevel();
	int returnPowertrainLevel();
	int returnChassisLevel();
	int returnDurabilityLevel();
};




