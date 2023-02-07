#include "ManualMoonSetup.h"

FManualMoonSetup::FManualMoonSetup() {
    this->Phase = EMoonPhaseName::NewMoon;
    this->PhasePercent = 0.00f;
    this->LightingAngle = 0.00f;
    this->SizeFactorPercent = 0.00f;
    this->BloodPercent = 0.00f;
    this->bOverride_Phase = false;
    this->bOverride_SizeFactor = false;
    this->bOverride_Blood = false;
}

