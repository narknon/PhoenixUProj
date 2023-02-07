#include "FixedSunPositions.h"

UFixedSunPositions::UFixedSunPositions() {
    this->TransitionTime = 30.00f;
    this->TransitionEaseInOutPower = 2.00f;
    this->SunriseDurationMinutes = 30.00f;
    this->NoonDurationHours = 2.50f;
    this->SunsetDurationMinutes = 30.00f;
    this->MidnightDurationHours = 4.00f;
    this->bNoonDuration = false;
    this->bSunriseDuration = false;
    this->bMidnightDuration = false;
    this->bSunsetDuration = false;
}

