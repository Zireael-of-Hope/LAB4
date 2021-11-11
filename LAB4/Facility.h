#pragma once
#include <iostream>
#include <conio.h>

#include "Color.h"
#include "Bureau.h"

using namespace std;

class Facility {
private:
	Bureau aerodynamics;
	Bureau powertrain;
	Bureau chassis;
	Bureau durability;

public:
	Facility();
	~Facility();

	void GetInfoBureauAerodynamics();
	void GetInfoBureauPowertrain();
	void GetInfoBureauChassis();
	void GetInfoBureauDurability();
	void SetFacilityBureausLevel_interface();

	int ReturnAerodynamicsLevel();
	int ReturnPowertrainLevel();
	int ReturnChassisLevel();
	int ReturnDurabilityLevel();
};




