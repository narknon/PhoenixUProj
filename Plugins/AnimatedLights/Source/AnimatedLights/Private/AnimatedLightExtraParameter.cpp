#include "AnimatedLightExtraParameter.h"

FAnimatedLightExtraParameter::FAnimatedLightExtraParameter() {
    this->ToleranceThreshold = 0.00f;
    this->Value = EAnimatedLightExtraParameterValue::LightColor;
    this->OutputIntensityUnits = ELightUnits::Unitless;
    this->bOnlyUpdateOnce = false;
    this->bUseOutputIntensityUnits = false;
}

