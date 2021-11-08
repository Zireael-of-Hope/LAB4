#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "Color.h"

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

struct Component {
	int expectedLifespan;
	int trackTime;
	int wear;
};

struct Tyres {
	TyresCompound installedTyres;
	int tyreWear;
};

class Vehicle
{
private:
	int sponsorStickerQuantity_;

	string driverName_;

	string vehicleName_;

	string* sponsorStickers_;

	Tyres tyreSet_;

	struct SeasonComponents {
		double totalComponentWearRatio_;
		struct powerUnitSet_ {
			Component engine_1_;
			Component engine_2_;
			Component engine_3_;

			Component mguKinetic_1_;
			Component mguKinetic_2_;
			Component mguKinetic_3_;

			Component mguHeat_1_;
			Component mguHeat_2_;
			Component mguHeat_3_;

			Component turboCharger_1_;
			Component turboCharger_2_;
			Component turboCharger_3_;

			Component energyStore_1_;
			Component energyStore_2_;

			Component controlElectronics_1_;
			Component controlElectronics_2_;

			struct ChosenComponentsPowerUnit {
				InstalledComponent internalCombastionEngine_;
				InstalledComponent mguKinetic_;
				InstalledComponent mguHeat_;
				InstalledComponent energyStore_;
				InstalledComponent turboCharger_;
				InstalledComponent controlElectronics_;
			} chosenComponentsPowerUnit_;
		} powerUnitSet_;
		struct Gearbox {
			Component practiceGearbox_1_;
			Component practiceGearbox_2_;

			Component eventGearbox_1_;
			Component eventGearbox_2_;

			struct ChosenComponentsGearbox {
				InstalledComponent practiceGearbox_;
				InstalledComponent eventGearbox_;
			} chosenComponentsGearbox_;
		} gearboxSet_;
	} seasonComponents_;

public:
	Vehicle();
	~Vehicle();

	void getSponsorStickers();
	void addSponsorSticker(string newSponsorName);
	bool deleteSponsorSticker(string nameDelete);
	void getInfoVehicleSponsorSticker();
	void getInfoVehicleTotalWear();
	void getInfoVehicle();
	void getInfoVehicleDriver();
	void getInfoVehicleName();
	void getInfoVehicleTyreSet();
	void getInfoVehicleCombastionEngine();
	void geInfoVehicleMguKinetic();
	void getInfoVehicleMguHeat();
	void getInfoVehicleTurboCharger();
	void getInfoVehicleEnergyStore();
	void getInfoVehicleControlElectronics();
	void getInfoPractiseGerboxVehicle();
	void getInfoEventGerboxVehicle();
	void setVehicleName(string newName);
	void setVehicleDriver(string newName);
	void setVehicleTyres_interface();
	void setVehicleComponents_interface();
	void setVehicleTotalComponentWearRatio(int aerodynamicsLevel, int powertrainLevel, int chassisLevel, int durabilityLevel);
};

