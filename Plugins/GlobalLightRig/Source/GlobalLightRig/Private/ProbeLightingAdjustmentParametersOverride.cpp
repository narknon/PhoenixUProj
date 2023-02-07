#include "ProbeLightingAdjustmentParametersOverride.h"

FProbeLightingAdjustmentParametersOverride::FProbeLightingAdjustmentParametersOverride() {
    this->bOverride_ProbeOutsideIntensity = false;
    this->bOverride_ProbeInsideIntensity = false;
    this->bOverride_ProbeOutsideSaturation = false;
    this->bOverride_ProbeInsideSaturation = false;
    this->ProbeOutsideIntensity = 0.00f;
    this->ProbeInsideIntensity = 0.00f;
    this->ProbeOutsideSaturation = 0.00f;
    this->ProbeInsideSaturation = 0.00f;
}

