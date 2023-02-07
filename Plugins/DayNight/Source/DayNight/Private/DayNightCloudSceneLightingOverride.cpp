#include "DayNightCloudSceneLightingOverride.h"

FDayNightCloudSceneLightingOverride::FDayNightCloudSceneLightingOverride() {
    this->LightDirection = EDayNightCloudSceneLightingSource::DirectionalLight;
    this->LightColor = EDayNightCloudSceneLightingSource::DirectionalLight;
    this->LightIntensity = EDayNightCloudSceneLightingSource::DirectionalLight;
    this->Saturation = 0.00f;
    this->ManualLightIntensity = 0.00f;
    this->bOverride_LightDirection = false;
    this->bOverride_LightColor = false;
    this->bOverride_LightIntensity = false;
    this->bOverride_Saturation = false;
}

