#include "LightSmoothOnOff.h"

void ULightSmoothOnOff::TurnOnOff(bool On, bool smooth) {
}

void ULightSmoothOnOff::SetIntensity(float NewIntensity, bool Filter) {
}

bool ULightSmoothOnOff::IsOnSmoothed() const {
    return false;
}

bool ULightSmoothOnOff::IsOn() const {
    return false;
}

void ULightSmoothOnOff::Initialize(float Intensity, bool Visible) {
}

float ULightSmoothOnOff::GetSmoothedIntensity() const {
    return 0.0f;
}

float ULightSmoothOnOff::GetIntensity() const {
    return 0.0f;
}

void ULightSmoothOnOff::AbortFadeOn(bool abortFade) {
}

void ULightSmoothOnOff::AbortFadeOff(bool abortFade) {
}

ULightSmoothOnOff::ULightSmoothOnOff() {
    this->DefaultIntensity = 3.14f;
    this->IntensityChangeFilter = 0.10f;
    this->DisableIntensityFilter = false;
    this->TurnOnDuration = 1.00f;
    this->TurnOffDuration = 1.00f;
    this->DisableOnOffSmoothing = false;
    this->TimeFactor = 1.00f;
}

