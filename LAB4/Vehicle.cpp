#include "Vehicle.h"

Vehicle::Vehicle()
{
    sponsorStickerQuantity = 0;
    vehicleName = "NoName";
    sponsorStickers = nullptr;
    seasonComponents.totalComponentWearRatio = 3;
    seasonComponents.powerUnitSet.internalCombastionEngine = InstalledComponent::NOT_FITTED;
    seasonComponents.powerUnitSet.mguKinetic = InstalledComponent::NOT_FITTED;
    seasonComponents.powerUnitSet.mguHeat = InstalledComponent::NOT_FITTED;
    seasonComponents.powerUnitSet.turboCharger = InstalledComponent::NOT_FITTED;
    seasonComponents.powerUnitSet.energyStore = InstalledComponent::NOT_FITTED;
    seasonComponents.powerUnitSet.controlElectronics = InstalledComponent::NOT_FITTED;

    seasonComponents.gearboxSet.eventGearbox = InstalledComponent::NOT_FITTED;
    seasonComponents.gearboxSet.practiceGearbox = InstalledComponent::NOT_FITTED;

}

Vehicle::~Vehicle()
{
}

void Vehicle::GetInfo()
{
    GetInfoName();
    GetInfoDriverName();
    GetSponsorStickers();
    GetInfoTyreSet();
    GetInfoTotalWear();
    GetInfoCombastionEngine();
    GetInfoVehicleMguKinetic();
    GetInfoMguHeat();
    GetInfoTurboCharger();
    GetInfoEnergyStore();
    GetInfoControlElectronics();
    GetInfoPractiseGerbox();
    GetInfoEventGerbox();
}

void Vehicle::GetInfoTotalWear()
{
    cout << "Total Component Wear Ratio: " << seasonComponents.totalComponentWearRatio << endl;
}

void Vehicle::GetSponsorStickers()
{
    int i;
    for (i = 0; i < sponsorStickerQuantity; i++)
        cout << "  " << sponsorStickers[i] << endl;
}

void Vehicle::AddSponsorSticker(string newSponsorName)
{
    int i;
    if (sponsorStickerQuantity == 0) {
        sponsorStickers = new string[1];
        sponsorStickers[0] = newSponsorName;
        sponsorStickerQuantity++;
    }
    else {
        string* new_arr = new string[sponsorStickerQuantity + 1];
        for (i = 0; i < sponsorStickerQuantity; i++) {
            new_arr[i] = sponsorStickers[i];
        }
        new_arr[sponsorStickerQuantity] = newSponsorName;
        delete[] sponsorStickers;
        sponsorStickers = new_arr;
        sponsorStickerQuantity++;
    }

}

bool Vehicle::DeleteSponsorSticker(string nameDelete)
{
    int i, j;
    bool isStickerFound = false;

    if (sponsorStickerQuantity != 0) {
        for (i = 0; i < sponsorStickerQuantity; i++)
            if (sponsorStickers[i] == nameDelete) {
                isStickerFound = true;
                for (j = i; j < sponsorStickerQuantity - 1; j++)
                    sponsorStickers[j] = sponsorStickers[j + 1];
            }
        if (isStickerFound == true) {
            string* new_arr = new string[sponsorStickerQuantity - 1];

            for (i = 0; i < sponsorStickerQuantity - 1; i++)
                new_arr[i] = sponsorStickers[i];

            delete[] sponsorStickers;

            sponsorStickers = new_arr;
            sponsorStickerQuantity--;
            return true;
        }
    }
    return false;
}

void Vehicle::GetInfoName()
{
    cout << "Vehicle Name: " << vehicleName << endl;
}

void Vehicle::GetInfoDriverName()
{
    cout << "Driver: " << driver.GetName() << endl;
}

