#include "EnvironmentalGlobalsColorRunMode.h"

FEnvironmentalGlobalsColorRunMode::FEnvironmentalGlobalsColorRunMode() {
    this->Mode = EEnvironmentalGlobalsRunMode::GameAndProbeCapture;
    this->bUseGameDefaultValue = false;
    this->bUseProbeDefaultValue = false;
}

