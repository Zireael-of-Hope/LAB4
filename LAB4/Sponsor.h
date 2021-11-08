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
	string name_;
	int color_;
	SponsorTargetRace targetRace_;
	SponsorTargetSeason targetSeason_;
	double paymentPerRace_;
	double targetBonusRatio_;

public:
	Sponsor();
	~Sponsor();

	void setSponsorName(string newName);
	void setSponsorColor_interface();
	void setSponsorTargetRace_interface();
	void setSponsorTargetSeason_interface();
	void setSponsorPaymentPerRace(int newPaymentPerRace);
	void setSponsorTargetBonusRatio(int newTargetBonusRatio);
	void getInfoSponsor();
	double getPaymentPerRace();
};


