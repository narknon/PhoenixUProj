#include "WeatherExclusionComponent.h"

void UWeatherExclusionComponent::SetPriority(float NewPriority) {
}

UWeatherExclusionComponent::UWeatherExclusionComponent() {
    this->bHideCameraFX = true;
    this->bHideSurfaceFX = false;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
}

