#include "WorldFXRuleWeatherWindSpeedRange.h"

UWorldFXRuleWeatherWindSpeedRange::UWorldFXRuleWeatherWindSpeedRange() {
    this->minThreshold = EBeaufortWindScale::ModerateBreeze;
    this->maxThreshold = EBeaufortWindScale::StrongBreeze;
}

