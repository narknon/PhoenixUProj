#include "EphemeralSkyState.h"

FEphemeralSkyState::FEphemeralSkyState() {
    this->Basis = NULL;
    this->NightDayNegOneToOne = 0.00f;
    this->NightDayLerp = 0.00f;
    this->NightLerp = 0.00f;
    this->DayLerp = 0.00f;
    this->NightSkyStrength = 0.00f;
    this->bTimeLerped = false;
    this->bNormalizedTimeValid = false;
    this->bSunValid = false;
    this->bMoonValid = false;
    this->bPlanetsValid = false;
    this->bCelestialSphereValid = false;
    this->bComputed = false;
    this->bUsingSecondaryDirectionalLight = false;
}

