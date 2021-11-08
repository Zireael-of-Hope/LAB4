﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Facility.h"
#include "Vehicle.h"
#include "Driver.h"
#include "Sponsor.h"

class MyF1Team {
public:
	Driver firstDriver;
	Driver secondDriver;
	Vehicle w11_1;
	Vehicle w11_2;
	Facility facility;
	Sponsor mainSponsor;
	Sponsor secondarySponsor;

	MyF1Team() {};
	~MyF1Team() {};
	void interactSlot();

	void getTeamInfo();

	void changeDriver();
	void sub_changeDriver(int whichDriver, std::string& tempString, int& tempInt);


	void changeVehicle();
	void sub_changeVehicle(int carNumber, bool& isPass, char& decision, std::string& tempString, bool& isCycled);
	void sub_changeVehicle_stickers(bool& isCycled, int carNumber, bool& isPass, char& decision, std::string& tempString);
	void sub_changeVehicle_driver(bool& isPass, char& decision, int carNumber, bool& isCycled);
	void changeSponsor();
	void upgradeFacility();
};

int choosingTeam(MyF1Team* team[]);

int main()
{
	bool isPass;
	int decision;
	MyF1Team* team[3] = { nullptr, nullptr, nullptr };

	do {
		system("cls");
		isPass = false;
		decision = choosingTeam(team);
		if (decision != 3) {
			team[decision]->interactSlot();
		}
	} while (isPass == false);
}

int choosingTeam(MyF1Team* team[])
{
	bool isPass;
	char decision;
	int i;

	for (i = 0; i < 3; i++) {
		cout << i + 1 << ") ";
		if (team[i] != nullptr) {
			SetColor(14, 0);
			cout << "\nDrivers:" << endl;
			SetColor(15, 0);
			team[i]->firstDriver.getInfoDriver();
			team[i]->secondDriver.getInfoDriver();

			SetColor(14, 0);
			cout << "\nVehicles:" << endl;
			SetColor(15, 0);
			cout << "1) "; team[i]->w11_1.getInfoVehicleName();
			cout << "2) "; team[i]->w11_2.getInfoVehicleName();
		}
		else {
			cout << "Empty Slot\n" << endl;
		}
	}

	cout << "Enter slot you want to modify. (4 - clear 1 slot, 5 - clear 2 slot, 6 - clear - 3 slot)... ";

	do {
		isPass = false;
		decision = _getch();
		if (decision >= 49 && decision <= 54)
			isPass = true;
	} while (isPass == false);

	switch (decision) {
	case '1':
		team[0] = new MyF1Team;
		return 0;
		break;
	case '2':
		team[1] = new MyF1Team;
		return 1;
		break;
	case '3':
		team[2] = new MyF1Team;
		return 2;
		break;
	case '4':
		if (team[0] != nullptr) {
			delete team[0];
			team[0] = nullptr;
			return 3;
		}
		else return 3;
		break;
	case '5':
		if (team[1] != nullptr) {
			delete team[1];
			team[1] = nullptr;
			return 3;
		}
		else return 3;
		break;
	case '6':
		if (team[2] != nullptr) {
			delete team[2];
			team[2] = nullptr;
			return 3;
		}
		else return 3;
		break;
	}
}

