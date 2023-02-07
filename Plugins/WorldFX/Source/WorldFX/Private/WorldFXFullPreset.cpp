#include "WorldFXFullPreset.h"

FWorldFXFullPreset::FWorldFXFullPreset() {
    this->SFXAudioEvent = NULL;
    this->SFXCullingDistanceMeters = 0.00f;
    this->SFXCullingDistanceType = EWorldFXDistanceType::UseDefault;
    this->SFXAttenuationScalingFactor = 0.00f;
    this->SFXNoTickRadius = 0.00f;
    this->SFXOcclusionRefreshInterval = 0.00f;
    this->SFXOcclusionCollisionChannel = ECC_WorldStatic;
    this->bSFXUseReverbVolumes = false;
    this->bSFXEnableSpotReflectors = false;
    this->SFXOuterRadius = 0.00f;
    this->SFXInnerRadius = 0.00f;
    this->CascadeCullingDistanceMeters = 0.00f;
    this->CascadeCullingDistanceType = EWorldFXDistanceType::UseDefault;
    this->NiagaraCullingDistanceMeters = 0.00f;
    this->NiagaraCullingDistanceType = EWorldFXDistanceType::UseDefault;
    this->bSpawnAttached = false;
}

