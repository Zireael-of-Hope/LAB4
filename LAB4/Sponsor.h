#pragma once
#include <iostream>
#include <string>
#include <conio.h>

#include "Color.h"

using namespace std;

enum class SponsorTargetRace {
	PODIUM,
	TOP_5,
	TOP_10,
	FINISH
};

enum class SponsorTargetSeason {
	CHAMP,
	TOP_THREE,
	TOP_FIVE,
	EVERY_RACE_PARTICIPATE,
	NOT_LAST
};

class Sponsor
{
private:
	string name;
	int color;
	SponsorTargetRace targetRace;
	SponsorTargetSeason targetSeason;
	double paymentPerRace;
	double targetBonusRatio;

public:
	Sponsor();
	~Sponsor();

	void SetName(string newName);
	void SetColor_interface();
	void SetTargetRace_interface();
	void SetTargetSeason_interface();
	void SetPaymentPerRace(double newPaymentPerRace);
	void SetTargetBonusRatio(double newTargetBonusRatio);
	void GetInfoSponsor();
	double GetPaymentPerRace();
};



