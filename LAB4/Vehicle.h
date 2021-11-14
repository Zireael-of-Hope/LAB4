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

struct Tyres {
	TyresCompound installedTyres;
	int tyreWear;
};

struct Vehicle
{
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
};

void initVehicle(Vehicle& vehicle);

void VehicleGetSponsorStickers(Vehicle& vehicle);
void VehicleAddSponsorSticker(Vehicle& vehicle, string newSponsorName);
bool VehicleDeleteSponsorSticker(Vehicle& vehicle, string nameDelete);
void VehicleGetInfoTotalWear(Vehicle& vehicle);
void VehicleGetInfo(Vehicle& vehicle);
void VehicleGetInfoName(Vehicle& vehicle);
void VehicleGetInfoTyreSet(Vehicle& vehicle);
void VehicleGetInfoCombastionEngine(Vehicle& vehicle);
void VehicleGetInfoVehicleMguKinetic(Vehicle& vehicle);
void VehicleGetInfoMguHeat(Vehicle& vehicle);
void VehicleGetInfoTurboCharger(Vehicle& vehicle);
void VehicleGetInfoEnergyStore(Vehicle& vehicle);
void VehicleGetInfoControlElectronics(Vehicle& vehicle);
void VehicleGetInfoPractiseGerbox(Vehicle& vehicle);
void VehicleGetInfoEventGerbox(Vehicle& vehicle);
void VehicleSetName(Vehicle& vehicle, string newName);
void VehicleSetTyres_interface(Vehicle& vehicle);
void VehicleSetComponents_interface(Vehicle& vehicle);
void VehicleSetDriver(Vehicle& vehicle, Driver newDriver);
void VehicleSetTotalComponentWearRatio(Vehicle& vehicle, int aerodynamicsLevel, int powertrainLevel, int chassisLevel, int durabilityLevel);
