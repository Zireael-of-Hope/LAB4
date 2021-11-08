#include "Vehicle.h"

Vehicle::Vehicle()
{
    sponsorStickerQuantity_ = 0;
    driverName_ = "not assigned";
    vehicleName_ = "NoName";
    sponsorStickers_ = nullptr;
    tyreSet_ = { TyresCompound::NOT_INSTALLED, 0 };
    seasonComponents_.totalComponentWearRatio_ = 3;
    seasonComponents_.powerUnitSet_.engine_1_ = { 340, 0, 0 };
    seasonComponents_.powerUnitSet_.engine_2_ = { 340, 0, 0 };
    seasonComponents_.powerUnitSet_.engine_3_ = { 340, 0, 0 };
    seasonComponents_.powerUnitSet_.mguKinetic_1_ = { 800, 0, 0 };
    seasonComponents_.powerUnitSet_.mguKinetic_2_ = { 800, 0, 0 };
    seasonComponents_.powerUnitSet_.mguKinetic_3_ = { 800, 0, 0 };
    seasonComponents_.powerUnitSet_.mguHeat_1_ = { 700, 0, 0 };
    seasonComponents_.powerUnitSet_.mguHeat_2_ = { 700, 0, 0 };
    seasonComponents_.powerUnitSet_.mguHeat_3_ = { 700, 0, 0 };
    seasonComponents_.powerUnitSet_.turboCharger_1_ = { 500, 0, 0 };
    seasonComponents_.powerUnitSet_.turboCharger_2_ = { 500, 0, 0 };
    seasonComponents_.powerUnitSet_.turboCharger_3_ = { 500, 0, 0 };
    seasonComponents_.powerUnitSet_.energyStore_1_ = { 900, 0, 0 };
    seasonComponents_.powerUnitSet_.energyStore_2_ = { 900, 0, 0 };
    seasonComponents_.powerUnitSet_.controlElectronics_1_ = { 450, 0, 0 };
    seasonComponents_.powerUnitSet_.controlElectronics_1_ = { 450, 0, 0 };
    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_ = { InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED };
    seasonComponents_.gearboxSet_.practiceGearbox_1_ = { 380, 0, 0 };
    seasonComponents_.gearboxSet_.practiceGearbox_2_ = { 380, 0, 0 };
    seasonComponents_.gearboxSet_.eventGearbox_1_ = { 380, 0, 0 };
    seasonComponents_.gearboxSet_.eventGearbox_2_ = { 380, 0, 0 };
    seasonComponents_.gearboxSet_.chosenComponentsGearbox_ = { InstalledComponent::NOT_FITTED, InstalledComponent::NOT_FITTED };
}

Vehicle::~Vehicle()
{
}

void Vehicle::getInfoVehicle()
{
    getInfoVehicleDriver();
    getInfoVehicleName();
    getInfoVehicleSponsorSticker();
    getInfoVehicleTyreSet();
    getInfoVehicleTotalWear();
    getInfoVehicleCombastionEngine();
    geInfoVehicleMguKinetic();
    getInfoVehicleMguHeat();
    getInfoVehicleTurboCharger();
    getInfoVehicleEnergyStore();
    getInfoVehicleControlElectronics();
    getInfoPractiseGerboxVehicle();
    getInfoEventGerboxVehicle();
}

void Vehicle::getInfoVehicleTotalWear()
{
    cout << "Total Component Wear Ratio: " << seasonComponents_.totalComponentWearRatio_ << endl;
}

void Vehicle::getInfoVehicleDriver()
{
    cout << "Assigned Driver: " << driverName_ << endl;
}

void Vehicle::getSponsorStickers()
{
    int i;
    for (i = 0; i < sponsorStickerQuantity_; i++)
        cout << "  " << sponsorStickers_[i] << endl;
}

void Vehicle::addSponsorSticker(string newSponsorName)
{
    int i;
    if (sponsorStickerQuantity_ == 0) {
        sponsorStickers_ = new string[1];
        sponsorStickers_[0] = newSponsorName;
        sponsorStickerQuantity_++;
    }
    else {
        string* new_arr = new string[sponsorStickerQuantity_ + 1];
        for (i = 0; i < sponsorStickerQuantity_; i++) {
            new_arr[i] = sponsorStickers_[i];
        }
        new_arr[sponsorStickerQuantity_] = newSponsorName;
        delete[] sponsorStickers_;
        sponsorStickers_ = new_arr;
        sponsorStickerQuantity_++;
    }

}

