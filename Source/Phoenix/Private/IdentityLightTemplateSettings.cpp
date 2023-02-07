#include "IdentityLightTemplateSettings.h"

FIdentityLightTemplateSettings::FIdentityLightTemplateSettings() {
    this->bOverride_Intensity = false;
    this->bOverride_Color = false;
    this->bOverride_Temperature = false;
    this->bOverride_AttenuationRadius = false;
    this->bOverride_IndirectLightingIntensity = false;
    this->bOverride_VolumetricScatteringIntensity = false;
    this->Intensity = 0.00f;
    this->LightTemperature = 0.00f;
    this->AttenuationRadius = 0.00f;
    this->IndirectLightingIntensity = 0.00f;
    this->VolumetricScatteringIntensity = 0.00f;
}

