#include "RenderSettingsPostProcessingVolume.h"

void ARenderSettingsPostProcessingVolume::Update() {
}

void ARenderSettingsPostProcessingVolume::SetPriority(float NewPriority) {
}

ARenderSettingsPostProcessingVolume::ARenderSettingsPostProcessingVolume() {
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bUnbounded = false;
    this->bEnabled = true;
}

