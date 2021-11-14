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

struct Sponsor
{
	string name;
	int color;
	SponsorTargetRace targetRace;
	SponsorTargetSeason targetSeason;
	double paymentPerRace;
	double targetBonusRatio;
};

void initSponsor(Sponsor& sponsor);

void SponsorSetName(Sponsor& sponsor, string newName);
void SponsorSetColor_interface(Sponsor& sponsor);
void SponsorSetTargetRace_interface(Sponsor& sponsor);
void SponsorSetTargetSeason_interface(Sponsor& sponsor);
void SponsorSetPaymentPerRace(Sponsor& sponsor, double newPaymentPerRace);
void SponsorSetTargetBonusRatio(Sponsor& sponsor, double newTargetBonusRatio);
void SponsorGetInfo(Sponsor& sponsor);
double SponsorGetPaymentPerRace(Sponsor& sponsor);
