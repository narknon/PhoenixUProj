#include "EphemerisSubroutineIdealSunPath.h"

UEphemerisSubroutineIdealSunPath::UEphemerisSubroutineIdealSunPath() {
    this->GamifyTime = NULL;
    this->bEnabled = true;
    this->bUseRemapNormalizedTime = false;
    this->bRemapNormalizedTimeIs12Hour = true;
}