void Vehicle::GetInfoTyreSet()
{
    switch (tyreSet.GetTyres()) {
    case TyresCompound::NOT_INSTALLED:
        cout << "Tyres aren't installed" << endl;
        break;
    case TyresCompound::SOFT:
        SetColor(4, 0);  cout << "SOFT "; SetColor(15, 0); cout << "tyres are installed" << endl;
        cout << "  Tyre Wear: " << tyreSet.GetTyreWear() << endl;
        break;
    case TyresCompound::MEDIUM:
        SetColor(6, 0);  cout << "MEDIUM "; SetColor(15, 0); cout << "tyres are installed" << endl;
        cout << "  Tyre Wear: " << tyreSet.GetTyreWear() << endl;
        break;
    case TyresCompound::HARD:
        cout << "HARD tyres are installed" << endl;
        cout << "  Tyre Wear: " << tyreSet.GetTyreWear() << endl;
        break;
    }
}

void Vehicle::GetInfoCombastionEngine()
{
    cout << "Internal Combastion Engine: ";
    switch (seasonComponents.powerUnitSet.internalCombastionEngine) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.engine1.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.engine1.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.engine1.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.engine2.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.engine2.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.engine2.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.engine3.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.engine3.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.engine3.GetWear() << endl;
        break;
    }
}

void Vehicle::GetInfoVehicleMguKinetic()
{
    cout << "MGU Kinetic: ";
    switch (seasonComponents.powerUnitSet.mguKinetic) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguKinetic1.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.mguKinetic1.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.mguKinetic1.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguKinetic2.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.mguKinetic2.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.mguKinetic2.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguKinetic3.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.mguKinetic3.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.mguKinetic3.GetWear() << endl;
        break;
    }
}

void Vehicle::GetInfoMguHeat()
{
    cout << "MGU Heat: ";
    switch (seasonComponents.powerUnitSet.mguHeat) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguHeat1.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.mguHeat1.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.mguHeat1.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguHeat2.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.mguHeat2.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.mguHeat2.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguHeat3.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.mguHeat3.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.mguHeat3.GetWear() << endl;
        break;
    }
}

void Vehicle::GetInfoTurboCharger()
{
    cout << "Turbo Charger: ";
    switch (seasonComponents.powerUnitSet.turboCharger) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.turboCharger1.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.turboCharger1.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.turboCharger1.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.turboCharger2.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.turboCharger2.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.turboCharger2.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_3:
        cout << "3" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.turboCharger3.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.turboCharger3.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.turboCharger3.GetWear() << endl;
        break;
    }
}

void Vehicle::GetInfoEnergyStore()
{
    cout << "Energy Store: ";
    switch (seasonComponents.powerUnitSet.energyStore) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.energyStore1.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.energyStore1.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.energyStore1.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.energyStore2.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.energyStore2.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.energyStore2.GetWear() << endl;
        break;
    }
}

void Vehicle::GetInfoControlElectronics()
{
    cout << "Control Electronics: ";
    switch (seasonComponents.powerUnitSet.controlElectronics) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.controlElectronics1.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.controlElectronics1.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.controlElectronics1.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.controlElectronics2.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.powerUnitSet.controlElectronics2.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.powerUnitSet.controlElectronics2.GetWear() << endl;
        break;
    }
}

void Vehicle::GetInfoPractiseGerbox()
{
    cout << "Practise Gearbox: ";
    switch (seasonComponents.gearboxSet.practiceGearbox) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.gearboxSet.practiceGearbox1.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.gearboxSet.practiceGearbox1.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.gearboxSet.practiceGearbox1.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.gearboxSet.practiceGearbox2.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.gearboxSet.practiceGearbox2.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.gearboxSet.practiceGearbox2.GetWear() << endl;
        break;
    }
}

void Vehicle::GetInfoEventGerbox()
{
    cout << "Event Gearbox: ";
    switch (seasonComponents.gearboxSet.eventGearbox) {
    case InstalledComponent::NOT_FITTED:
        cout << "not fitted" << endl;
        break;
    case InstalledComponent::COMPONENT_1:
        cout << "1" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.gearboxSet.eventGearbox1.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.gearboxSet.eventGearbox1.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.gearboxSet.eventGearbox1.GetWear() << endl;
        break;
    case InstalledComponent::COMPONENT_2:
        cout << "2" << endl;
        cout << "  Expected Lifespan: " << seasonComponents.gearboxSet.eventGearbox2.GetExpectedLifespan() << endl;
        cout << "  Track Time: " << seasonComponents.gearboxSet.eventGearbox2.GetTrackTime() << endl;
        cout << "  Wear: " << seasonComponents.gearboxSet.eventGearbox2.GetWear() << endl;
        break;
    }
}

