#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Team.h"

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
		cout << "\n" << i + 1 << ") ";
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



