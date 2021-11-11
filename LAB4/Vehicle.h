#pragma once
#include <iostream>
#include <string>
#include <conio.h>

#include "Component.h"
#include "Color.h"
#include "Driver.h"

using namespace std;

enum class InstalledComponent {
	NOT_FITTED,
	COMPONENT_1,
	COMPONENT_2,
	COMPONENT_3
};

enum class TyresCompound {
	NOT_INSTALLED,
	SOFT,
	MEDIUM,
	HARD
};



class Tyres {
public:
	TyresCompound installedTyres;
	int tyreWear;
};

class Vehicle
{
private:
	int sponsorStickerQuantity;

	Driver driver;

	string vehicleName;

	string* sponsorStickers;

	Tyres tyreSet;

	struct SeasonComponents {
		double totalComponentWearRatio;
		struct powerUnitSet {
			Component engine1;
			Component engine2;
			Component engine3;

			Component mguKinetic1;
			Component mguKinetic2;
			Component mguKinetic3;

			Component mguHeat1;
			Component mguHeat2;
			Component mguHeat3;

			Component turboCharger1;
			Component turboCharger2;
			Component turboCharger3;

			Component energyStore1;
			Component energyStore2;

			Component controlElectronics1;
			Component controlElectronics2;

			struct ChosenComponentsPowerUnit {
				InstalledComponent internalCombastionEngine;
				InstalledComponent mguKinetic;
				InstalledComponent mguHeat;
				InstalledComponent energyStore;
				InstalledComponent turboCharger;
				InstalledComponent controlElectronics;
			} chosenComponentsPowerUnit;
		} powerUnitSet;
		struct Gearbox {
			Component practiceGearbox1;
			Component practiceGearbox2;

			Component eventGearbox1;
			Component eventGearbox2;

			struct ChosenComponentsGearbox {
				InstalledComponent practiceGearbox;
				InstalledComponent eventGearbox;
			} chosenComponentsGearbox;
		} gearboxSet;
	} seasonComponents;

public:
	Vehicle();
	~Vehicle();

	void GetSponsorStickers();
	void AddSponsorSticker(string newSponsorName);
	bool DeleteSponsorSticker(string nameDelete);
	void GetInfoTotalWear();
	void GetInfo();
	void GetInfoName();
	void GetInfoTyreSet();
	void GetInfoCombastionEngine();
	void GetInfoVehicleMguKinetic();
	void GetInfoMguHeat();
	void GetInfoTurboCharger();
	void GetInfoEnergyStore();
	void GetInfoControlElectronics();
	void GetInfoPractiseGerbox();
	void GetInfoEventGerbox();
	void SetName(string newName);
	void SetTyres_interface();
	void SetComponents_interface();
	void SetDriver(Driver newDriver);
	void SetTotalComponentWearRatio(int aerodynamicsLevel, int powertrainLevel, int chassisLevel, int durabilityLevel);
};

