#pragma once
#include <iostream>
#include <conio.h>

#include "Facility.h"
#include "Vehicle.h"
#include "Driver.h"
#include "Sponsor.h"

using namespace std;

class MyF1Team {
public:
	Driver firstDriver;
	Driver secondDriver;
	Vehicle w11_1;
	Vehicle w11_2;
	Facility facility;
	Sponsor mainSponsor;
	Sponsor secondarySponsor;

	MyF1Team() {};
	~MyF1Team() {};
	void InteractSlot();

	void GetTeamInfo();

	void ChangeDriver();
	void SubChangeDriver(int whichDriver, std::string& tempString, int& tempInt, double& tempDouble);

	void ChangeVehicle();
	void SubChangeVehicle(int carNumber, bool& isPass, char& decision, std::string& tempString, bool& isCycled);
	void SubChangeVehicle_stickers(bool& isCycled, int carNumber, bool& isPass, char& decision, std::string& tempString);
	void SubChangeVehicle_driver(bool& isPass, char& decision, int carNumber, bool& isCycled);

	void ChangeSponsor();
	void SubchangeSposnor(int whichSponsor, std::string& tempString, double& tempDouble);
};
