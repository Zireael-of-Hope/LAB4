#include "Driver.h"

Driver::Driver()
{
	name = "NoName";
	number_ = 0;
	overallRating_ = 0;
	experience_ = 0;
	racecraft_ = 0;
	awareness_ = 0;
	pace_ = 0;
	salary_ = 0;
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
	number_ = newNumber;
}

void Driver::SetOverallRating(int newOverallRating)
{
	overallRating_ = newOverallRating;
}

void Driver::SetExperience(int newExperience)
{
	experience_ = newExperience;
}

void Driver::SetRacecraft(int newRacecraft)
{
	racecraft_ = newRacecraft;
}

void Driver::SetAwareness(int newAwareness)
{
	awareness_ = newAwareness;
}

void Driver::SetPace(int newPace)
{
	pace_ = newPace;
}

void Driver::SetSalary(double newSalary)
{
	salary_ = newSalary;
}

void Driver::GetInfo()
{
	SetColor(14, 0);
	cout << "Driver ";
	SetColor(15, 0);

	cout << name << " " << number_ << endl;
	cout << "    " << "Overall rating: " << overallRating_ << endl;
	cout << "    " << "Experience: " << experience_ << endl;
	cout << "    " << "Racecraft: " << racecraft_ << endl;
	cout << "    " << "Awareness: " << awareness_ << endl;
	cout << "    " << "Pace: " << pace_ << endl;
	cout << "    " << "Salary: " << salary_ << "%" << endl;
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