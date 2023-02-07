#include "ExpHeightFogInscatteringTextureParameters.h"

FExpHeightFogInscatteringTextureParameters::FExpHeightFogInscatteringTextureParameters() {
    this->InscatteringColorCubemap = NULL;
    this->InscatteringColorCubemapAngle = 0.00f;
    this->FullyDirectionalInscatteringColorDistance = 0.00f;
    this->NonDirectionalInscatteringColorDistance = 0.00f;
    this->bUseSkyLight = false;
    this->InscatteringColorCubemapFactor = 0.00f;
}

