#include "DayNightEventsCurrentAltitude.h"

FDayNightEventsCurrentAltitude::FDayNightEventsCurrentAltitude() {
    this->Altitude = 0.00f;
    this->Direction = EDayNightEventDirection::Rising;
    this->bValid = false;
}

