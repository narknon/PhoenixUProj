#include "EphemerisSubroutineDynamicIdealMoonPath.h"

UEphemerisSubroutineDynamicIdealMoonPath::UEphemerisSubroutineDynamicIdealMoonPath() {
    this->AzimuthMode = EMoonPathMode::MoonRelative;
    this->AzimuthOffsetDegrees = 0.00f;
    this->bEnabled = true;
}

