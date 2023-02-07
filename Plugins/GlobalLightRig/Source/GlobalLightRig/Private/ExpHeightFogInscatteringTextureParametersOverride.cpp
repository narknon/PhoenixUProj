#include "ExpHeightFogInscatteringTextureParametersOverride.h"

FExpHeightFogInscatteringTextureParametersOverride::FExpHeightFogInscatteringTextureParametersOverride() {
    this->bOverride_InscatteringColorCubemap = false;
    this->bOverride_InscatteringColorCubemapAngle = false;
    this->bOverride_InscatteringTextureTint = false;
    this->bOverride_FullyDirectionalInscatteringColorDistance = false;
    this->bOverride_NonDirectionalInscatteringColorDistance = false;
    this->bOverride_bUseSkyLight = false;
    this->bOverride_InscatteringColorCubemapFactor = false;
    this->InscatteringColorCubemap = NULL;
    this->InscatteringColorCubemapAngle = 0.00f;
    this->FullyDirectionalInscatteringColorDistance = 0.00f;
    this->NonDirectionalInscatteringColorDistance = 0.00f;
    this->bUseSkyLight = false;
    this->InscatteringColorCubemapFactor = 0.00f;
}

