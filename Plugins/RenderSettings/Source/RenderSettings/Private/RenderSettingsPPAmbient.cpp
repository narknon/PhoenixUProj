#include "RenderSettingsPPAmbient.h"

FRenderSettingsPPAmbient::FRenderSettingsPPAmbient() {
    this->bOverride_AmbientOcclusionIntensity = false;
    this->bOverride_AmbientOcclusionRadius = false;
    this->bOverride_AmbientCubemapTint = false;
    this->bOverride_AmbientCubemapIntensity = false;
    this->AmbientOcclusionIntensity = 0.00f;
    this->AmbientOcclusionRadius = 0.00f;
    this->AmbientCubemap = NULL;
    this->AmbientCubemapIntensity = 0.00f;
}

