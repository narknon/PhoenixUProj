#include "SkyLightHemisphereParameters.h"

FSkyLightHemisphereParameters::FSkyLightHemisphereParameters() {
    this->bUseHemisphereLight = false;
    this->HemiOutsideIntensity = 0.00f;
    this->HemiInsideIntensity = 0.00f;
    this->ProbeOutsideMinimumIntensity = 0.00f;
    this->ProbeInsideMinimumIntensity = 0.00f;
    this->SkyOcclusionContrast = 0.00f;
    this->SkyOcclusionExponent = 0.00f;
}

