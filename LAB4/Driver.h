#pragma once
#include <iostream>
#include <string>

#include "Color.h"

using namespace std;

class Driver
{
private:
	string name = "NoName";
	int number_ = 0;

	int overallRating_ = 0;
	int experience_ = 0;
	int racecraft_ = 0;
	int awareness_ = 0;
	int pace_ = 0;

	double salary_ = 0;

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

	bool isDriverHired();
	string returnDriverName();
};

