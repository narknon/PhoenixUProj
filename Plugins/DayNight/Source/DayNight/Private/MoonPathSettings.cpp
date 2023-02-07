#include "MoonPathSettings.h"

FMoonPathSettings::FMoonPathSettings() {
    this->SamplePoints = 0;
    this->CubicTension = 0.00f;
    this->bHighAccuracyPosition = false;
    this->bTrueTopoCentric = false;
    this->bRemoveRedundantKeys = false;
    this->bCubicInterpolation = false;
}

