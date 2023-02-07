#include "DayNightSunAltitudeChangeEvent.h"

FDayNightSunAltitudeChangeEvent::FDayNightSunAltitudeChangeEvent() {
    this->SunAltitudeChangeDegrees = 0.00f;
    this->Direction = EDayNightEventDirectionTrigger::Rising;
    this->SunMinAltitudeDegrees = 0.00f;
    this->SunMaxAltitudeDegrees = 0.00f;
    this->bAllowFireOnBeginPlay = false;
    this->bAllowFireOnDiscontinuity = false;
}

