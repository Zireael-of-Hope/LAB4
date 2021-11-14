#include "Vehicle.h"

void initVehicle(Vehicle& vehicle)
{
    vehicle.sponsorStickerQuantity = 0;
    vehicle.vehicleName = "NoName";
    vehicle.sponsorStickers = nullptr;
    vehicle.tyreSet = { TyresCompound::NOT_INSTALLED, 0 };
    vehicle.seasonComponents.totalComponentWearRatio = 3;
    initComponent(vehicle.seasonComponents.powerUnitSet.engine1, ComponentID::Engine);
    initComponent(vehicle.seasonComponents.powerUnitSet.engine2, ComponentID::Engine);
    initComponent(vehicle.seasonComponents.powerUnitSet.engine3, ComponentID::Engine);
    initComponent(vehicle.seasonComponents.powerUnitSet.mguKinetic1, ComponentID::MguKinetic);
    initComponent(vehicle.seasonComponents.powerUnitSet.mguKinetic2, ComponentID::MguKinetic);
    initComponent(vehicle.seasonComponents.powerUnitSet.mguKinetic3, ComponentID::MguKinetic);
    initComponent(vehicle.seasonComponents.powerUnitSet.mguHeat1, ComponentID::MguHeat);
    initComponent(vehicle.seasonComponents.powerUnitSet.mguHeat2, ComponentID::MguHeat);
    initComponent(vehicle.seasonComponents.powerUnitSet.mguHeat3, ComponentID::MguHeat);
    initComponent(vehicle.seasonComponents.powerUnitSet.turboCharger1, ComponentID::TurboCharger);
    initComponent(vehicle.seasonComponents.powerUnitSet.turboCharger2, ComponentID::TurboCharger);
    initComponent(vehicle.seasonComponents.powerUnitSet.turboCharger3, ComponentID::TurboCharger);
    initComponent(vehicle.seasonComponents.powerUnitSet.energyStore1, ComponentID::EnergyStore);
    initComponent(vehicle.seasonComponents.powerUnitSet.energyStore2, ComponentID::EnergyStore);
    initComponent(vehicle.seasonComponents.powerUnitSet.controlElectronics1, ComponentID::ControlElectronics);
    initComponent(vehicle.seasonComponents.powerUnitSet.controlElectronics2, ComponentID::ControlElectronics);
    initComponent(vehicle.seasonComponents.gearboxSet.practiceGearbox1, ComponentID::Gearbox);
    initComponent(vehicle.seasonComponents.gearboxSet.practiceGearbox2, ComponentID::Gearbox);
    initComponent(vehicle.seasonComponents.gearboxSet.eventGearbox1, ComponentID::Gearbox);
    initComponent(vehicle.seasonComponents.gearboxSet.eventGearbox2, ComponentID::Gearbox);

    vehicle.seasonComponents.gearboxSet.chosenComponentsGearbox = { InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED };
    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit = { InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED };
}

void VehicleGetInfo(Vehicle& vehicle)
{
    VehicleGetInfoName(vehicle);
    VehicleGetSponsorStickers(vehicle);
    VehicleGetInfoTyreSet(vehicle);
    VehicleGetInfoTotalWear(vehicle);
    VehicleGetInfoCombastionEngine(vehicle);
    VehicleGetInfoVehicleMguKinetic(vehicle);
    VehicleGetInfoMguHeat(vehicle);
    VehicleGetInfoTurboCharger(vehicle);
    VehicleGetInfoEnergyStore(vehicle);
    VehicleGetInfoControlElectronics(vehicle);
    VehicleGetInfoPractiseGerbox(vehicle);
    VehicleGetInfoEventGerbox(vehicle);
}

void VehicleGetInfoTotalWear(Vehicle& vehicle)
{
    cout << "Total Component Wear Ratio: " << vehicle.seasonComponents.totalComponentWearRatio << endl;
}

void VehicleGetSponsorStickers(Vehicle& vehicle)
{
    int i;
    for (i = 0; i < vehicle.sponsorStickerQuantity; i++)
        cout << "  " << vehicle.sponsorStickers[i] << endl;
}

void VehicleAddSponsorSticker(Vehicle& vehicle, string newSponsorName)
{
    int i;
    if (vehicle.sponsorStickerQuantity == 0) {
        vehicle.sponsorStickers = new string[1];
        vehicle.sponsorStickers[0] = newSponsorName;
        vehicle.sponsorStickerQuantity++;
    }
    else {
        string* new_arr = new string[vehicle.sponsorStickerQuantity + 1];
        for (i = 0; i < vehicle.sponsorStickerQuantity; i++) {
            new_arr[i] = vehicle.sponsorStickers[i];
        }
        new_arr[vehicle.sponsorStickerQuantity] = newSponsorName;
        delete[]  vehicle.sponsorStickers;
        vehicle.sponsorStickers = new_arr;
        vehicle.sponsorStickerQuantity++;
    }

}

