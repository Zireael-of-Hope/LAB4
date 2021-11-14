#include "Driver.h"

void initDriver(Driver& driver)
{
	driver.name = "NoName";
	driver.number_ = 0;
	driver.overallRating_ = 0;
	driver.experience_ = 0;
	driver.racecraft_ = 0;
	driver.awareness_ = 0;
	driver.pace_ = 0;
	driver.salary_ = 0;
}

void DriverSetName(Driver& driver, string newName)
{
	driver.name = newName;
}

void DriverSetNumber(Driver& driver, int newNumber)
{
	driver.number_ = newNumber;
}

void DriverSetOverallRating(Driver& driver, int newOverallRating)
{
	driver.overallRating_ = newOverallRating;
}

void DriverSetExperience(Driver& driver, int newExperience)
{
	driver.experience_ = newExperience;
}

void DriverSetRacecraft(Driver& driver, int newRacecraft)
{
	driver.racecraft_ = newRacecraft;
}

void DriverSetAwareness(Driver& driver, int newAwareness)
{
	driver.awareness_ = newAwareness;
}

void DriverSetPace(Driver& driver, int newPace)
{
	driver.pace_ = newPace;
}

void DriverSetSalary(Driver& driver, double newSalary)
{
	driver.salary_ = newSalary;
}

void DriverGetInfo(Driver& driver)
{
	SetColor(14, 0);
	cout << "Driver ";
	SetColor(15, 0);

	cout << driver.name << " " << driver.number_ << endl;
	cout << "    " << "Overall rating: " << driver.overallRating_ << endl;
	cout << "    " << "Experience: " << driver.experience_ << endl;
	cout << "    " << "Racecraft: " << driver.racecraft_ << endl;
	cout << "    " << "Awareness: " << driver.awareness_ << endl;
	cout << "    " << "Pace: " << driver.pace_ << endl;
	cout << "    " << "Salary: " << driver.salary_ << endl;
}

bool DriverIsDriverHired(Driver& driver)
{
	if (driver.name == "NoName")
		return false;
	else
		return true;
}

string DriverReturnDriverName(Driver& driver)
{
	return driver.name;
}