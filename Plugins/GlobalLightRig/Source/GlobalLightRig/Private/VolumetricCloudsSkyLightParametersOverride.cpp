#include "VolumetricCloudsSkyLightParametersOverride.h"

FVolumetricCloudsSkyLightParametersOverride::FVolumetricCloudsSkyLightParametersOverride() {
    this->bOverride_CloudOutput = false;
    this->bOverride_CloudAlpha = false;
    this->bOverride_Desaturate = false;
    this->bOverride_GroundColor = false;
    this->CloudOutput = 0.00f;
    this->CloudAlpha = 0.00f;
    this->Desaturate = 0.00f;
}

