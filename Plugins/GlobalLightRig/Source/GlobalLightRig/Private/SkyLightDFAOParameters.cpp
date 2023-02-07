#include "SkyLightDFAOParameters.h"

FSkyLightDFAOParameters::FSkyLightDFAOParameters() {
    this->OcclusionMaxDistance = 0.00f;
    this->Contrast = 0.00f;
    this->OcclusionExponent = 0.00f;
    this->MinOcclusion = 0.00f;
    this->OcclusionCombineMode = OCM_Minimum;
}

