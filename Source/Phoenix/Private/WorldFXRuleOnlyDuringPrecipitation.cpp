#include "WorldFXRuleOnlyDuringPrecipitation.h"

UWorldFXRuleOnlyDuringPrecipitation::UWorldFXRuleOnlyDuringPrecipitation() {
    this->Precipitation = 3;
    this->Types = 6;
    this->MinCoverageThreshold = 0.00f;
    this->MaxCoverageThreshold = 1.00f;
    this->MinIntensityThreshold = 0.00f;
    this->MaxIntensityThreshold = 1.00f;
}

