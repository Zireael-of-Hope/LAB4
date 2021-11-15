#include "Driver.h"

void initDriver(Driver& driver)
{
	driver.name = "NoName";
	driver.number = 0;
	driver.overallRating = 0;
	driver.experience = 0;
	driver.racecraft = 0;
	driver.awareness = 0;
	driver.pace = 0;
	driver.salary = 0;
}

void DriverSetName(Driver& driver, string newName)
{
	driver.name = newName;
}

void DriverSetNumber(Driver& driver, int newNumber)
{
	driver.number = newNumber;
}

void DriverSetOverallRating(Driver& driver, int newOverallRating)
{
	driver.overallRating = newOverallRating;
}

void DriverSetExperience(Driver& driver, int newExperience)
{
	driver.experience = newExperience;
}

void DriverSetRacecraft(Driver& driver, int newRacecraft)
{
	driver.racecraft = newRacecraft;
}

void DriverSetAwareness(Driver& driver, int newAwareness)
{
	driver.awareness = newAwareness;
}

void DriverSetPace(Driver& driver, int newPace)
{
	driver.pace = newPace;
}

void DriverSetSalary(Driver& driver, double newSalary)
{
	driver.salary = newSalary;
}

void DriverGetInfo(Driver& driver)
{
	SetColor(14, 0);
	cout << "Driver ";
	SetColor(15, 0);

	cout << driver.name << " " << driver.number << endl;
	cout << "    " << "Overall rating: " << driver.overallRating << endl;
	cout << "    " << "Experience: " << driver.experience << endl;
	cout << "    " << "Racecraft: " << driver.racecraft << endl;
	cout << "    " << "Awareness: " << driver.awareness << endl;
	cout << "    " << "Pace: " << driver.pace << endl;
	cout << "    " << "Salary: " << driver.salary << endl;
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