bool Vehicle::deleteSponsorSticker(string nameDelete)
{
    int i, j;
    bool isStickerFound = false;

    if (sponsorStickerQuantity_ != 0) {
        for (i = 0; i < sponsorStickerQuantity_; i++)
            if (sponsorStickers_[i] == nameDelete) {
                isStickerFound = true;
                for (j = i; j < sponsorStickerQuantity_ - 1; j++)
                    sponsorStickers_[j] = sponsorStickers_[j + 1];
            }
        if (isStickerFound == true) {
            string* new_arr = new string[sponsorStickerQuantity_ - 1];

            for (i = 0; i < sponsorStickerQuantity_ - 1; i++)
                new_arr[i] = sponsorStickers_[i];

            delete[] sponsorStickers_;

            sponsorStickers_ = new_arr;
            sponsorStickerQuantity_--;
            return true;
        }
    }
    return false;
}

void Vehicle::getInfoVehicleSponsorSticker()
{
    int i;

    cout << "Sponsor's Stickers: " << endl;
    for (i = 0; i < sponsorStickerQuantity_; i++)
        cout << "  " << sponsorStickers_[i] << endl;
}

void Vehicle::getInfoVehicleName()
{
    cout << "Vehicle Name: " << vehicleName_ << endl;
}

void Vehicle::getInfoVehicleTyreSet()
{
    switch (tyreSet_.installedTyres) {
    case TyresCompound::NOT_INSTALLED:
        cout << "Tyres aren't installed" << endl;
        break;
    case TyresCompound::SOFT:
        SetColor(4, 0);  cout << "SOFT "; SetColor(15, 0); cout << "tyres are installed" << endl;
        cout << "  Tyre Wear: " << tyreSet_.tyreWear << endl;
        break;
    case TyresCompound::MEDIUM:
        SetColor(6, 0);  cout << "MEDIUM "; SetColor(15, 0); cout << "tyres are installed" << endl;
        cout << "  Tyre Wear: " << tyreSet_.tyreWear << endl;
        break;
    case TyresCompound::HARD:
        cout << "HARD tyres are installed" << endl;
        cout << "  Tyre Wear: " << tyreSet_.tyreWear << endl;
        break;
    }
}

void Vehicle::getInfoVehicleCombastionEngine()
{
    cout << "Internal Combastion Engine: ";
    switch (seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.internalCombastionEngine_) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.engine_1_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.engine_1_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.engine_1_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.engine_2_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.engine_2_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.engine_2_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.engine_3_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.engine_3_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.engine_3_.wear << endl;
        break;
    }
}

void Vehicle::geInfoVehicleMguKinetic()
{
    cout << "MGU Kinetic: ";
    switch (seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguKinetic_) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguKinetic_1_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguKinetic_1_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguKinetic_1_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguKinetic_2_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguKinetic_2_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguKinetic_2_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguKinetic_2_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguKinetic_2_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguKinetic_2_.wear << endl;
        break;
    }
}

void Vehicle::getInfoVehicleMguHeat()
{
    cout << "MGU Heat: ";
    switch (seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguHeat_) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguHeat_1_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguHeat_1_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguHeat_1_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguHeat_2_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguHeat_2_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguHeat_2_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguHeat_3_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguHeat_3_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguHeat_3_.wear << endl;
        break;
    }
}

void Vehicle::getInfoVehicleTurboCharger()
{
    cout << "Turbo Charger: ";
    switch (seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.turboCharger_) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.turboCharger_1_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.turboCharger_1_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.turboCharger_1_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.turboCharger_2_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.turboCharger_2_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.turboCharger_2_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.turboCharger_3_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.turboCharger_3_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.turboCharger_3_.wear << endl;
        break;
    }
}

void Vehicle::getInfoVehicleEnergyStore()
{
    cout << "Energy Store: ";
    switch (seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.energyStore_) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.energyStore_1_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.energyStore_1_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.energyStore_1_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.energyStore_2_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.energyStore_2_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.energyStore_2_.wear << endl;
        break;
    }
}

void Vehicle::getInfoVehicleControlElectronics()
{
    cout << "Control Electronics: ";
    switch (seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.controlElectronics_) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.controlElectronics_1_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.controlElectronics_1_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.controlElectronics_1_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.controlElectronics_2_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.powerUnitSet_.controlElectronics_2_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.powerUnitSet_.controlElectronics_2_.wear << endl;
        break;
    }
}

