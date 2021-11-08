#include "Driver.h"

Driver::Driver()
{
	name_ = "NoName";
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

void Driver::setDriverName(string newName)
{
	name_ = newName;
}

void Driver::setDriverNumber(int newNumber)
{
	number_ = newNumber;
}

void Driver::setDriverOverallRating(int newOverallRating)
{
	overallRating_ = newOverallRating;
}

void Driver::setDriverExperience(int newExperience)
{
	experience_ = newExperience;
}

void Driver::setDriverRacecraft(int newRacecraft)
{
	racecraft_ = newRacecraft;
}

void Driver::setDriverAwareness(int newAwareness)
{
	awareness_ = newAwareness;
}

void Driver::setDriverPace(int newPace)
{
	pace_ = newPace;
}

void Driver::setDriverSalary_interface(double sponsorSalary)
{
	double decision;
	bool isPass;

	cout << "Enter the percentage of the sponsorship payment (current sponsor's payment: " << sponsorSalary << "): ";

	do {
		isPass = false;
		cin >> decision;
		cin.get();
		if (decision >= 0 && decision <= 100)
			isPass = true;
	} while (isPass == false);
	cin.get();

	salary_ = sponsorSalary * (decision / 100);
}

void Driver::getInfoDriver()
{
	SetColor(14, 0);
	cout << "Driver ";
	SetColor(15, 0);

	cout << name_ << " " << number_ << endl;
	cout << "    " << "Overall rating: " << overallRating_ << endl;
	cout << "    " << "Experience: " << experience_ << endl;
	cout << "    " << "Racecraft: " << racecraft_ << endl;
	cout << "    " << "Awareness: " << awareness_ << endl;
	cout << "    " << "Pace: " << pace_ << endl;
}

bool Driver::isDriverHired()
{
	if (name_ == "NoName")
		return false;
	else
		return true;
}

string Driver::returnDriverName()
{
	return name_;
}