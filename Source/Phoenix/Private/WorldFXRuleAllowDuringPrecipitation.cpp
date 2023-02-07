#include "WorldFXRuleAllowDuringPrecipitation.h"

UWorldFXRuleAllowDuringPrecipitation::UWorldFXRuleAllowDuringPrecipitation() {
    this->AllowDuringPrecipitation = 3;
    this->AllowDuringTypes = 6;
    this->MaxCoverageThreshold = 0.05f;
    this->MaxIntensityThreshold = 0.10f;
}