void MyF1Team::interactSlot()
{
	char decision;
	bool isPass, isCycled;

	do {
		isCycled = true;
		getTeamInfo();

		cout << "1) Change Driver" << endl;
		cout << "2) Change Vehicle" << endl;
		cout << "3) Change Sponsor" << endl;
		cout << "4) Upgrade Facilities" << endl;
		cout << "5) Return" << endl;

		do {
			isPass = false;
			decision = _getch();
			if (decision >= 49 && decision <= 53)
				isPass = true;
		} while (isPass == false);

		switch (decision) {
		case '1':
			changeDriver();
			isCycled = true;
			break;
		case '2':
			changeVehicle();
			isCycled = true;
			break;
		case '3':
			changeSponsor();
			break;
		case '4':
			upgradeFacility();
			break;
		case '5': 
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}

void MyF1Team::getTeamInfo()
{
	system("cls");

	SetColor(14, 0);
	cout << "F1 Team: \n" << endl;
	SetColor(15, 0);

	if (firstDriver.isDriverHired()) {
		cout << "1) ";
		firstDriver.getInfoDriver();
	}
	else {
		SetColor(14, 0);
		cout << "1) Driver";
		SetColor(15, 0);
		cout << " not hired" << endl;
	}

	if (secondDriver.isDriverHired()) {
		cout << "\n2) ";
		secondDriver.getInfoDriver();
	}
	else {
		SetColor(14, 0);
		cout << "\n2) Driver";
		SetColor(15, 0);
		cout << " not hired" << endl;
	}

	SetColor(14, 0);
	cout << "\nVehicle 1: " << endl;
	SetColor(15, 0);
	w11_1.getInfoVehicle();

	SetColor(14, 0);
	cout << "\nVehicle 2: " << endl;
	SetColor(15, 0);
	w11_2.getInfoVehicle();

	SetColor(14, 0);
	cout << "\nMain Sponsor: " << endl;
	SetColor(15, 0);
	mainSponsor.getInfoSponsor();

	SetColor(14, 0);
	cout << "\nSecondary Sponsor: " << endl;
	SetColor(15, 0);
	secondarySponsor.getInfoSponsor();

	SetColor(14, 0);
	cout << "\nFacilities:" << endl;
	SetColor(15, 0);
	facility.getInfoBureauAerodynamics();
	facility.getInfoBureauPowertrain();
	facility.getInfoBureauChassis();
	facility.getInfoBureauDurability();
}

void MyF1Team::changeDriver()
{
	char decision;
	bool isPass, isCycled;
	string tempString;
	int tempInt;

	do {
		isCycled = true;
		system("cls");
		cout << "1) Change First Driver" << endl;
		cout << "2) Change Second Driver" << endl;
		cout << "3) Return" << endl;

		do {
			isPass = false;
			decision = _getch();
			if (decision >= 49 && decision <= 51)
				isPass = true;
		} while (isPass == false);

		switch (decision) {
		case '1':
			sub_changeDriver(1, tempString, tempInt);
			break;
		case '2':
			sub_changeDriver(2, tempString, tempInt);
			break;
		case '3':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1Team::sub_changeDriver(int whichDriver, std::string& tempString, int& tempInt)
{
	system("cls");

	cout << "Enter Driver's Name: ";
	getline(cin, tempString);
	if (whichDriver == 1) firstDriver.setDriverName(tempString);
	else secondDriver.setDriverName(tempString);

	cout << "Enter Driver's Number: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.setDriverNumber(tempInt);
	else secondDriver.setDriverNumber(tempInt);

	cout << "Enter Driver's Overall Rating: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.setDriverOverallRating(tempInt);
	else secondDriver.setDriverOverallRating(tempInt);

	cout << "Enter Driver's Experience: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.setDriverExperience(tempInt);
	else secondDriver.setDriverExperience(tempInt);

	cout << "Enter Driver's Racecraft: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.setDriverRacecraft(tempInt);
	else secondDriver.setDriverRacecraft(tempInt);

	cout << "Enter Driver's Awareness: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.setDriverAwareness(tempInt);
	else secondDriver.setDriverAwareness(tempInt);

	cout << "Enter Driver's Pace: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.setDriverPace(tempInt);
	else secondDriver.setDriverPace(tempInt);

	if (whichDriver == 1) {
		if (mainSponsor.getPaymentPerRace() == 0) {
			cout << "Driver's salary can't be set because of main sponsor's payment isn't defined yet" << endl;
			Sleep(1500);
		}
		else {
			cout << "Enter Driver's Salary: ";
			cin >> tempInt;
			cin.get();
			firstDriver.setDriverSalary_interface(mainSponsor.getPaymentPerRace());
		}
	} 
	else {
		if (secondarySponsor.getPaymentPerRace() == 0) {
			cout << "Driver's salary can't be set because of main sponsor's payment isn't defined yet" << endl;
			Sleep(1500);
		}
		else {
			cout << "Enter Driver's Salary: ";
			cin >> tempInt;
			cin.get();
			secondDriver.setDriverSalary_interface(secondarySponsor.getPaymentPerRace());
		}
	}

	SetColor(14, 0);
	cout << "\nInfo has been updated";
	SetColor(15, 0);
	Sleep(1500);
}

void MyF1Team::changeVehicle()
{
	char decision;
	bool isPass, isCycled;
	string tempString;
	int tempInt;


	do {
		system("cls");

		isCycled = true;
		cout << "1) Change Vehicle 1" << endl;
		cout << "2) Change Vehicle 2" << endl;
		cout << "3) Return\n" << endl;

		do {
			isPass = false;
			decision = _getch();
			if (decision >= 49 && decision <= 51)
				isPass = true;
		} while (isPass == false);

		switch (decision) {
		case '1':
			sub_changeVehicle(1, isPass, decision, tempString, isCycled);
			isCycled = true;
			break;
		case '2':
			sub_changeVehicle(2, isPass, decision, tempString, isCycled);
			isCycled = true;
			break;
		case '3':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1Team::sub_changeVehicle(int carNumber, bool& isPass, char& decision, std::string& tempString, bool& isCycled)
{
	do {
		isCycled = true;
		system("cls");

		cout << "1) Change Vehicle name" << endl;
		cout << "2) Change Vehicle driver" << endl;
		cout << "3) Change Vehicle components" << endl;
		cout << "4) Sticker Management" << endl;
		cout << "5) Return\n" << endl;

		do {
			isPass = false;
			decision = _getch();
			if (decision >= 49 && decision <= 53)
				isPass = true;
		} while (isPass == false);

		switch (decision) {
		case '1':
			system("cls");

			cout << "Enter new Vehicle Name: ";
			getline(cin, tempString);
			if (carNumber == 1) w11_1.setVehicleName(tempString);
			else w11_2.setVehicleName(tempString);

			SetColor(14, 0);
			cout << "Name has been changed";
			SetColor(15, 0);

			Sleep(1500);
			break;
		case '2':
			sub_changeVehicle_driver(isPass, decision, carNumber, isCycled);
			isCycled = true;
			break;
		case '3':
			if (carNumber == 1) w11_1.setVehicleComponents_interface();
			else w11_2.setVehicleComponents_interface();
			isCycled = true;
			break;
		case '4':
			sub_changeVehicle_stickers(isCycled, carNumber, isPass, decision, tempString);
			isCycled = true;
			break;
		case '5':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1Team::sub_changeVehicle_stickers(bool& isCycled, int carNumber, bool& isPass, char& decision, std::string& tempString)
{
	do {
		isCycled = true;
		system("cls");
		SetColor(14, 0);
		cout << "Stickers on the Vehicle:" << endl;
		SetColor(15, 0);
		if (carNumber == 1)
			w11_1.getSponsorStickers();
		else w11_2.getSponsorStickers();

		cout << "\n1) Add Sticker on the Vehicle" << endl;
		cout << "2) Delete Sticker on the Vehicle" << endl;
		cout << "3) Return\n" << endl;

		do {
			isPass = false;
			decision = _getch();
			if (decision >= 49 && decision <= 51)
				isPass = true;
		} while (isPass == false);

		switch (decision) {
		case '1':
			system("cls");

			cout << "Enter name of the new sticker: ";
			getline(cin, tempString);
			if (carNumber == 1)
				w11_1.addSponsorSticker(tempString);
			else w11_2.addSponsorSticker(tempString);

			SetColor(14, 0);
			cout << "\nSticker has been added";
			SetColor(15, 0);

			Sleep(1500);
			break;
		case '2':
			system("cls");

			cout << "Enter name of the sticker to delete: ";
			getline(cin, tempString);

			SetColor(14, 0);
			if (carNumber == 1)
			{
				if (w11_1.deleteSponsorSticker(tempString) == true) {
					cout << "\nSticker has been deleted";
					SetColor(15, 0);
				}
				else {
					cout << "\nSticker with this name doesn't exist";
					SetColor(15, 0);
				}
			}
			else
			{
				if (w11_2.deleteSponsorSticker(tempString) == true) {
					cout << "\nSticker has been deleted";
					SetColor(15, 0);
				}
				else {
					cout << "\nSticker with this name doesn't exist";
					SetColor(15, 0);
				}
			}

			Sleep(1500);
			break;
		case '3':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1Team::sub_changeVehicle_driver(bool& isPass, char& decision, int carNumber, bool& isCycled)
{
	do {
		system("cls");

		cout << "Which Driver you want to assign on this Vehicle:" << endl;
		firstDriver.getInfoDriver();
		puts("");
		secondDriver.getInfoDriver();

		cout << "1) Assign First Driver" << endl;
		cout << "2) Assign Second Driver" << endl;
		cout << "3) Return\n" << endl;

		do {
			isPass = false;
			decision = _getch();
			if (decision >= 49 && decision <= 51)
				isPass = true;
		} while (isPass == false);

		switch (decision) {
		case '1':
			if (firstDriver.isDriverHired() == true) {
				if (carNumber == 1)
					w11_1.setVehicleDriver(firstDriver.returnDriverName());
				else w11_2.setVehicleDriver(firstDriver.returnDriverName());
			}
			else {
				cout << "Driver isn't hired yet";
				Sleep(1500);
			}
			break;
		case '2':
			if (secondDriver.isDriverHired() == true) {
				if (carNumber == 1)
					w11_1.setVehicleDriver(secondDriver.returnDriverName());
				else w11_2.setVehicleDriver(secondDriver.returnDriverName());
			}
			else {
				cout << "Driver isn't hired yet";
				Sleep(1500);
			}
			break;
		case '3':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}

void MyF1Team::changeSponsor()
{
	char decision;
	bool isPass, isCycled;
	string tempString;
	int tempInt;

	system("cls");

	cout << "1) Change Main Sponsor"
}
void MyF1Team::upgradeFacility()
{

}
