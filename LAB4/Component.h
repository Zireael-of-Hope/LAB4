#pragma once
#include <iostream>
#include <conio.h>

enum class ComponentID {
	Engine,
	MguKinetic,
	MguHeat,
	TurboCharger,
	EnergyStore,
	ControlElectronics,
	Gearbox
};

class Component
{
	int expectedLifespan;
	int trackTime;
	int wear;

public:
	int GetExpectedLifespan();
	int GetTrackTime();
	int GetWear();
	void SetExpectedLifespan(int newExpectedLifespan);
	void SetTrackTime(int newTrackTime);
	void SetWear(int wear);
	void SetFreshComponent(ComponentID componentName);
};

