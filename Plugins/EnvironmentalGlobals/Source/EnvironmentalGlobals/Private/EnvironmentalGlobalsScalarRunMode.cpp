#include "EnvironmentalGlobalsScalarRunMode.h"

FEnvironmentalGlobalsScalarRunMode::FEnvironmentalGlobalsScalarRunMode() {
    this->Mode = EEnvironmentalGlobalsRunMode::GameAndProbeCapture;
    this->GameDefaultValue = 0.00f;
    this->ProbeDefaultValue = 0.00f;
    this->bUseGameDefaultValue = false;
    this->bUseProbeDefaultValue = false;
}

