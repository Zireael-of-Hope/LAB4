#pragma once
#include <iostream>
#include <string>

#include "Color.h"

using namespace std;

struct Driver
{
	string name = "NoName";
	int number = 0;

	int overallRating = 0;
	int experience = 0;
	int racecraft = 0;
	int awareness = 0;
	int pace = 0;
	double salary = 0;
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