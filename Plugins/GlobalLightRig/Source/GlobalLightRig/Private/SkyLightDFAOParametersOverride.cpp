#include "SkyLightDFAOParametersOverride.h"

FSkyLightDFAOParametersOverride::FSkyLightDFAOParametersOverride() {
    this->bOverride_OcclusionMaxDistance = false;
    this->bOverride_Contrast = false;
    this->bOverride_OcclusionExponent = false;
    this->bOverride_MinOcclusion = false;
    this->bOverride_OcclusionTint = false;
    this->bOverride_OcclusionCombineMode = false;
    this->OcclusionMaxDistance = 0.00f;
    this->Contrast = 0.00f;
    this->OcclusionExponent = 0.00f;
    this->MinOcclusion = 0.00f;
    this->OcclusionCombineMode = OCM_Minimum;
}

