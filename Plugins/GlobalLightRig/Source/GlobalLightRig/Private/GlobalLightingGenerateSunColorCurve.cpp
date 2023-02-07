#include "GlobalLightingGenerateSunColorCurve.h"

FGlobalLightingGenerateSunColorCurve::FGlobalLightingGenerateSunColorCurve() {
    this->SunAngleStart = 0.00f;
    this->SunAngleEnd = 0.00f;
    this->SunAngleIncrement = 0.00f;
    this->ErrorTolerance = 0.00f;
    this->bCubic = false;
}

