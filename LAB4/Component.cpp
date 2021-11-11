#include "Component.h"

int Component::GetExpectedLifespan()
{
	return expectedLifespan;
}

int Component::GetTrackTime()
{
	return trackTime;
}

int Component::GetWear()
{
	return wear;
}

void Component::SetExpectedLifespan(int newExpectedLifespan)
{
	expectedLifespan = newExpectedLifespan;
}

void Component::SetTrackTime(int newTrackTime)
{
	trackTime = newTrackTime;
}

void Component::SetWear(int newWear)
{
	wear = newWear;
}

void Component::SetFreshComponent(ComponentID componentName)
{
	switch (componentName) {
	case ComponentID::Engine:
		expectedLifespan = 340;
		break;
	case ComponentID::MguKinetic:
		expectedLifespan = 800;
		break;
	case ComponentID::MguHeat:
		expectedLifespan = 700;
		break;
	case ComponentID::TurboCharger:
		expectedLifespan = 500;
		break;
	case ComponentID::EnergyStore:
		expectedLifespan = 900;
		break;
	case ComponentID::ControlElectronics:
		expectedLifespan = 450;
		break;
	case ComponentID::Gearbox:
		expectedLifespan = 380;
		break;
	}

	trackTime = 0;
	wear = 0;
}


