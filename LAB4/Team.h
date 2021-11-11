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
	void interactSlot();

	void getTeamInfo();

	void changeDriver();
	void sub_changeDriver(int whichDriver, std::string& tempString, int& tempInt);

	void changeVehicle();
	void sub_changeVehicle(int carNumber, bool& isPass, char& decision, std::string& tempString, bool& isCycled);
	void sub_changeVehicle_stickers(bool& isCycled, int carNumber, bool& isPass, char& decision, std::string& tempString);
	void sub_changeVehicle_driver(bool& isPass, char& decision, int carNumber, bool& isCycled);

	void changeSponsor();
	void sub_changeSposnor(int whichSponsor, std::string& tempString, double& tempDouble);
};
