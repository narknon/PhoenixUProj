#include "EphemeralMoonState.h"

FEphemeralMoonState::FEphemeralMoonState() {
    this->UnitSize = 0.00f;
    this->Phase = 0.00f;
    this->DiskPhase = 0.00f;
    this->PhaseName = EMoonPhaseName::NewMoon;
    this->Blood = 0.00f;
    this->MoonPeriodDaysOverride = 0.00f;
    this->DiskScale = 0.00f;
    this->AboveHorizon = 0.00f;
    this->Visibility = 0.00f;
    this->SunAngleDegrees = 0.00f;
}