void Vehicle::getInfoPractiseGerboxVehicle()
{
    cout << "Practise Gearbox: ";
    switch (seasonComponents_.gearboxSet_.chosenComponentsGearbox_.practiceGearbox_) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.gearboxSet_.practiceGearbox_1_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.gearboxSet_.practiceGearbox_1_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.gearboxSet_.practiceGearbox_1_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.gearboxSet_.practiceGearbox_2_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.gearboxSet_.practiceGearbox_2_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.gearboxSet_.practiceGearbox_2_.wear << endl;
        break;
    }
}

void Vehicle::getInfoEventGerboxVehicle()
{
    cout << "Event Gearbox: ";
    switch (seasonComponents_.gearboxSet_.chosenComponentsGearbox_.eventGearbox_) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.gearboxSet_.eventGearbox_1_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.gearboxSet_.eventGearbox_1_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.gearboxSet_.eventGearbox_1_.wear << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents_.gearboxSet_.eventGearbox_2_.expectedLifespan << endl;
        cout << "  Track Time: " << seasonComponents_.gearboxSet_.eventGearbox_2_.trackTime << endl;
        cout << "  Wear: " << seasonComponents_.gearboxSet_.eventGearbox_2_.wear << endl;
        break;
    }
}

void Vehicle::setVehicleName(string newName)
{
    vehicleName_ = newName;
}

void Vehicle::setVehicleDriver(string newName)
{
    driverName_ = newName;
}

void Vehicle::setVehicleTyres_interface()
{
    bool isPass;
    char decision;

    SetColor(14, 0);
    cout << "Current Tyres: ";
    SetColor(15, 0);

    switch (tyreSet_.installedTyres) {
    case TyresCompound::NOT_INSTALLED:
        cout << " Tyres aren't installed" << endl;
        break;
    case TyresCompound::SOFT:
        SetColor(4, 0);  cout << "SOFT "; SetColor(15, 0); cout << "tyres are installed";
        cout << " Tyre Wear: " << tyreSet_.tyreWear << endl;
        break;
    case TyresCompound::MEDIUM:
        SetColor(6, 0);  cout << "MEDIUM "; SetColor(15, 0); cout << "tyres are installed";
        cout << " Tyre Wear: " << tyreSet_.tyreWear << endl;
        break;
    case TyresCompound::HARD:
        cout << "HARD tyres are installed";
        cout << " Tyre Wear: " << tyreSet_.tyreWear << endl;
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
        tyreSet_.installedTyres = TyresCompound::SOFT;
        tyreSet_.tyreWear = 0;
        break;
    case '2':
        tyreSet_.installedTyres = TyresCompound::MEDIUM;
        tyreSet_.tyreWear = 0;
        break;
    case '3':
        tyreSet_.installedTyres = TyresCompound::HARD;
        tyreSet_.tyreWear = 0;
        break;
    case '0':
        break;
    }
}

