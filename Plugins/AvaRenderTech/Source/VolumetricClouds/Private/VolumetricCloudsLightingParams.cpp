#include "VolumetricCloudsLightingParams.h"

FVolumetricCloudsLightingParams::FVolumetricCloudsLightingParams() {
    this->Ambient = 0.00f;
    this->Light = 0.00f;
    this->Extinction = 0.00f;
    this->PowderExtinction = 0.00f;
    this->PowderStrength = 0.00f;
    this->FinalOutput = 0.00f;
    this->SkyLightCloudsOutput = 0.00f;
    this->SkyLightCloudsAlpha = 0.00f;
    this->SkyLightDesaturate = 0.00f;
    this->ShadowScale = 0.00f;
    this->ShadowMapCloudShadowDensity = 0.00f;
    this->RayMarchCloudShadowScale = 0.00f;
    this->RayMarchShadowDensity = 0.00f;
    this->SkyLightShadowDensity = 0.00f;
    this->FogDensityMultiplier = 0.00f;
    this->HeightFogDensityMultiplier = 0.00f;
    this->LightIntensity = 0.00f;
    this->LightSaturation = 0.00f;
}

