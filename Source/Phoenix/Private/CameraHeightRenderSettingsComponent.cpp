#include "CameraHeightRenderSettingsComponent.h"

UCameraHeightRenderSettingsComponent::UCameraHeightRenderSettingsComponent() {
    this->StartEffectHeightMeters = 20.00f;
    this->FullEffectHeightMeters = 100.00f;
    this->Base = EWorldBaseHeightAffect::ExponentialHeightFog;
}

