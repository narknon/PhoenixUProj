#include "DayNightLightRig.h"

UDayNightLightRig::UDayNightLightRig() {
    this->MinimumDirectionalLightIntensity = 0.00f;
    this->DayNightLerpDirection = NULL;
    this->BlendOps = 16383;
}

