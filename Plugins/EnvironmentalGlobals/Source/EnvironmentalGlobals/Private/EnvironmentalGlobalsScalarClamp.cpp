#include "EnvironmentalGlobalsScalarClamp.h"

FEnvironmentalGlobalsScalarClamp::FEnvironmentalGlobalsScalarClamp() {
    this->ClampMin = 0.00f;
    this->ClampMax = 0.00f;
    this->ClampMinMaxConversion = EEnvironmentalGlobalsScalarConversion::None;
    this->bUseMin = false;
    this->bUseMax = false;
}

