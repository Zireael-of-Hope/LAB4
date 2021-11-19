#include "Tyres.h"

void initTyres(Tyres& tyres)
{
    tyres.installedTyres = TyresCompound::NOT_INSTALLED;
}

int GetTyreWear(Tyres& tyres)
{
    return tyres.tyreWear;
}

void SetTyres(Tyres& tyres, TyresCompound newTyres)
{
    tyres.installedTyres = newTyres;
    tyres.tyreWear = 0;
}

TyresCompound GetTyres(Tyres& tyres)
{
    return tyres.installedTyres;
}