void Vehicle::SetName(string newName)
{
    vehicleName = newName;
}

void Vehicle::SetTyres_interface()
{
    bool isPass, isCycled;
    char decision;

    do {
        isCycled = true;
        system("cls");
        SetColor(14, 0);
        cout << "Current Tyres: ";
        SetColor(15, 0);

        switch (tyreSet.GetTyres()) {
        case TyresCompound::NOT_INSTALLED:
            cout << " Tyres aren't installed" << endl;
            break;
        case TyresCompound::SOFT:
            SetColor(4, 0);  cout << "SOFT "; SetColor(15, 0); cout << "tyres are installed";
            cout << " Tyre Wear: " << tyreSet.GetTyreWear() << endl;
            break;
        case TyresCompound::MEDIUM:
            SetColor(6, 0);  cout << "MEDIUM "; SetColor(15, 0); cout << "tyres are installed";
            cout << " Tyre Wear: " << tyreSet.GetTyreWear() << endl;
            break;
        case TyresCompound::HARD:
            cout << "HARD tyres are installed";
            cout << " Tyre Wear: " << tyreSet.GetTyreWear() << endl;
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
            tyreSet.SetTyres(TyresCompound::SOFT);
            break;
        case '2':
            tyreSet.SetTyres(TyresCompound::MEDIUM);
            break;
        case '3':
            tyreSet.SetTyres(TyresCompound::HARD);
            break;
        case '0':
            isCycled = false;
            break;
        }
    } while (isCycled);
}

