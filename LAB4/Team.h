#pragma once
#include <iostream>
#include <conio.h>

#include "Facility.h"
#include "Vehicle.h"
#include "Driver.h"
#include "Sponsor.h"

using namespace std;

struct MyF1Team {
	Driver firstDriver;
	Driver secondDriver;
	Vehicle w11_1;
	Vehicle w11_2;
	Facility facility;
	Sponsor mainSponsor;
	Sponsor secondarySponsor;
};

void initMyF1Team(MyF1Team& team);
void MyF1TeamInteractSlot(MyF1Team& team);

void MyF1TeamGetTeamInfo(MyF1Team& team);

void MyF1TeamChangeDriver(MyF1Team& team);
void MyF1TeamSubChangeDriver(MyF1Team& team, int whichDriver, std::string& tempString, int& tempInt, double& tempDouble);

void MyF1TeamChangeVehicle(MyF1Team& team);
void MyF1TeamSubchangeVehicle(MyF1Team& team, int carNumber, bool& isPass, char& decision, std::string& tempString, bool& isCycled);
void MyF1TeamSubchangeVehicle_stickers(MyF1Team& team, bool& isCycled, int carNumber, bool& isPass, char& decision, std::string& tempString);
void MyF1TeamSubchangeVehicle_driver(MyF1Team& team, bool& isPass, char& decision, int carNumber, bool& isCycled);

void MyF1TeamChangeSponsor(MyF1Team& team);
void MyF1TeamSubChangeSposnor(MyF1Team& team, int whichSponsor, std::string& tempString, double& tempDouble);