#include "RenderSettingsPPAmbientOcclusionAdvanced.h"

FRenderSettingsPPAmbientOcclusionAdvanced::FRenderSettingsPPAmbientOcclusionAdvanced() {
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
    this->AmbientOcclusionStaticFraction = 0.00f;
    this->AmbientOcclusionRadiusInWS = false;
    this->AmbientOcclusionFadeDistance = 0.00f;
    this->AmbientOcclusionFadeRadius = 0.00f;
    this->AmbientOcclusionPower = 0.00f;
    this->AmbientOcclusionBias = 0.00f;
    this->AmbientOcclusionQuality = 0.00f;
    this->AmbientOcclusionMipBlend = 0.00f;
    this->AmbientOcclusionMipScale = 0.00f;
    this->AmbientOcclusionMipThreshold = 0.00f;
}

