#pragma once
#include <iostream>
#include <string>

#include "Color.h"

using namespace std;

struct Driver
{
	string name = "NoName";
	int number_ = 0;

	int overallRating_ = 0;
	int experience_ = 0;
	int racecraft_ = 0;
	int awareness_ = 0;
	int pace_ = 0;
	double salary_ = 0;
};

void initDriver(Driver& driver);

void DriverSetName(Driver& driver, string newName);
void DriverSetNumber(Driver& driver, int newNumber);
void DriverSetOverallRating(Driver& driver, int newOverallRating);
void DriverSetExperience(Driver& driver, int newExperience);
void DriverSetRacecraft(Driver& driver, int newRacecraft);
void DriverSetAwareness(Driver& driver, int newAwareness);
void DriverSetPace(Driver& driver, int newPace);
void DriverSetSalary(Driver& driver, double newSalary);
void DriverGetInfo(Driver& driver);

bool DriverIsDriverHired(Driver& driver);
string DriverReturnDriverName(Driver& driver);