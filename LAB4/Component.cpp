#include "Component.h"

void initComponent(Component& component, ComponentID componentName)
{
	switch (componentName) {
	case ComponentID::Engine:
		component.expectedLifespan = 340;
		break;
	case ComponentID::MguKinetic:
		component.expectedLifespan = 800;
		break;
	case ComponentID::MguHeat:
		component.expectedLifespan = 700;
		break;
	case ComponentID::TurboCharger:
		component.expectedLifespan = 500;
		break;
	case ComponentID::EnergyStore:
		component.expectedLifespan = 900;
		break;
	case ComponentID::ControlElectronics:
		component.expectedLifespan = 450;
		break;
	case ComponentID::Gearbox:
		component.expectedLifespan = 380;
		break;
	}

	component.trackTime = 0;
	component.wear = 0;
}

int ComponentGetExpectedLifespan(Component& component)
{
	return component.expectedLifespan;
}

int ComponentGetTrackTime(Component& component)
{
	return component.trackTime;
}

int ComponentGetWear(Component& component)
{
	return component.wear;
}

void ComponentSetExpectedLifespan(Component& component, int newExpectedLifespan)
{
	component.expectedLifespan = newExpectedLifespan;
}

void ComponentSetTrackTime(Component& component, int newTrackTime)
{
	component.trackTime = newTrackTime;
}

void ComponentSetWear(Component& component, int newWear)
{
	component.wear = newWear;
}