bool VehicleDeleteSponsorSticker(Vehicle& vehicle, string nameDelete)
{
    int i, j;
    bool isStickerFound = false;

    if (vehicle.sponsorStickerQuantity != 0) {
        for (i = 0; i < vehicle.sponsorStickerQuantity; i++)
            if (vehicle.sponsorStickers[i] == nameDelete) {
                isStickerFound = true;
                for (j = i; j < vehicle.sponsorStickerQuantity - 1; j++)
                    vehicle.sponsorStickers[j] = vehicle.sponsorStickers[j + 1];
            }
        if (isStickerFound == true) {
            string* new_arr = new string[vehicle.sponsorStickerQuantity - 1];

            for (i = 0; i < vehicle.sponsorStickerQuantity - 1; i++)
                new_arr[i] = vehicle.sponsorStickers[i];

            delete[]  vehicle.sponsorStickers;

            vehicle.sponsorStickers = new_arr;
            vehicle.sponsorStickerQuantity--;
            return true;
        }
    }
    return false;
}

void VehicleGetInfoName(Vehicle& vehicle)
{
    cout << "Vehicle Name: " << vehicle.vehicleName << endl;
}

void VehicleGetInfoTyreSet(Vehicle& vehicle)
{
    switch (vehicle.tyreSet.installedTyres) {
    case TyresCompound::NOT_INSTALLED:
        cout << "Tyres aren't installed" << endl;
        break;
    case TyresCompound::SOFT:
        SetColor(4, 0);  cout << "SOFT "; SetColor(15, 0); cout << "tyres are installed" << endl;
        cout << "  Tyre Wear: " << vehicle.tyreSet.tyreWear << endl;
        break;
    case TyresCompound::MEDIUM:
        SetColor(6, 0);  cout << "MEDIUM "; SetColor(15, 0); cout << "tyres are installed" << endl;
        cout << "  Tyre Wear: " << vehicle.tyreSet.tyreWear << endl;
        break;
    case TyresCompound::HARD:
        cout << "HARD tyres are installed" << endl;
        cout << "  Tyre Wear: " << vehicle.tyreSet.tyreWear << endl;
        break;
    }
}

void VehicleGetInfoCombastionEngine(Vehicle& vehicle)
{
    cout << "Internal Combastion Engine: ";
    switch (vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.internalCombastionEngine) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.engine1) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.engine1) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.engine1) << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.engine2) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.engine2) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.engine2) << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.engine3) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.engine3) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.engine3) << endl;
        break;
    }
}

void VehicleGetInfoVehicleMguKinetic(Vehicle& vehicle)
{
    cout << "MGU Kinetic: ";
    switch (vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguKinetic) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguKinetic1) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguKinetic1) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguKinetic1) << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguKinetic2) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguKinetic2) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguKinetic2) << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguKinetic3) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguKinetic3) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguKinetic3) << endl;
        break;
    }
}

void VehicleGetInfoMguHeat(Vehicle& vehicle)
{
    cout << "MGU Heat: ";
    switch (vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguHeat) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguHeat1) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguHeat1) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguHeat1) << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguHeat2) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguHeat2) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguHeat2) << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguHeat3) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguHeat3) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguHeat3) << endl;
        break;
    }
}

void VehicleGetInfoTurboCharger(Vehicle& vehicle)
{
    cout << "Turbo Charger: ";
    switch (vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.turboCharger) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.turboCharger1) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.turboCharger1) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.turboCharger1) << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.turboCharger2) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.turboCharger2) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.turboCharger2) << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.turboCharger3) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.turboCharger3) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.turboCharger3) << endl;
        break;
    }
}

void VehicleGetInfoEnergyStore(Vehicle& vehicle)
{
    cout << "Energy Store: ";
    switch (vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.energyStore) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.energyStore1) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.energyStore1) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.energyStore1) << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.energyStore2) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.energyStore2) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.energyStore2) << endl;
        break;
    }
}

void VehicleGetInfoControlElectronics(Vehicle& vehicle)
{
    cout << "Control Electronics: ";
    switch (vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.controlElectronics) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.controlElectronics1) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.controlElectronics1) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.controlElectronics1) << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.controlElectronics2) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.controlElectronics2) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.controlElectronics2) << endl;
        break;
    }
}

