#include "DayNightMoonAltitudeEvent.h"

FDayNightMoonAltitudeEvent::FDayNightMoonAltitudeEvent() {
    this->MoonAltitudeDegrees = 0.00f;
    this->MoonPhase = EMoonPhaseName::NewMoon;
    this->NightThreshold = 0.00f;
    this->DirectionTrigger = EDayNightEventDirectionTrigger::Rising;
    this->bAllowFireOnBeginPlay = false;
    this->bAllowFireOnDiscontinuity = false;
    this->bUseMoonPhase = false;
    this->bUseNightThreshold = false;
}

