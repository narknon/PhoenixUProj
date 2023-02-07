#include "EphemerisSubroutineFauxMoon.h"

UEphemerisSubroutineFauxMoon::UEphemerisSubroutineFauxMoon() {
    this->BaseOffsetDegrees = 180.00f;
    this->OffsetVarianceDegrees = 15.00f;
    this->OffsetPeriodDays = 28.00f;
    this->PhasePeriodDays = 28.00f;
    this->bEnabled = true;
    this->bOverride_PhasePeriodDays = false;
    this->bUseIdealDate = false;
}

