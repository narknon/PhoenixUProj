#include "WorldFXAudioEventExtra.h"

FWorldFXAudioEventExtra::FWorldFXAudioEventExtra() {
    this->AttenuationScalingFactor = 0.00f;
    this->NoTickRadius = 0.00f;
    this->OcclusionRefreshInterval = 0.00f;
    this->OcclusionCollisionChannel = ECC_WorldStatic;
    this->bUseReverbVolumes = false;
    this->bEnableSpotReflectors = false;
    this->OuterRadius = 0.00f;
    this->InnerRadius = 0.00f;
}

