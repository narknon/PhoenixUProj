#include "DayNightSunAltitudeEvent.h"

FDayNightSunAltitudeEvent::FDayNightSunAltitudeEvent() {
    this->SunAltitudeDegrees = 0.00f;
    this->DirectionTrigger = EDayNightEventDirectionTrigger::Rising;
    this->bAllowFireOnBeginPlay = false;
    this->bAllowFireOnDiscontinuity = false;
}

