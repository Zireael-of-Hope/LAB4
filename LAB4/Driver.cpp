#include "Driver.h"

Driver::Driver()
{
	name = "NoName";
	number = 0;
	overallRating = 0;
	experience = 0;
	racecraft = 0;
	awareness = 0;
	pace = 0;
	salary = 0;
}

Driver::~Driver()
{
}

void Driver::SetName(string newName)
{
	name = newName;
}

void Driver::SetNumber(int newNumber)
{
	number = newNumber;
}

void Driver::SetOverallRating(int newOverallRating)
{
	overallRating = newOverallRating;
}

void Driver::SetExperience(int newExperience)
{
	experience = newExperience;
}

void Driver::SetRacecraft(int newRacecraft)
{
	racecraft = newRacecraft;
}

void Driver::SetAwareness(int newAwareness)
{
	awareness = newAwareness;
}

void Driver::SetPace(int newPace)
{
	pace = newPace;
}

void Driver::SetSalary(double newSalary)
{
	salary = newSalary;
}

void Driver::GetInfo()
{
	SetColor(14, 0);
	cout << "Driver ";
	SetColor(15, 0);

	cout << name << " " << number << endl;
	cout << "    " << "Overall rating: " << overallRating << endl;
	cout << "    " << "Experience: " << experience << endl;
	cout << "    " << "Racecraft: " << racecraft << endl;
	cout << "    " << "Awareness: " << awareness << endl;
	cout << "    " << "Pace: " << pace << endl;
	cout << "    " << "Salary: " << salary << "%" << endl;
}

bool Driver::isDriverHired()
{
	if (name == "NoName")
		return false;
	else
		return true;
}

string Driver::returnDriverName()
{
	return name;
}