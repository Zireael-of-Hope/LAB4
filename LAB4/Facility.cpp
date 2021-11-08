#include "Facility.h"

Facility::Facility()
{
    aerodynamics_ = { 1, 1, 1, 0.2, 1 };
    powertrain_ = { 1, 1, 1, 0.2, 1 };
    chassis_ = { 1, 1, 1, 0.2, 1 };
    durability_ = { 1, 1, 1, 0.2, 1 };
}

Facility::~Facility()
{
}

void Facility::getInfoBureauAerodynamics()
{
    cout << "Aerodynamics: " << endl;
    cout << "   Level: " << aerodynamics_.level << endl;
    cout << "   Fabrication: " << aerodynamics_.fabrication << endl;
    cout << "   Build Time: " << aerodynamics_.buildTime << endl;
    cout << "   Quality Control: " << aerodynamics_.qualityControl << endl;
    cout << "   Duraresource Point Generationbility: " << aerodynamics_.resourcePointGeneration << "\n" << endl;
}

void Facility::getInfoBureauPowertrain()
{
    cout << "Powertrain: " << endl;
    cout << "   Level: " << powertrain_.level << endl;
    cout << "   Fabrication: " << powertrain_.fabrication << endl;
    cout << "   Build Time: " << powertrain_.buildTime << endl;
    cout << "   Quality Control: " << powertrain_.qualityControl << endl;
    cout << "   Duraresource Point Generationbility: " << powertrain_.resourcePointGeneration << "\n" << endl;
}

void Facility::getInfoBureauChassis()
{
    cout << "Chassis: " << endl;
    cout << "   Level: " << chassis_.level << endl;
    cout << "   Fabrication: " << chassis_.fabrication << endl;
    cout << "   Build Time: " << chassis_.buildTime << endl;
    cout << "   Quality Control: " << chassis_.qualityControl << endl;
    cout << "   Duraresource Point Generationbility: " << chassis_.resourcePointGeneration << "\n" << endl;
}

void Facility::getInfoBureauDurability()
{
    cout << "Durability: " << endl;
    cout << "   Level: " << durability_.level << endl;
    cout << "   Fabrication: " << durability_.fabrication << endl;
    cout << "   Build Time: " << durability_.buildTime << endl;
    cout << "   Quality Control: " << durability_.qualityControl << endl;
    cout << "   Duraresource Point Generationbility: " << durability_.resourcePointGeneration << "\n" << endl;
}

void Facility::setFacilityBureausLevel_interface()
{
    bool isPass, isCycled;
    char decision;

    do {
        isCycled = true;
        system("cls");

        SetColor(14, 0);
        cout << "Bereaus:\n" << endl;
        SetColor(15, 0);

        cout << "1) "; getInfoBureauAerodynamics();
        cout << "" << endl;
        cout << "2) "; getInfoBureauPowertrain();
        cout << "" << endl;
        cout << "3) "; getInfoBureauChassis();
        cout << "" << endl;
        cout << "4) "; getInfoBureauDurability();

        cout << "\nPick Bureau you want to upgrade (0 - return)...";

        do {
            isPass = false;
            decision = _getch();
            if (decision == '1' || decision == '2' || decision == '3' || decision == '4' || decision == '0')
                isPass = true;
        } while (isPass == false);

        switch (decision) {
        case '1':
            if (aerodynamics_.level < 4) {
                SetColor(14, 0);
                cout << "\nAerodynamics Bureau has been upgraded.";
                SetColor(15, 0);
                aerodynamics_.level++;
                aerodynamics_.fabrication = aerodynamics_.fabrication - 0.15;
                aerodynamics_.buildTime = aerodynamics_.buildTime - 0.15;
                aerodynamics_.qualityControl = aerodynamics_.qualityControl - 0.06;
                aerodynamics_.resourcePointGeneration = aerodynamics_.resourcePointGeneration + 0.2;
            }
            else cout << "\nAerodynamics Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '2':
            if (powertrain_.level < 4) {
                SetColor(14, 0);
                cout << "\nPowertrain Bureau has been upgraded.";
                SetColor(15, 0);
                powertrain_.level++;
                powertrain_.fabrication = powertrain_.fabrication - 0.15;
                powertrain_.buildTime = powertrain_.buildTime - 0.15;
                powertrain_.qualityControl = powertrain_.qualityControl - 0.06;
                powertrain_.resourcePointGeneration = powertrain_.resourcePointGeneration + 0.2;
            }
            else cout << "\nPowertrain Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '3':
            if (chassis_.level < 4) {
                SetColor(14, 0);
                cout << "\nChassis Bureau has been upgraded.";
                SetColor(15, 0);
                chassis_.level++;
                chassis_.fabrication = chassis_.fabrication - 0.15;
                chassis_.buildTime = chassis_.buildTime - 0.15;
                chassis_.qualityControl = chassis_.qualityControl - 0.06;
                chassis_.resourcePointGeneration = chassis_.resourcePointGeneration + 0.2;
            }
            else cout << "\nChassis Bureau is already at the top level.";
            Sleep(1500);
            break;
        case '4':
            if (durability_.level < 4) {
                SetColor(14, 0);
                cout << "\nDurability Bureau has been upgraded.";
                SetColor(15, 0);
                durability_.level++;
                durability_.fabrication = durability_.fabrication - 0.15;
                durability_.buildTime = durability_.buildTime - 0.15;
                durability_.qualityControl = durability_.qualityControl - 0.06;
                durability_.resourcePointGeneration = durability_.resourcePointGeneration + 0.2;
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

int Facility::returnAerodynamicsLevel()
{
    return aerodynamics_.level;
}

int Facility::returnPowertrainLevel()
{
    return powertrain_.level;
}

int Facility::returnChassisLevel()
{
    return chassis_.level;
}

int Facility::returnDurabilityLevel()
{
    return durability_.level;
}
