#include "MountViewDistanceLimiter.h"

UMountViewDistanceLimiter::UMountViewDistanceLimiter() {
    this->CameraHeightRenderSettingsComponent = NULL;
    this->MaxFogOnOffValue = 1.00f;
    this->FogOnOffInterpSpeed = 0.10f;
}