void VehicleGetInfoPractiseGerbox(Vehicle& vehicle)
{
    cout << "Practise Gearbox: ";
    switch (vehicle.seasonComponents.gearboxSet.chosenComponentsGearbox.practiceGearbox) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.gearboxSet.practiceGearbox1) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.gearboxSet.practiceGearbox1) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.gearboxSet.practiceGearbox1) << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.gearboxSet.practiceGearbox2) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.gearboxSet.practiceGearbox2) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.gearboxSet.practiceGearbox2) << endl;
        break;
    }
}

void VehicleGetInfoEventGerbox(Vehicle& vehicle)
{
    cout << "Event Gearbox: ";
    switch (vehicle.seasonComponents.gearboxSet.chosenComponentsGearbox.eventGearbox) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.gearboxSet.eventGearbox1) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.gearboxSet.eventGearbox1) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.gearboxSet.eventGearbox1) << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.gearboxSet.eventGearbox2) << endl;
        cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.gearboxSet.eventGearbox2) << endl;
        cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.gearboxSet.eventGearbox2) << endl;
        break;
    }
}

void VehicleSetName(Vehicle& vehicle, string newName)
{
    vehicle.vehicleName = newName;
}

void VehicleSetTyres_interface(Vehicle& vehicle)
{
    bool isPass;
    char decision;

    SetColor(14, 0);
    cout << "Current Tyres: ";
    SetColor(15, 0);

    switch (vehicle.tyreSet.installedTyres) {
    case TyresCompound::NOT_INSTALLED:
        cout << " Tyres aren't installed" << endl;
        break;
    case TyresCompound::SOFT:
        SetColor(4, 0);  cout << "SOFT "; SetColor(15, 0); cout << "tyres are installed";
        cout << " Tyre Wear: " << vehicle.tyreSet.tyreWear << endl;
        break;
    case TyresCompound::MEDIUM:
        SetColor(6, 0);  cout << "MEDIUM "; SetColor(15, 0); cout << "tyres are installed";
        cout << " Tyre Wear: " << vehicle.tyreSet.tyreWear << endl;
        break;
    case TyresCompound::HARD:
        cout << "HARD tyres are installed";
        cout << " Tyre Wear: " << vehicle.tyreSet.tyreWear << endl;
        break;
    }

    SetColor(14, 0);
    cout << "Available options: " << endl;
    SetColor(15, 0);

    cout << "  1) "; SetColor(4, 0); cout << "SOFT" << endl; SetColor(15, 0);
    cout << "  2) "; SetColor(6, 0); cout << "MEDIUM" << endl; SetColor(15, 0);
    cout << "  3) HARD" << endl;

    cout << "\nPick Option (0 - return): ";

    do {
        isPass = false;
        decision = _getch();
        if (decision == '1' || decision == '2' || decision == '3' || decision == '0')
            isPass = true;
    } while (isPass == false);

    switch (decision) {
    case '1':
        vehicle.tyreSet.installedTyres = TyresCompound::SOFT;
        vehicle.tyreSet.tyreWear = 0;
        break;
    case '2':
        vehicle.tyreSet.installedTyres = TyresCompound::MEDIUM;
        vehicle.tyreSet.tyreWear = 0;
        break;
    case '3':
        vehicle.tyreSet.installedTyres = TyresCompound::HARD;
        vehicle.tyreSet.tyreWear = 0;
        break;
    case '0':
        break;
    }
}

