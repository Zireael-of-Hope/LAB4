#include "Facility.h"

Facility::Facility()
{
}

Facility::~Facility()
{
}

void Facility::GetInfoBureauAerodynamics()
{
    cout << "Aerodynamics: " << endl;
    cout << "   Level: " << aerodynamics.GetLevel() << endl;
    cout << "   Fabrication: " << aerodynamics.GetFabrication() << endl;
    cout << "   Build Time: " << aerodynamics.GetBuildTime() << endl;
    cout << "   Quality Control: " << aerodynamics.GetQualityControl() << endl;
    cout << "   Duraresource Point Generationbility: " << aerodynamics.GetResourcePointGeneration() << "\n" << endl;
}

void Facility::GetInfoBureauPowertrain()
{
    cout << "Powertrain: " << endl;
    cout << "   Level: " << powertrain.GetLevel() << endl;
    cout << "   Fabrication: " << powertrain.GetFabrication() << endl;
    cout << "   Build Time: " << powertrain.GetBuildTime() << endl;
    cout << "   Quality Control: " << powertrain.GetQualityControl() << endl;
    cout << "   Duraresource Point Generationbility: " << powertrain.GetResourcePointGeneration() << "\n" << endl;
}

void Facility::GetInfoBureauChassis()
{
    cout << "Chassis: " << endl;
    cout << "   Level: " << chassis.GetLevel() << endl;
    cout << "   Fabrication: " << chassis.GetFabrication() << endl;
    cout << "   Build Time: " << chassis.GetBuildTime() << endl;
    cout << "   Quality Control: " << chassis.GetQualityControl() << endl;
    cout << "   Duraresource Point Generationbility: " << chassis.GetResourcePointGeneration() << "\n" << endl;
}

void Facility::GetInfoBureauDurability()
{
    cout << "Durability: " << endl;
    cout << "   Level: " << durability.GetLevel() << endl;
    cout << "   Fabrication: " << durability.GetFabrication() << endl;
    cout << "   Build Time: " << durability.GetBuildTime() << endl;
    cout << "   Quality Control: " << durability.GetQualityControl() << endl;
    cout << "   Duraresource Point Generationbility: " << durability.GetResourcePointGeneration() << "\n" << endl;
}

void Facility::SetFacilityBureausLevel_interface()
{
    bool isPass, isCycled;
    char decision;

    do {
        isCycled = true;
        system("cls");

        SetColor(14, 0);
        cout << "Bereaus:\n" << endl;
        SetColor(15, 0);

        cout << "1) "; GetInfoBureauAerodynamics();
        cout << "" << endl;
        cout << "2) "; GetInfoBureauPowertrain();
        cout << "" << endl;
        cout << "3) "; GetInfoBureauChassis();
        cout << "" << endl;
        cout << "4) "; GetInfoBureauDurability();

        cout << "\nPick Bureau you want to upgrade (0 - return)...";

        do {
            isPass = false;
            decision = _getch();
            if (decision == '1' || decision == '2' || decision == '3' || decision == '4' || decision == '0')
                isPass = true;
        } while (isPass == false);

        switch (decision) {
        case '1':
            if (aerodynamics.GetLevel() < 4) {
                SetColor(14, 0);
                cout << "\nAerodynamics Bureau has been upgraded.";
                SetColor(15, 0);
                aerodynamics.UpgradeBureau();
            }
            else cout << "\nAerodynamics Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '2':
            if (powertrain.GetLevel() < 4) {
                SetColor(14, 0);
                cout << "\nPowertrain Bureau has been upgraded.";
                SetColor(15, 0);
                powertrain.UpgradeBureau();
            }
            else cout << "\nPowertrain Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '3':
            if (chassis.GetLevel() < 4) {
                SetColor(14, 0);
                cout << "\nChassis Bureau has been upgraded.";
                SetColor(15, 0);
                chassis.UpgradeBureau();
            }
            else cout << "\nChassis Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '4':
            if (durability.GetLevel() < 4) {
                SetColor(14, 0);
                cout << "\nDurability Bureau has been upgraded.";
                SetColor(15, 0);
                durability.UpgradeBureau();
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

int Facility::ReturnAerodynamicsLevel()
{
    return aerodynamics.GetLevel();
}

int Facility::ReturnPowertrainLevel()
{
    return powertrain.GetLevel();
}

int Facility::ReturnChassisLevel()
{
    return chassis.GetLevel();
}

int Facility::ReturnDurabilityLevel()
{
    return durability.GetLevel();
}
