#pragma once
#include <iostream>
#include <string>
#include "Color.h"
using namespace std;

class Driver
{
private:
	string name_ = "NoName";
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

	void setDriverName(string newName);
	void setDriverNumber(int newNumber);
	void setDriverOverallRating(int newOverallRating);
	void setDriverExperience(int newExperience);
	void setDriverRacecraft(int newRacecraft);
	void setDriverAwareness(int newAwareness);
	void setDriverPace(int newPace);
	void setDriverSalary_interface(double sponsorSalary);
	void getInfoDriver();

	bool isDriverHired();
	string returnDriverName();
};

