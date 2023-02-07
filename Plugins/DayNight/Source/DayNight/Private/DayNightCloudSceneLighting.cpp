#include "DayNightCloudSceneLighting.h"

FDayNightCloudSceneLighting::FDayNightCloudSceneLighting() {
    this->LightDirection = EDayNightCloudSceneLightingSource::DirectionalLight;
    this->LightColor = EDayNightCloudSceneLightingSource::DirectionalLight;
    this->LightIntensity = EDayNightCloudSceneLightingSource::DirectionalLight;
    this->Saturation = 0.00f;
    this->ManualLightIntensity = 0.00f;
}

