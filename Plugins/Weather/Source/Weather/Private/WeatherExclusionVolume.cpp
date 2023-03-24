#include "WeatherExclusionVolume.h"

void AWeatherExclusionVolume::SetPriority(float NewPriority) {
}

AWeatherExclusionVolume::AWeatherExclusionVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bHideCameraFX = true;
    this->bHideSurfaceFX = false;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
}

