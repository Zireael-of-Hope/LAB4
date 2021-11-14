#include "Facility.h"

void initFacility(Facility& facility)
{
    initBureau(facility.aerodynamics);
    initBureau(facility.powertrain);
    initBureau(facility.chassis);
    initBureau(facility.durability);
}

void FacilityGetInfoAerodynamics(Facility& facility)
{
    cout << "Aerodynamics: " << endl;
    cout << "   Level: " << BureauGetLevel(facility.aerodynamics) << endl;
    cout << "   Fabrication: " << BureauGetFabrication(facility.aerodynamics) << endl;
    cout << "   Build Time: " << BureauGetBuildTime(facility.aerodynamics) << endl;
    cout << "   Quality Control: " << BureauGetQualityControl(facility.aerodynamics) << endl;
    cout << "   Duraresource Point Generationbility: " << BureauGetResourcePointGeneration(facility.aerodynamics) << "\n" << endl;
}

void FacilityGetInfoPowertrain(Facility& facility)
{
    cout << "Powertrain: " << endl; 
    cout << "   Level: " << BureauGetLevel(facility.powertrain) << endl;
    cout << "   Fabrication: " << BureauGetFabrication(facility.powertrain) << endl;
    cout << "   Build Time: " << BureauGetBuildTime(facility.powertrain) << endl;
    cout << "   Quality Control: " << BureauGetQualityControl(facility.powertrain) << endl;
    cout << "   Duraresource Point Generationbility: " << BureauGetResourcePointGeneration(facility.powertrain) << "\n" << endl;
}

void FacilityGetInfoChassis(Facility& facility)
{
    cout << "Chassis: " << endl; 
    cout << "   Level: " << BureauGetLevel(facility.chassis) << endl;
    cout << "   Fabrication: " << BureauGetFabrication(facility.chassis) << endl;
    cout << "   Build Time: " << BureauGetBuildTime(facility.chassis) << endl;
    cout << "   Quality Control: " << BureauGetQualityControl(facility.chassis) << endl;
    cout << "   Duraresource Point Generationbility: " << BureauGetResourcePointGeneration(facility.chassis) << "\n" << endl;
}

void FacilityGetInfoDurability(Facility& facility)
{
    cout << "Durability: " << endl; 
    cout << "   Level: " << BureauGetLevel(facility.durability) << endl;
    cout << "   Fabrication: " << BureauGetFabrication(facility.durability) << endl;
    cout << "   Build Time: " << BureauGetBuildTime(facility.durability) << endl;
    cout << "   Quality Control: " << BureauGetQualityControl(facility.durability) << endl;
    cout << "   Duraresource Point Generationbility: " << BureauGetResourcePointGeneration(facility.durability) << "\n" << endl;
}

void FacilitySetBureausLevel_interface(Facility& facility)
{
    bool isPass, isCycled;
    char decision;

    do {
        isCycled = true;
        system("cls");

        SetColor(14, 0);
        cout << "Bereaus:\n" << endl;
        SetColor(15, 0);

        cout << "1) "; FacilityGetInfoAerodynamics(facility);
        cout << "" << endl;
        cout << "2) "; FacilityGetInfoPowertrain(facility);
        cout << "" << endl;
        cout << "3) "; FacilityGetInfoChassis(facility);
        cout << "" << endl;
        cout << "4) "; FacilityGetInfoDurability(facility);

        cout << "\nPick Bureau you want to upgrade (0 - return)...";

        do {
            isPass = false;
            decision = _getch();
            if (decision == '1' || decision == '2' || decision == '3' || decision == '4' || decision == '0')
                isPass = true;
        } while (isPass == false);

        switch (decision) {
        case '1':
            if (BureauGetLevel(facility.aerodynamics) < 4) {
                SetColor(14, 0);
                cout << "\nAerodynamics Bureau has been upgraded.";
                SetColor(15, 0);
                BureauUpgrade(facility.aerodynamics);
            }
            else cout << "\nAerodynamics Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '2':
            if (BureauGetLevel(facility.powertrain) < 4) {
                SetColor(14, 0);
                cout << "\nPowertrain Bureau has been upgraded.";
                SetColor(15, 0);
                BureauUpgrade(facility.powertrain);
            }
            else cout << "\nPowertrain Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '3':
            if (BureauGetLevel(facility.chassis) < 4) {
                SetColor(14, 0);
                cout << "\nChassis Bureau has been upgraded.";
                SetColor(15, 0);
                BureauUpgrade(facility.chassis);
            }
            else cout << "\nChassis Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '4':
            if (BureauGetLevel(facility.durability) < 4) {
                SetColor(14, 0);
                cout << "\nDurability Bureau has been upgraded.";
                SetColor(15, 0);
                BureauUpgrade(facility.durability);
            }
            else cout << "\nDurability Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '0':
            isCycled = false;
            break;
        }
    } while (isCycled == true);
}

int FacilityReturnAerodynamicsLevel(Facility& facility)
{
    return BureauGetLevel(facility.aerodynamics);
}

int FacilityReturnPowertrainLevel(Facility& facility)
{
    return BureauGetLevel(facility.powertrain);
}

int FacilityReturnChassisLevel(Facility& facility)
{
    return BureauGetLevel(facility.chassis);
}

int FacilityReturnDurabilityLevel(Facility& facility)
{
    return BureauGetLevel(facility.durability);
}
