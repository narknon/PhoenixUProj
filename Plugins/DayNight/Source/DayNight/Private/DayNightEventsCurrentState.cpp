#include "DayNightEventsCurrentState.h"

FDayNightEventsCurrentState::FDayNightEventsCurrentState() {
    this->NormalizedTime = 0.00f;
    this->MoonPhase = EMoonPhaseName::NewMoon;
    this->bValid = false;
}

