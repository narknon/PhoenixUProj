#include "DayNightOverrideComponent.h"

void UDayNightOverrideComponent::SetPriority(float NewPriority) {
}

UDayNightOverrideComponent::UDayNightOverrideComponent() {
    this->OverrideBasis = NULL;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbounded = true;
    this->bAppendToMasterEphemerisProgram = false;
    this->LastUpdate = 0.00f;
    this->InitializedComputer = 0;
}

