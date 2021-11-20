#pragma once

enum class TyresCompound {
	NOT_INSTALLED,
	SOFT,
	MEDIUM,
	HARD
};

class Tyres {
	TyresCompound installedTyres;
	int tyreWear;

public:
	Tyres();
	~Tyres();

	int GetTyreWear();
	void SetTyres(TyresCompound newTyres);
	TyresCompound GetTyres();
};

