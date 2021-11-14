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

struct Component
{
	int expectedLifespan;
	int trackTime;
	int wear;
};

void initComponent(Component& component, ComponentID componentName);

int ComponentGetExpectedLifespan(Component& component);
int ComponentGetTrackTime(Component& component);
int ComponentGetWear(Component& component);
void ComponentSetExpectedLifespan(Component& component, int newExpectedLifespan);
void ComponentSetTrackTime(Component& component, int newTrackTime);
void ComponentSetWear(Component& component, int wear);

