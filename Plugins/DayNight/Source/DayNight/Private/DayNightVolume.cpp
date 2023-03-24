#include "DayNightVolume.h"

void ADayNightVolume::SetPriority(float NewPriority) {
}

ADayNightVolume::ADayNightVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OverrideBasis = NULL;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bUnbounded = false;
    this->bEnabled = true;
    this->bAppendToMasterEphemerisProgram = false;
    this->LastUpdate = 0.00f;
    this->InitializedComputer = 0;
}