void VehicleSetComponents_interface(Vehicle& vehicle)
{
    bool isPass, isCycled;
    char decision;

    do {
        isCycled = true;
        system("cls");

        SetColor(14, 0);
        cout << "Current Components Info:\n" << endl;

        cout << "Power Unit:" << endl;
        SetColor(15, 0);

        cout << "1) "; VehicleGetInfoCombastionEngine(vehicle);
        cout << "2) "; VehicleGetInfoVehicleMguKinetic(vehicle);
        cout << "3) "; VehicleGetInfoMguHeat(vehicle);
        cout << "4) "; VehicleGetInfoTurboCharger(vehicle);
        cout << "5) "; VehicleGetInfoEnergyStore(vehicle);
        cout << "6) "; VehicleGetInfoControlElectronics(vehicle);

        SetColor(14, 0);
        cout << "\nGearbox:" << endl;
        SetColor(15, 0);

        cout << "7) "; VehicleGetInfoPractiseGerbox(vehicle);
        cout << "8) "; VehicleGetInfoEventGerbox(vehicle);

        cout << "\nPick component you want to change (0 - return)...";

        do {
            isPass = false;
            decision = _getch();
            if (decision == '1' || decision == '2' || decision == '3' || decision == '4' || decision == '5' || decision == '6' || decision == '7' || decision == '8' || decision == '0')
                isPass = true;
        } while (isPass == false);
        system("cls");

        switch (decision) {
        case '1':
            SetColor(14, 0);  cout << "Internal Combastion Engine:" << endl; SetColor(15, 0);
            cout << "1)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.engine1) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.engine1) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.engine1) << endl;
            cout << "2)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.engine2) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.engine2) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.engine2) << endl;
            cout << "3)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.engine3) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.engine3) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.engine3) << endl;

            cout << "\nPick Engine you want to fit or press 4 to take off the fitted component (0 - return)...";

            do {
                isPass = false;
                decision = _getch();
                if (decision == '1' || decision == '2' || decision == '3' || decision == '4' || decision == '0')
                    isPass = true;
            } while (isPass == false);

            if (decision != 0)
                switch (decision) {
                case '1':
                    cout << "\n\nFirst engine has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.internalCombastionEngine = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond engine has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.internalCombastionEngine = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird engine has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.internalCombastionEngine = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.internalCombastionEngine = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '2':
            SetColor(14, 0);  cout << "MGU Kinetic:" << endl; SetColor(15, 0);
            cout << "1)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguKinetic1) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguKinetic1) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguKinetic1) << endl;
            cout << "2)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguKinetic2) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguKinetic2) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguKinetic2) << endl;
            cout << "3)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguKinetic3) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguKinetic3) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguKinetic3) << endl;

            cout << "\nPick MGU Kinetic you want to fit or press 4 to take off the fitted component (0 - return)...";

            do {
                isPass = false;
                decision = _getch();
                if (decision == '1' || decision == '2' || decision == '3' || decision == '4' || decision == '0')
                    isPass = true;
            } while (isPass == false);

            if (decision != 0)
                switch (decision) {
                case '1':
                    cout << "\n\nFirst MGU Kinetic has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguKinetic = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond MGU Kinetic has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguKinetic = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird MGU Kinetic has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguKinetic = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguKinetic = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '3':
            SetColor(14, 0);  cout << "MGU Heat:" << endl; SetColor(15, 0);
            cout << "1)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguHeat1) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguHeat1) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguHeat1) << endl;
            cout << "2)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguHeat2) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguHeat2) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguHeat2) << endl;
            cout << "3)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.mguHeat3) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.mguHeat3) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.mguHeat3) << endl;

            cout << "\nPick MGU Heat you want to fit or press 4 to take off the fitted component (0 - return)...";

            do {
                isPass = false;
                decision = _getch();
                if (decision == '1' || decision == '2' || decision == '3' || decision == '4' || decision == '0')
                    isPass = true;
            } while (isPass == false);

            if (decision != 0)
                switch (decision) {
                case '1':
                    cout << "\n\nFirst MGU Heat has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguHeat = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond MGU Heat has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguHeat = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird MGU Heat has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguHeat = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.mguHeat = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '4':
            SetColor(14, 0);  cout << "Turbo Charger:" << endl; SetColor(15, 0);
            cout << "1)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.turboCharger1) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.turboCharger1) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.turboCharger1) << endl;
            cout << "2)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.turboCharger2) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.turboCharger2) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.turboCharger2) << endl;
            cout << "3)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.turboCharger3) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.turboCharger3) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.turboCharger3) << endl;

            cout << "\nPick Turbo Charger you want to fit or press 4 to take off the fitted component (0 - return)...";

            do {
                isPass = false;
                decision = _getch();
                if (decision == '1' || decision == '2' || decision == '3' || decision == '4' || decision == '0')
                    isPass = true;
            } while (isPass == false);

            if (decision != 0)
                switch (decision) {
                case '1':
                    cout << "\n\nFirst Turbo Charger has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.turboCharger = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Turbo Charger has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.turboCharger = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird Turbo Charger has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.turboCharger = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.turboCharger = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '5':
            SetColor(14, 0);  cout << "Energy Store:" << endl; SetColor(15, 0);
            cout << "1)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.energyStore1) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.energyStore1) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.energyStore1) << endl;
            cout << "2)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.energyStore2) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.energyStore2) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.energyStore2) << endl;

            cout << "\nPick Energy Store you want to fit or press 3 to take off the fitted component (0 - return)...";

            do {
                isPass = false;
                decision = _getch();
                if (decision == '1' || decision == '2' || decision == '3' || decision == '0')
                    isPass = true;
            } while (isPass == false);

            if (decision != 0)
                switch (decision) {
                case '1':
                    cout << "\n\nFirst Energy Store has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.energyStore = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Energy Store has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.energyStore = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.energyStore = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '6':
            SetColor(14, 0);  cout << "Control Electronics:" << endl; SetColor(15, 0);
            cout << "1)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.controlElectronics1) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.controlElectronics1) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.controlElectronics1) << endl;
            cout << "2)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.powerUnitSet.controlElectronics2) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.powerUnitSet.controlElectronics2) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.powerUnitSet.controlElectronics2) << endl;

            cout << "\nPick Control Electronics you want to fit or press 3 to take off the fitted component (0 - return)...";

            do {
                isPass = false;
                decision = _getch();
                if (decision == '1' || decision == '2' || decision == '3' || decision == '0')
                    isPass = true;
            } while (isPass == false);

            if (decision != 0)
                switch (decision) {
                case '1':
                    cout << "\n\nFirst Control Electronics Store has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.controlElectronics = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Control Electronics Store has been fitted.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.controlElectronics = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    vehicle.seasonComponents.powerUnitSet.chosenComponentsPowerUnit.controlElectronics = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '7':
            SetColor(14, 0);  cout << "Practise Gearbox:" << endl; SetColor(15, 0);
            cout << "1)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.gearboxSet.practiceGearbox1) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.gearboxSet.practiceGearbox1) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.gearboxSet.practiceGearbox1) << endl;
            cout << "2)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.gearboxSet.practiceGearbox2) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.gearboxSet.practiceGearbox2) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.gearboxSet.practiceGearbox2) << endl;

            cout << "\nPick Practise Gearbox you want to fit or press 3 to take off the fitted component (0 - return)...";

            do {
                isPass = false;
                decision = _getch();
                if (decision == '1' || decision == '2' || decision == '3' || decision == '0')
                    isPass = true;
            } while (isPass == false);

            if (decision != 0)
                switch (decision) {
                case '1':
                    cout << "\n\nFirst Practise Gearbox has been fitted.";
                    vehicle.seasonComponents.gearboxSet.chosenComponentsGearbox.practiceGearbox = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Practise Gearbox has been fitted.";
                    vehicle.seasonComponents.gearboxSet.chosenComponentsGearbox.practiceGearbox = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    vehicle.seasonComponents.gearboxSet.chosenComponentsGearbox.practiceGearbox = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '8':
            SetColor(14, 0);  cout << "Event Gearbox:" << endl; SetColor(15, 0);
            cout << "1)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.gearboxSet.eventGearbox1) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.gearboxSet.eventGearbox1) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.gearboxSet.eventGearbox1) << endl;
            cout << "2)" << endl;
            cout << "  Expected Lifespan: " << ComponentGetExpectedLifespan(vehicle.seasonComponents.gearboxSet.eventGearbox2) << endl;
            cout << "  Track Time: " << ComponentGetTrackTime(vehicle.seasonComponents.gearboxSet.eventGearbox2) << endl;
            cout << "  Wear: " << ComponentGetWear(vehicle.seasonComponents.gearboxSet.eventGearbox2) << endl;

            cout << "\nPick Event Gearbox you want to fit or press 3 to take off the fitted component (0 - return)...";

            do {
                isPass = false;
                decision = _getch();
                if (decision == '1' || decision == '2' || decision == '3' || decision == '0')
                    isPass = true;
            } while (isPass == false);

            if (decision != 0)
                switch (decision) {
                case '1':
                    cout << "\n\nFirst Event Gearbox has been fitted.";
                    vehicle.seasonComponents.gearboxSet.chosenComponentsGearbox.eventGearbox = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Event Gearbox has been fitted.";
                    vehicle.seasonComponents.gearboxSet.chosenComponentsGearbox.eventGearbox = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    vehicle.seasonComponents.gearboxSet.chosenComponentsGearbox.eventGearbox = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '0':
            isCycled = false;
            break;
        }
    } while (isCycled == true);
}

void VehicleSetDriver(Vehicle& vehicle, Driver newDriver)
{
    vehicle.driver = newDriver;
}

void VehicleSetTotalComponentWearRatio(Vehicle& vehicle, int aerodynamicsLevel, int powertrainLevel, int chassisLevel, int durabilityLevel)
{
    double tempTotalWear = vehicle.seasonComponents.totalComponentWearRatio;

    tempTotalWear = tempTotalWear * 10;

    tempTotalWear = tempTotalWear - aerodynamicsLevel - powertrainLevel - chassisLevel - durabilityLevel;

    tempTotalWear = tempTotalWear / 10;

    vehicle.seasonComponents.totalComponentWearRatio = tempTotalWear;
}
