#pragma once
#include <iostream>
#include <conio.h>

#include "Color.h"
#include "Bureau.h"

using namespace std;

struct Facility {
	Bureau aerodynamics;
	Bureau powertrain;
	Bureau chassis;
	Bureau durability;
};

void initFacility(Facility& facility);

void FacilityGetInfoAerodynamics(Facility& facility);
void FacilityGetInfoPowertrain(Facility& facility);
void FacilityGetInfoChassis(Facility& facility);
void FacilityGetInfoDurability(Facility& facility);
void FacilitySetBureausLevel_interface(Facility& facility);

int FacilityReturnAerodynamicsLevel(Facility& facility);
int FacilityReturnPowertrainLevel(Facility& facility);
int FacilityReturnChassisLevel(Facility& facility);
int FacilityReturnDurabilityLevel(Facility& facility);


