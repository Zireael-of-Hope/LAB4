#include "Team.h"

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
			facility.SetFacilityBureausLevel_interface();
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
		firstDriver.GetInfo();
	}
	else {
		SetColor(14, 0);
		cout << "1) Driver";
		SetColor(15, 0);
		cout << " not hired" << endl;
	}

	if (secondDriver.isDriverHired()) {
		cout << "\n2) ";
		secondDriver.GetInfo();
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
	w11_1.GetInfo();

	SetColor(14, 0);
	cout << "\nVehicle 2: " << endl;
	SetColor(15, 0);
	w11_2.GetInfo();

	SetColor(14, 0);
	cout << "\nMain Sponsor: " << endl;
	SetColor(15, 0);
	mainSponsor.GetInfoSponsor();

	SetColor(14, 0);
	cout << "\nSecondary Sponsor: " << endl;
	SetColor(15, 0);
	secondarySponsor.GetInfoSponsor();

	SetColor(14, 0);
	cout << "\nFacilities:" << endl;
	SetColor(15, 0);
	facility.GetInfoBureauAerodynamics();
	facility.GetInfoBureauPowertrain();
	facility.GetInfoBureauChassis();
	facility.GetInfoBureauDurability();
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
	if (whichDriver == 1) firstDriver.SetName(tempString);
	else secondDriver.SetName(tempString);

	cout << "Enter Driver's Number: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.SetNumber(tempInt);
	else secondDriver.SetNumber(tempInt);

	cout << "Enter Driver's Overall Rating: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.SetOverallRating(tempInt);
	else secondDriver.SetOverallRating(tempInt);

	cout << "Enter Driver's Experience: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.SetExperience(tempInt);
	else secondDriver.SetExperience(tempInt);

	cout << "Enter Driver's Racecraft: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.SetRacecraft(tempInt);
	else secondDriver.SetRacecraft(tempInt);

	cout << "Enter Driver's Awareness: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.SetAwareness(tempInt);
	else secondDriver.SetAwareness(tempInt);

	cout << "Enter Driver's Pace: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.SetPace(tempInt);
	else secondDriver.SetPace(tempInt);

	cout << "Enter Driver's salary: ";
	cin >> tempInt;
	cin.get();
	if (whichDriver == 1) firstDriver.SetSalary(tempInt);
	else secondDriver.SetSalary(tempInt);

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
			if (carNumber == 1) w11_1.SetName(tempString);
			else w11_2.SetName(tempString);

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
			if (carNumber == 1) w11_1.SetComponents_interface();
			else w11_2.SetComponents_interface();
			isCycled = true;
			break;
		case '4':
			sub_changeVehicle_stickers(isCycled, carNumber, isPass, decision, tempString);
			isCycled = true;
			break;
		case '5':
			if (carNumber == 1) w11_1.SetTotalComponentWearRatio(facility.ReturnAerodynamicsLevel(), facility.ReturnPowertrainLevel(), facility.ReturnChassisLevel(), facility.ReturnDurabilityLevel());
			else w11_2.SetTotalComponentWearRatio(facility.ReturnAerodynamicsLevel(), facility.ReturnPowertrainLevel(), facility.ReturnChassisLevel(), facility.ReturnDurabilityLevel());
			break;
		case '6':
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
			w11_1.GetSponsorStickers();
		else w11_2.GetSponsorStickers();

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
				w11_1.AddSponsorSticker(tempString);
			else w11_2.AddSponsorSticker(tempString);

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
				if (w11_1.DeleteSponsorSticker(tempString) == true) {
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
				if (w11_2.DeleteSponsorSticker(tempString) == true) {
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
		firstDriver.GetInfo();
		puts("");
		secondDriver.GetInfo();

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
					w11_1.SetDriver(firstDriver);
				else w11_2.SetDriver(firstDriver);
			}
			else {
				cout << "Driver isn't hired yet";
				Sleep(1500);
			}
			break;
		case '2':
			if (secondDriver.isDriverHired() == true) {
				if (carNumber == 1)
					w11_1.SetDriver(secondDriver);
				else w11_2.SetDriver(secondDriver);
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
			sub_changeSposnor(1, tempString, tempDouble);
			isCycled = true;
			break;
		case '2':
			sub_changeSposnor(2, tempString, tempDouble);
			break;
		case '3':
			isCycled = false;
			break;
		}
	} while (isCycled == true);
}
void MyF1Team::sub_changeSposnor(int whichSponsor, std::string& tempString, double& tempDouble)
{
	system("cls");

	cout << "Enter name of the main sponsor: ";
	getline(cin, tempString);
	if (whichSponsor == 1) mainSponsor.SetName(tempString);
	else secondarySponsor.SetName(tempString);

	puts("");
	if (whichSponsor == 1) mainSponsor.SetColor_interface();
	else secondarySponsor.SetColor_interface();

	puts("");
	if (whichSponsor == 1) mainSponsor.SetTargetRace_interface();
	else secondarySponsor.SetTargetRace_interface();

	puts("\n");
	if (whichSponsor == 1) mainSponsor.SetTargetSeason_interface();
	else secondarySponsor.SetTargetSeason_interface();

	puts("\n");
	cout << "Enter sponsor's payment per race: ";
	cin >> tempDouble;
	cin.get();
	if (whichSponsor == 1) mainSponsor.SetPaymentPerRace(tempDouble);
	else secondarySponsor.SetPaymentPerRace(tempDouble);

	cout << "\nEnter sponsor's target bonus ratio: ";
	cin >> tempDouble;
	cin.get();
	if (whichSponsor == 1) mainSponsor.SetTargetBonusRatio(tempDouble);
	else secondarySponsor.SetTargetBonusRatio(tempDouble);
}
