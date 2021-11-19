#pragma once

enum class TyresCompound {
	NOT_INSTALLED,
	SOFT,
	MEDIUM,
	HARD
};

struct Tyres
{
	TyresCompound installedTyres;
	int tyreWear;
};

void initTyres(Tyres& tyres);
int GetTyreWear(Tyres& tyres);
void SetTyres(Tyres& tyres, TyresCompound newTyres);
TyresCompound GetTyres(Tyres& tyres);

