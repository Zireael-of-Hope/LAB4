#pragma once
#include <iostream>
#include <string>
#include <conio.h>

#include "Component.h"
#include "Color.h"
#include "Driver.h"
#include "Tyres.h"

using namespace std;

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
			Component engine1{ ComponentID::Engine };
			Component engine2{ ComponentID::Engine };
			Component engine3{ ComponentID::Engine };

			Component mguKinetic1{ ComponentID::MguKinetic };
			Component mguKinetic2{ ComponentID::MguKinetic };
			Component mguKinetic3{ ComponentID::MguKinetic };

			Component mguHeat1{ ComponentID::MguHeat };
			Component mguHeat2{ ComponentID::MguHeat };
			Component mguHeat3{ ComponentID::MguHeat };

			Component turboCharger1{ ComponentID::TurboCharger };
			Component turboCharger2{ ComponentID::TurboCharger };
			Component turboCharger3{ ComponentID::TurboCharger };

			Component energyStore1{ ComponentID::EnergyStore };
			Component energyStore2{ ComponentID::EnergyStore };

			Component controlElectronics1{ ComponentID::ControlElectronics };
			Component controlElectronics2{ ComponentID::ControlElectronics };

			InstalledComponent internalCombastionEngine;
			InstalledComponent mguKinetic;
			InstalledComponent mguHeat;
			InstalledComponent energyStore;
			InstalledComponent turboCharger;
			InstalledComponent controlElectronics;
		} powerUnitSet;
		struct Gearbox {
			Component practiceGearbox1{ ComponentID::Gearbox };
			Component practiceGearbox2{ ComponentID::Gearbox };

			Component eventGearbox1{ ComponentID::Gearbox };
			Component eventGearbox2{ ComponentID::Gearbox };

			InstalledComponent practiceGearbox;
			InstalledComponent eventGearbox;
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
	void GetInfoDriverName();
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