void Vehicle::setVehicleComponents_interface()
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

        cout << "1) "; getInfoVehicleCombastionEngine();
        cout << "2) "; geInfoVehicleMguKinetic();
        cout << "3) "; getInfoVehicleMguHeat();
        cout << "4) "; getInfoVehicleTurboCharger();
        cout << "5) "; getInfoVehicleEnergyStore();
        cout << "6) "; getInfoVehicleControlElectronics();

        SetColor(14, 0);
        cout << "\nGearbox:" << endl;
        SetColor(15, 0);

        cout << "7) "; getInfoPractiseGerboxVehicle();
        cout << "8) "; getInfoEventGerboxVehicle();

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
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.engine_1_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.engine_1_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.engine_1_.wear << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.engine_2_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.engine_2_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.engine_2_.wear << endl;
            cout << "3:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.engine_3_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.engine_3_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.engine_3_.wear << endl;

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
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.internalCombastionEngine_ = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond engine has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.internalCombastionEngine_ = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird engine has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.internalCombastionEngine_ = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.internalCombastionEngine_ = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '2':
            SetColor(14, 0);  cout << "MGU Kinetic:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguKinetic_1_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguKinetic_1_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguKinetic_1_.wear << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguKinetic_2_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguKinetic_2_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguKinetic_2_.wear << endl;
            cout << "3: " << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguKinetic_3_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguKinetic_3_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguKinetic_3_.wear << endl;

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
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguKinetic_ = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond MGU Kinetic has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguKinetic_ = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird MGU Kinetic has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguKinetic_ = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguKinetic_ = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '3':
            SetColor(14, 0);  cout << "MGU Heat:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguHeat_1_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguHeat_1_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguHeat_1_.wear << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguHeat_2_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguHeat_2_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguHeat_2_.wear << endl;
            cout << "3:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.mguHeat_3_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.mguHeat_3_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.mguHeat_3_.wear << endl;

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
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguHeat_ = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond MGU Heat has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguHeat_ = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird MGU Heat has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguHeat_ = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.mguHeat_ = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '4':
            SetColor(14, 0);  cout << "Turbo Charger:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.turboCharger_1_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.turboCharger_1_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.turboCharger_1_.wear << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.turboCharger_2_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.turboCharger_2_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.turboCharger_2_.wear << endl;
            cout << "3:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.turboCharger_3_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.turboCharger_3_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.turboCharger_3_.wear << endl;

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
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.turboCharger_ = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Turbo Charger has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.turboCharger_ = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird Turbo Charger has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.turboCharger_ = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.turboCharger_ = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '5':
            SetColor(14, 0);  cout << "Energy Store:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.energyStore_1_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.energyStore_1_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.energyStore_1_.wear << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.energyStore_2_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.energyStore_2_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.energyStore_2_.wear << endl;

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
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.energyStore_ = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Energy Store has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.energyStore_ = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.energyStore_ = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '6':
            SetColor(14, 0);  cout << "Control Electronics:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.controlElectronics_1_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.controlElectronics_1_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.controlElectronics_1_.wear << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.powerUnitSet_.controlElectronics_2_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.powerUnitSet_.controlElectronics_2_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.powerUnitSet_.controlElectronics_2_.wear << endl;

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
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.controlElectronics_ = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Control Electronics Store has been fitted.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.controlElectronics_ = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents_.powerUnitSet_.chosenComponentsPowerUnit_.controlElectronics_ = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '7':
            SetColor(14, 0);  cout << "Practise Gearbox:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.gearboxSet_.practiceGearbox_1_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.gearboxSet_.practiceGearbox_1_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.gearboxSet_.practiceGearbox_1_.wear << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.gearboxSet_.practiceGearbox_2_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.gearboxSet_.practiceGearbox_2_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.gearboxSet_.practiceGearbox_2_.wear << endl;

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
                    seasonComponents_.gearboxSet_.chosenComponentsGearbox_.practiceGearbox_ = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Practise Gearbox has been fitted.";
                    seasonComponents_.gearboxSet_.chosenComponentsGearbox_.practiceGearbox_ = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents_.gearboxSet_.chosenComponentsGearbox_.practiceGearbox_ = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '8':
            SetColor(14, 0);  cout << "Event Gearbox:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.gearboxSet_.eventGearbox_1_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.gearboxSet_.eventGearbox_1_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.gearboxSet_.eventGearbox_1_.wear << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents_.gearboxSet_.eventGearbox_2_.expectedLifespan << endl;
            cout << "  Track Time: " << seasonComponents_.gearboxSet_.eventGearbox_2_.trackTime << endl;
            cout << "  Wear: " << seasonComponents_.gearboxSet_.eventGearbox_2_.wear << endl;

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
                    seasonComponents_.gearboxSet_.chosenComponentsGearbox_.eventGearbox_ = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Event Gearbox has been fitted.";
                    seasonComponents_.gearboxSet_.chosenComponentsGearbox_.eventGearbox_ = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents_.gearboxSet_.chosenComponentsGearbox_.eventGearbox_ = InstalledComponent::NOT_FITTED;
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

void Vehicle::setVehicleTotalComponentWearRatio(int aerodynamicsLevel, int powertrainLevel, int chassisLevel, int durabilityLevel)
{
    double tempTotalWear = seasonComponents_.totalComponentWearRatio_;

    tempTotalWear = tempTotalWear * 10;

    tempTotalWear = tempTotalWear - aerodynamicsLevel - powertrainLevel - chassisLevel - durabilityLevel;

    tempTotalWear = tempTotalWear / 10;

    seasonComponents_.totalComponentWearRatio_ = tempTotalWear;
}
