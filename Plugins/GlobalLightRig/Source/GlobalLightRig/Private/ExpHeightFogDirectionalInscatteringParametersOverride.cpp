#include "ExpHeightFogDirectionalInscatteringParametersOverride.h"

FExpHeightFogDirectionalInscatteringParametersOverride::FExpHeightFogDirectionalInscatteringParametersOverride() {
    this->bOverride_DirectionalInscatteringExponent = false;
    this->bOverride_DirectionalInscatteringStartDistance = false;
    this->bOverride_DirectionalInscatteringColor = false;
    this->bOverride_DirectionalInscatteringIntensity = false;
    this->bOverride_DirectionalInscatteringSaturation = false;
    this->bOverride_DirectionalInscatteringColorDirLightLuminanceModulate = false;
    this->DirectionalInscatteringExponent = 0.00f;
    this->DirectionalInscatteringStartDistance = 0.00f;
    this->DirectionalInscatteringIntensity = 0.00f;
    this->DirectionalInscatteringSaturation = 0.00f;
    this->DirectionalInscatteringColorDirLightLuminanceModulate = 0.00f;
}

