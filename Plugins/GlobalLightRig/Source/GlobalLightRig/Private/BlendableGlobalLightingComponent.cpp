#include "BlendableGlobalLightingComponent.h"

UBlendableGlobalLightingComponent::UBlendableGlobalLightingComponent() {
    this->GlobalLightingBlendable = NULL;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbounded = true;
    this->bCameraExpHeightFogHeight_DEPRICATED = false;
    this->FogZMode = EGlobalLightingFogZMode::BaseOfVolume;
}

