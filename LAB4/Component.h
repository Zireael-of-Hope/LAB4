#pragma once
#include <iostream>
#include <conio.h>

enum class InstalledComponent {
	NOT_FITTED,
	COMPONENT_1,
	COMPONENT_2,
	COMPONENT_3
};

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
	Component(ComponentID componentName);
	~Component();

	int GetExpectedLifespan();
	int GetTrackTime();
	int GetWear();
	void SetExpectedLifespan(int newExpectedLifespan);
	void SetTrackTime(int newTrackTime);
	void SetWear(int wear);
};

