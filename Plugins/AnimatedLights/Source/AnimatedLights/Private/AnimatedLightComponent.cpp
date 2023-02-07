#include "AnimatedLightComponent.h"

UAnimatedLightComponent::UAnimatedLightComponent() {
    this->ColorCurve_DEPRICATED = NULL;
    this->IntensityCurve_DEPRICATED = NULL;
    this->WaveSpeed1 = 8.70f;
    this->WaveSpeed2 = 15.00f;
    this->MinIntensity = 0.20f;
    this->IntensityNoiseType = EAnimatedLightComponentNoiseType::AddAndSubtract;
    this->IntensityNoiseSpeed = 2.00f;
    this->IntensityNoiseFactor = 0.25f;
    this->HueNoiseType = EAnimatedLightComponentNoiseType::AddAndSubtract;
    this->HueNoiseSpeed = 2.50f;
    this->HueNoiseAmount = 25.00f;
    this->SaturationNoiseType = EAnimatedLightComponentNoiseType::SubtractOnly;
    this->SaturationNoiseSpeed = 2.25f;
    this->SaturationNoiseAmount = 0.25f;
    this->UseMathBased = false;
    this->bAddIntensityNoise = false;
    this->bAddHSVNoise = false;
    this->bLoopColorCurve_DEPRICATED = false;
    this->bLoopIntensityCurve_DEPRICATED = false;
}

