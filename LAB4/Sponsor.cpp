#include "Sponsor.h"

Sponsor::Sponsor()
{
    name_ = "NoName";
    color_ = 15;
    targetRace_ = SponsorTargetRace::FINISH;
    targetSeason_ = SponsorTargetSeason::NOT_LAST;
    paymentPerRace_ = 0;
    targetBonusRatio_ = 1;
}

Sponsor::~Sponsor()
{
}

void Sponsor::setName(string newName)
{
    name_ = newName;
}

void Sponsor::setColor_interface()
{
    bool isPass;

    SetColor(1, 0);
    puts("1) 0000000000000000000000000");
    SetColor(2, 0);
    puts("2) 0000000000000000000000000");
    SetColor(3, 0);
    puts("3) 0000000000000000000000000");
    SetColor(4, 0);
    puts("4) 0000000000000000000000000");
    SetColor(5, 0);
    puts("5) 0000000000000000000000000");
    SetColor(6, 0);
    puts("6) 0000000000000000000000000");
    SetColor(7, 0);
    puts("7) 0000000000000000000000000");
    SetColor(8, 0);
    puts("8) 0000000000000000000000000");
    SetColor(9, 0);
    puts("9) 0000000000000000000000000");
    SetColor(10, 0);
    puts("10) 000000000000000000000000");
    SetColor(11, 0);
    puts("11) 000000000000000000000000");
    SetColor(12, 0);
    puts("12) 000000000000000000000000");
    SetColor(13, 0);
    puts("13) 000000000000000000000000");
    SetColor(14, 0);
    puts("14) 000000000000000000000000");
    SetColor(15, 0);
    puts("15) 000000000000000000000000");

    cout << "\nChoose the color you like: ";

    do {
        isPass = false;
        cin >> color_;
        cin.get();
        if (color_ > 0 && color_ < 16)
            isPass = true;
    } while (isPass == false);
}

void Sponsor::setTargetRace_interface()
{
    bool isPass;
    int decision;

    cout << "1) Podium" << endl;
    cout << "2) TOP 5" << endl;
    cout << "3) TOP 10" << endl;
    cout << "4) To Finish\n" << endl;
    cout << "Select sponsor's target for the race: ";

    do {
        isPass = false;
        cin >> decision;
        cin.get();
        if (decision >= 1 && decision <= 4)
            isPass = true;
    } while (isPass == false);

    switch (decision) {
    case '1':
        targetRace_ = SponsorTargetRace::PODIUM;
        break;
    case '2':
        targetRace_ = SponsorTargetRace::TOP_5;
        break;
    case '3':
        targetRace_ = SponsorTargetRace::TOP_10;
        break;
    case '4':
        targetRace_ = SponsorTargetRace::FINISH;
        break;
    }
}

void Sponsor::setTargetSeason_interface()
{
    bool isPass;
    int decision;

    cout << "1) One of the driver is champion" << endl;
    cout << "2) TOP 3" << endl;
    cout << "3) TOP 5" << endl;
    cout << "4) Finish every race" << endl;
    cout << "5) Not last in the season\n" << endl;
    cout << "Select sponsor's target for the season: ";

    do {
        isPass = false;
        cin >> decision;
        cin.get();
        if (decision >= 1 && decision <= 4)
            isPass = true;
    } while (isPass == false);

    switch (decision) {
    case '1':
        targetSeason_ = SponsorTargetSeason::CHAMP;
        break;
    case '2':
        targetSeason_ = SponsorTargetSeason::TOP_THREE;
        break;
    case '3':
        targetSeason_ = SponsorTargetSeason::TOP_FIVE;
        break;
    case '4':
        targetSeason_ = SponsorTargetSeason::EVERY_RACE_PARTICIPATE;
        break;
    case '5':
        targetSeason_ = SponsorTargetSeason::NOT_LAST;
        break;
    }
}

void Sponsor::setPaymentPerRace(double newPaymentPerRace)
{
    paymentPerRace_ = newPaymentPerRace;
}

void Sponsor::setTargetBonusRatio(double newTargetBonusRatio)
{
    targetBonusRatio_ = newTargetBonusRatio;
}

void Sponsor::getInfoSponsor()
{
    int i;
    bool isPass;
    char decision;
    char color_line[20] = { 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219 };

    cout << "Sponsor " << name_ << endl;

    cout << "Color: ";
    SetColor(color_, 0);
    for (i = 0; i < 20; i++)
        cout << color_line[i];
    SetColor(15, 0);

    cout << "\nRace Target: ";
    switch (targetRace_) {
    case SponsorTargetRace::PODIUM:
        cout << "Podium" << endl;
        break;
    case SponsorTargetRace::TOP_5:
        cout << "TOP 5" << endl;
        break;
    case SponsorTargetRace::TOP_10:
        cout << "TOP 10" << endl;
        break;
    case SponsorTargetRace::FINISH:
        cout << "Cross the finish line" << endl;
        break;
    }

    cout << "Season Target: ";
    switch (targetSeason_) {
    case SponsorTargetSeason::CHAMP:
        cout << "One of the drivers is champion" << endl;
        break;
    case SponsorTargetSeason::TOP_THREE:
        cout << "TOP 3" << endl;
        break;
    case SponsorTargetSeason::TOP_FIVE:
        cout << "TOP 5" << endl;
        break;
    case SponsorTargetSeason::NOT_LAST:
        cout << "Not Last" << endl;
        break;
    }

    cout << "Income per race: " << paymentPerRace_ << endl;

    cout << "Target bonus ratio: " << targetBonusRatio_ << endl;

}

double Sponsor::getPaymentPerRace()
{
    return paymentPerRace_;
}
