#include "EphemerisSubroutineFixedIdealMoonPath.h"

UEphemerisSubroutineFixedIdealMoonPath::UEphemerisSubroutineFixedIdealMoonPath() {
    this->AzimuthMode = EMoonPathMode::MoonRelative;
    this->AzimuthOffsetDegrees = 0.00f;
    this->bEnabled = true;
}

