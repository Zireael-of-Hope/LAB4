#pragma once
#include <iostream>
#include <string>

#include "Color.h"

using namespace std;

class Driver
{
private:
	string name = "NoName";
	int number = 0;

	int overallRating = 0;
	int experience = 0;
	int racecraft = 0;
	int awareness = 0;
	int pace = 0;
	double salary = 0;

public:
	Driver();
	~Driver();

	void SetName(string newName);
	void SetNumber(int newNumber);
	void SetOverallRating(int newOverallRating);
	void SetExperience(int newExperience);
	void SetRacecraft(int newRacecraft);
	void SetAwareness(int newAwareness);
	void SetPace(int newPace);
	void SetSalary(double newSalary);
	void GetInfo();
	string GetName();

	bool isDriverHired();
	string returnDriverName();
};
