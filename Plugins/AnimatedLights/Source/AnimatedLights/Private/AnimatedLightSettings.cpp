#include "AnimatedLightSettings.h"

FAnimatedLightSettings::FAnimatedLightSettings() {
    this->WaveSpeed1 = 0.00f;
    this->WaveSpeed2 = 0.00f;
    this->MinIntensity = 0.00f;
    this->IntensityNoiseType = EAnimatedLightComponentNoiseType::AddAndSubtract;
    this->IntensityNoiseSpeed = 0.00f;
    this->IntensityNoiseFactor = 0.00f;
    this->HueNoiseType = EAnimatedLightComponentNoiseType::AddAndSubtract;
    this->HueNoiseSpeed = 0.00f;
    this->HueNoiseAmount = 0.00f;
    this->SaturationNoiseType = EAnimatedLightComponentNoiseType::AddAndSubtract;
    this->SaturationNoiseSpeed = 0.00f;
    this->SaturationNoiseAmount = 0.00f;
    this->bIntensityFlicker = false;
    this->bAddIntensityNoise = false;
    this->bAddHSVNoise = false;
}