void Vehicle::SetComponents_interface()
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

        cout << "1) "; GetInfoCombastionEngine();
        cout << "2) "; GetInfoVehicleMguKinetic();
        cout << "3) "; GetInfoMguHeat();
        cout << "4) "; GetInfoTurboCharger();
        cout << "5) "; GetInfoEnergyStore();
        cout << "6) "; GetInfoControlElectronics();

        SetColor(14, 0);
        cout << "\nGearbox:" << endl;
        SetColor(15, 0);

        cout << "7) "; GetInfoPractiseGerbox();
        cout << "8) "; GetInfoEventGerbox();

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
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.engine1.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.engine1.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.engine1.GetWear() << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.engine2.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.engine2.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.engine2.GetWear() << endl;
            cout << "3:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.engine3.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.engine3.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.engine3.GetWear() << endl;

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
                    seasonComponents.powerUnitSet.internalCombastionEngine = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond engine has been fitted.";
                    seasonComponents.powerUnitSet.internalCombastionEngine = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird engine has been fitted.";
                    seasonComponents.powerUnitSet.internalCombastionEngine = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents.powerUnitSet.internalCombastionEngine = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '2':
            SetColor(14, 0);  cout << "MGU Kinetic:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguKinetic1.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.mguKinetic1.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.mguKinetic1.GetWear() << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguKinetic2.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.mguKinetic2.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.mguKinetic2.GetWear() << endl;
            cout << "3: " << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguKinetic3.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.mguKinetic3.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.mguKinetic3.GetWear() << endl;

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
                    seasonComponents.powerUnitSet.mguKinetic = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond MGU Kinetic has been fitted.";
                    seasonComponents.powerUnitSet.mguKinetic = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird MGU Kinetic has been fitted.";
                    seasonComponents.powerUnitSet.mguKinetic = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents.powerUnitSet.mguKinetic = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '3':
            SetColor(14, 0);  cout << "MGU Heat:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguHeat1.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.mguHeat1.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.mguHeat1.GetWear() << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguHeat2.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.mguHeat2.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.mguHeat2.GetWear() << endl;
            cout << "3:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.mguHeat3.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.mguHeat3.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.mguHeat3.GetWear() << endl;

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
                    seasonComponents.powerUnitSet.mguHeat = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond MGU Heat has been fitted.";
                    seasonComponents.powerUnitSet.mguHeat = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird MGU Heat has been fitted.";
                    seasonComponents.powerUnitSet.mguHeat = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents.powerUnitSet.mguHeat = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '4':
            SetColor(14, 0);  cout << "Turbo Charger:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.turboCharger1.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.turboCharger1.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.turboCharger1.GetWear() << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.turboCharger2.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.turboCharger2.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.turboCharger2.GetWear() << endl;
            cout << "3:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.turboCharger3.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.turboCharger3.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.turboCharger3.GetWear() << endl;

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
                    seasonComponents.powerUnitSet.turboCharger = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Turbo Charger has been fitted.";
                    seasonComponents.powerUnitSet.turboCharger = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nThird Turbo Charger has been fitted.";
                    seasonComponents.powerUnitSet.turboCharger = InstalledComponent::COMPONENT_3;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents.powerUnitSet.turboCharger = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '5':
            SetColor(14, 0);  cout << "Energy Store:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.energyStore1.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.energyStore1.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.energyStore1.GetWear() << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.energyStore2.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.energyStore2.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.energyStore2.GetWear() << endl;

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
                    seasonComponents.powerUnitSet.energyStore = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Energy Store has been fitted.";
                    seasonComponents.powerUnitSet.energyStore = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents.powerUnitSet.energyStore = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '6':
            SetColor(14, 0);  cout << "Control Electronics:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.controlElectronics1.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.controlElectronics1.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.controlElectronics1.GetWear() << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.powerUnitSet.controlElectronics2.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.powerUnitSet.controlElectronics2.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.powerUnitSet.controlElectronics2.GetWear() << endl;

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
                    seasonComponents.powerUnitSet.controlElectronics = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Control Electronics Store has been fitted.";
                    seasonComponents.powerUnitSet.controlElectronics = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents.powerUnitSet.controlElectronics = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '7':
            SetColor(14, 0);  cout << "Practise Gearbox:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.gearboxSet.practiceGearbox1.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.gearboxSet.practiceGearbox1.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.gearboxSet.practiceGearbox1.GetWear() << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.gearboxSet.practiceGearbox2.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.gearboxSet.practiceGearbox2.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.gearboxSet.practiceGearbox2.GetWear() << endl;

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
                    seasonComponents.gearboxSet.practiceGearbox = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Practise Gearbox has been fitted.";
                    seasonComponents.gearboxSet.practiceGearbox = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents.gearboxSet.practiceGearbox = InstalledComponent::NOT_FITTED;
                    Sleep(1500);
                    break;
                case '0':
                    break;
                }
            break;
        case '8':
            SetColor(14, 0);  cout << "Event Gearbox:" << endl; SetColor(15, 0);
            cout << "1:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.gearboxSet.eventGearbox1.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.gearboxSet.eventGearbox1.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.gearboxSet.eventGearbox1.GetWear() << endl;
            cout << "2:" << endl;
            cout << "  Expected Lifespan: " << seasonComponents.gearboxSet.eventGearbox2.GetExpectedLifespan() << endl;
            cout << "  Track Time: " << seasonComponents.gearboxSet.eventGearbox2.GetTrackTime() << endl;
            cout << "  Wear: " << seasonComponents.gearboxSet.eventGearbox2.GetWear() << endl;

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
                    seasonComponents.gearboxSet.eventGearbox = InstalledComponent::COMPONENT_1;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "\n\nSecond Event Gearbox has been fitted.";
                    seasonComponents.gearboxSet.eventGearbox = InstalledComponent::COMPONENT_2;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "\n\nComponent has been taken off.";
                    seasonComponents.gearboxSet.eventGearbox = InstalledComponent::NOT_FITTED;
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

void Vehicle::SetDriver(Driver newDriver)
{
    driver = newDriver;
}

void Vehicle::SetTotalComponentWearRatio(int aerodynamicsLevel, int powertrainLevel, int chassisLevel, int durabilityLevel)
{
    double tempTotalWear = seasonComponents.totalComponentWearRatio;

    tempTotalWear = tempTotalWear * 10;

    tempTotalWear = tempTotalWear - aerodynamicsLevel - powertrainLevel - chassisLevel - durabilityLevel;

    tempTotalWear = tempTotalWear / 10;

    seasonComponents.totalComponentWearRatio = tempTotalWear;
}
