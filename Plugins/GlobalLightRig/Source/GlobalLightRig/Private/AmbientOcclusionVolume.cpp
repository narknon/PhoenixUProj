#include "AmbientOcclusionVolume.h"

void AAmbientOcclusionVolume::UpdatePostProcessSettings() {
}

void AAmbientOcclusionVolume::SetPriority(float NewPriority) {
}

AAmbientOcclusionVolume::AAmbientOcclusionVolume() {
    this->BlendablePriority = 0.00f;
    this->AmbientOcclusionIntensity = 0.50f;
    this->AmbientOcclusionRadius = 200.00f;
    this->AmbientCubemap = NULL;
    this->AmbientCubemapIntensity = 1.00f;
    this->AmbientOcclusionStaticFraction = 1.00f;
    this->AmbientOcclusionFadeDistance = 8000.00f;
    this->AmbientOcclusionFadeRadius = 5000.00f;
    this->AmbientOcclusionPower = 2.00f;
    this->AmbientOcclusionBias = 3.00f;
    this->AmbientOcclusionQuality = 50.00f;
    this->AmbientOcclusionMipBlend = 0.60f;
    this->AmbientOcclusionMipScale = 1.70f;
    this->AmbientOcclusionMipThreshold = 0.01f;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bUnbounded = false;
    this->bEnabled = true;
    this->AmbientOcclusionRadiusInWS = false;
    this->bOverride_AmbientOcclusionIntensity = false;
    this->bOverride_AmbientOcclusionRadius = false;
    this->bOverride_AmbientCubemapTint = false;
    this->bOverride_AmbientCubemapIntensity = false;
    this->bOverride_AmbientOcclusionStaticFraction = false;
    this->bOverride_AmbientOcclusionFadeDistance = false;
    this->bOverride_AmbientOcclusionFadeRadius = false;
    this->bOverride_AmbientOcclusionRadiusInWS = false;
    this->bOverride_AmbientOcclusionPower = false;
    this->bOverride_AmbientOcclusionBias = false;
    this->bOverride_AmbientOcclusionQuality = false;
    this->bOverride_AmbientOcclusionMipBlend = false;
    this->bOverride_AmbientOcclusionMipScale = false;
    this->bOverride_AmbientOcclusionMipThreshold = false;
    this->GTAOBlendable = NULL;
}

