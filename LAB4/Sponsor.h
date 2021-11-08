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

	void setName(string newName);
	void setColor_interface();
	void setTargetRace_interface();
	void setTargetSeason_interface();
	void setPaymentPerRace(double newPaymentPerRace);
	void setTargetBonusRatio(double newTargetBonusRatio);
	void getInfoSponsor();
	double getPaymentPerRace();
};


