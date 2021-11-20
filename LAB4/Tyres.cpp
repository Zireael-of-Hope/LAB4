#include "Tyres.h"

Tyres::Tyres()
{
	installedTyres = TyresCompound::NOT_INSTALLED;
}

Tyres::~Tyres()
{
}

int Tyres::GetTyreWear()
{
	return tyreWear;
}

void Tyres::SetTyres(TyresCompound newTyres)
{
	installedTyres = newTyres;
	tyreWear = 0;
}

TyresCompound Tyres::GetTyres()
{
	return installedTyres;
}