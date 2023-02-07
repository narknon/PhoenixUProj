#include "SkyLightHemisphereParametersOverride.h"

FSkyLightHemisphereParametersOverride::FSkyLightHemisphereParametersOverride() {
    this->bOverride_bUseHemisphereLight = false;
    this->bOverride_HemiTopColor = false;
    this->bOverride_HemiBottomColor = false;
    this->bOverride_HemiOutsideIntensity = false;
    this->bOverride_HemiInsideIntensity = false;
    this->bOverride_ProbeOutsideMinimumIntensity = false;
    this->bOverride_ProbeInsideMinimumIntensity = false;
    this->bOverride_SkyOcclusionContrast = false;
    this->bOverride_SkyOcclusionExponent = false;
    this->bUseHemisphereLight = false;
    this->HemiOutsideIntensity = 0.00f;
    this->HemiInsideIntensity = 0.00f;
    this->ProbeOutsideMinimumIntensity = 0.00f;
    this->ProbeInsideMinimumIntensity = 0.00f;
    this->SkyOcclusionContrast = 0.00f;
    this->SkyOcclusionExponent = 0.00f;
}

