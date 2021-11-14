#include "Team.h"
void initMyF1Team(MyF1Team& team)
{
	initDriver(team.firstDriver);
	initDriver(team.secondDriver);

	initVehicle(team.w11_1);
	initVehicle(team.w11_2);

	initFacility(team.facility);

	initSponsor(team.mainSponsor);
	initSponsor(team.secondarySponsor);
}

void MyF1TeamInteractSlot(MyF1Team& team)
{
	char decision;
	bool isPass, isCycled;

	do {
		isCycled = true;
		MyF1TeamGetTeamInfo(team);

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
			MyF1TeamChangeDriver(team);
			isCycled = true;
			break;
		case '2':
			MyF1TeamChangeVehicle(team);
			isCycled = true;
			break;
		case '3':
			MyF1TeamChangeSponsor(team);
			break;
		case '4':
			FacilitySetBureausLevel_interface(team.facility);
			break;
		case '5':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1TeamGetTeamInfo(MyF1Team& team)
{
	system("cls");

	SetColor(14, 0);
	cout << "F1 Team: \n" << endl;
	SetColor(15, 0);

	if (DriverIsDriverHired(team.firstDriver)) {
		cout << "1) ";
		DriverGetInfo(team.firstDriver);
	}
	else {
		SetColor(14, 0);
		cout << "1) Driver";
		SetColor(15, 0);
		cout << " not hired" << endl;
	}

	if (DriverIsDriverHired(team.secondDriver)) {
		cout << "\n2) ";
		DriverGetInfo(team.secondDriver);
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
	VehicleGetInfo(team.w11_1);

	SetColor(14, 0);
	cout << "\nVehicle 2: " << endl;
	SetColor(15, 0);
	VehicleGetInfo(team.w11_2);

	SetColor(14, 0);
	cout << "\nMain Sponsor: " << endl;
	SetColor(15, 0);
	SponsorGetInfo(team.mainSponsor);

	SetColor(14, 0);
	cout << "\nSecondary Sponsor: " << endl;
	SetColor(15, 0);
	SponsorGetInfo(team.secondarySponsor);

	SetColor(14, 0);
	cout << "\nFacilities:" << endl;
	SetColor(15, 0);
	FacilityGetInfoAerodynamics(team.facility);
	FacilityGetInfoPowertrain(team.facility);
	FacilityGetInfoChassis(team.facility);
	FacilityGetInfoDurability(team.facility);
}

void MyF1TeamChangeDriver(MyF1Team& team)
{
	char decision;
	bool isPass, isCycled;
	string tempString;
	int tempInt;
	double tempDouble;

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
			MyF1TeamSubChangeDriver(team, 1, tempString, tempInt, tempDouble);
			break;
		case '2':
			MyF1TeamSubChangeDriver(team, 2, tempString, tempInt, tempDouble);
			break;
		case '3':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1TeamSubChangeDriver(MyF1Team& team, int whichDriver, std::string& tempString, int& tempInt, double& tempDouble)
{
	system("cls");

	cout << "Enter Driver's Name: ";
	getline(cin, tempString);
	if (whichDriver == 1) DriverSetName(team.firstDriver, tempString);
	else DriverSetName(team.secondDriver, tempString);

	cout << "Enter Driver's Number: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) DriverSetNumber(team.firstDriver, tempInt);
	else DriverSetName(team.secondDriver, tempString);

	cout << "Enter Driver's Overall Rating: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) DriverSetOverallRating(team.firstDriver, tempInt);
	else DriverSetName(team.secondDriver, tempString);

	cout << "Enter Driver's Experience: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) DriverSetExperience(team.firstDriver, tempInt);
	else DriverSetName(team.secondDriver, tempString);

	cout << "Enter Driver's Racecraft: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) DriverSetRacecraft(team.firstDriver, tempInt);
	else DriverSetName(team.secondDriver, tempString);

	cout << "Enter Driver's Awareness: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) DriverSetAwareness(team.firstDriver, tempInt);
	else DriverSetName(team.secondDriver, tempString);

	cout << "Enter Driver's Pace: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) DriverSetPace(team.firstDriver, tempInt);
	else DriverSetName(team.secondDriver, tempString);

	cout << "Enter Driver's salary: ";
	cin >> tempDouble;
	cin.get();
	if (whichDriver == 1) DriverSetSalary(team.firstDriver, tempDouble);
	else DriverSetName(team.secondDriver, tempString);

	SetColor(14, 0);
	cout << "\nInfo has been updated";
	SetColor(15, 0);
	Sleep(1500);
}

void MyF1TeamChangeVehicle(MyF1Team& team)
{
	char decision;
	bool isPass, isCycled;
	string tempString;

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
			MyF1TeamSubchangeVehicle(team, 1, isPass, decision, tempString, isCycled);
			isCycled = true;
			break;
		case '2':
			MyF1TeamSubchangeVehicle(team, 2, isPass, decision, tempString, isCycled);
			isCycled = true;
			break;
		case '3':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1TeamSubchangeVehicle(MyF1Team& team, int carNumber, bool& isPass, char& decision, std::string& tempString, bool& isCycled)
{
	do {
		isCycled = true;
		system("cls");

		cout << "1) Change Vehicle name" << endl;
		cout << "2) Change Vehicle driver" << endl;
		cout << "3) Change Vehicle components" << endl;
		cout << "4) Sticker Management" << endl;
		cout << "5) Update Vehicle total component wear ratio due to facilities level" << endl;
		cout << "6) Return\n" << endl;

		do {
			isPass = false;
			decision = _getch();
			if (decision >= 49 && decision <= 54)
				isPass = true;
		} while (isPass == false);

		switch (decision) {
		case '1':
			system("cls");

			cout << "Enter new Vehicle Name: ";
			getline(cin, tempString);
			if (carNumber == 1) VehicleSetName(team.w11_1, tempString);
			else VehicleSetName(team.w11_2, tempString);

			SetColor(14, 0);
			cout << "Name has been changed";
			SetColor(15, 0);

			Sleep(1500);
			break;
		case '2':
			MyF1TeamSubchangeVehicle_driver(team, isPass, decision, carNumber, isCycled);
			isCycled = true;
			break;
		case '3':
			if (carNumber == 1) VehicleSetComponents_interface(team.w11_1);
			else VehicleSetComponents_interface(team.w11_2);
			isCycled = true;
			break;
		case '4':
			MyF1TeamSubchangeVehicle_stickers(team, isCycled, carNumber, isPass, decision, tempString);
			isCycled = true;
			break;
		case '5':
			if (carNumber == 1) VehicleSetTotalComponentWearRatio(team.w11_1, FacilityReturnAerodynamicsLevel(team.facility), FacilityReturnPowertrainLevel(team.facility), FacilityReturnChassisLevel(team.facility), FacilityReturnDurabilityLevel(team.facility));
			else VehicleSetTotalComponentWearRatio(team.w11_2, FacilityReturnAerodynamicsLevel(team.facility), FacilityReturnPowertrainLevel(team.facility), FacilityReturnChassisLevel(team.facility), FacilityReturnDurabilityLevel(team.facility));
			break;
		case '6':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1TeamSubchangeVehicle_stickers(MyF1Team& team, bool& isCycled, int carNumber, bool& isPass, char& decision, std::string& tempString)
{
	do {
		isCycled = true;
		system("cls");
		SetColor(14, 0);
		cout << "Stickers on the Vehicle:" << endl;
		SetColor(15, 0);
		if (carNumber == 1)
			VehicleGetSponsorStickers(team.w11_1);
		else VehicleGetSponsorStickers(team.w11_2);

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
				VehicleAddSponsorSticker(team.w11_1, tempString);
			else VehicleAddSponsorSticker(team.w11_2, tempString);

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
				if (VehicleDeleteSponsorSticker(team.w11_1, tempString) == true) {
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
				if (VehicleDeleteSponsorSticker(team.w11_1, tempString) == true) {
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
void MyF1TeamSubchangeVehicle_driver(MyF1Team& team, bool& isPass, char& decision, int carNumber, bool& isCycled)
{
	do {
		system("cls");

		cout << "Which Driver you want to assign on this Vehicle:" << endl;
		DriverGetInfo(team.firstDriver);
		puts("");
		DriverGetInfo(team.secondDriver);

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
			if (DriverIsDriverHired(team.firstDriver)) {
				if (carNumber == 1)
					VehicleSetDriver(team.w11_1, team.firstDriver);
				else VehicleSetDriver(team.w11_2, team.firstDriver);
			}
			else {
				cout << "Driver isn't hired yet";
				Sleep(1500);
			}
			break;
		case '2':
			if (DriverIsDriverHired(team.secondDriver)) {
				if (carNumber == 1)
					VehicleSetDriver(team.w11_1, team.secondDriver);
				else VehicleSetDriver(team.w11_2, team.secondDriver);
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

void MyF1TeamChangeSponsor(MyF1Team& team)
{
	char decision;
	bool isPass, isCycled;
	string tempString;
	double tempDouble;

	do {
		system("cls");
		isCycled = true;

		cout << "1) Change Main Sponsor" << endl;
		cout << "2) Change Secondary Sponsor" << endl;
		cout << "3) Return" << endl;

		do {
			isPass = false;
			decision = _getch();
			if (decision >= 49 && decision <= 51)
				isPass = true;
		} while (isPass == false);

		switch (decision) {
		case '1':
			MyF1TeamSubChangeSposnor(team, 1, tempString, tempDouble);
			isCycled = true;
			break;
		case '2':
			MyF1TeamSubChangeSposnor(team, 2, tempString, tempDouble);
			break;
		case '3':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1TeamSubChangeSposnor(MyF1Team& team, int whichSponsor, std::string& tempString, double& tempDouble)
{
	system("cls");

	cout << "Enter name of the main sponsor: ";
	getline(cin, tempString);
	if (whichSponsor == 1) SponsorSetName(team.mainSponsor, tempString);
	else SponsorSetName(team.secondarySponsor, tempString);

	puts("");
	if (whichSponsor == 1) SponsorSetColor_interface(team.mainSponsor);
	else SponsorSetColor_interface(team.secondarySponsor);

	puts("");
	if (whichSponsor == 1) SponsorSetTargetRace_interface(team.mainSponsor);
	else SponsorSetTargetRace_interface(team.secondarySponsor);

	puts("\n");
	if (whichSponsor == 1) SponsorSetTargetSeason_interface(team.mainSponsor);
	else SponsorSetTargetSeason_interface(team.secondarySponsor);

	puts("\n");
	cout << "Enter sponsor's payment per race: ";
	cin >> tempDouble;
	cin.get();
	if (whichSponsor == 1) SponsorSetPaymentPerRace(team.mainSponsor, tempDouble);
	else SponsorSetPaymentPerRace(team.secondarySponsor, tempDouble);

	cout << "\nEnter sponsor's target bonus ratio: ";
	cin >> tempDouble;
	cin.get();
	if (whichSponsor == 1) SponsorSetTargetBonusRatio(team.mainSponsor, tempDouble);
	else SponsorSetTargetBonusRatio(team.secondarySponsor, tempDouble);
}
