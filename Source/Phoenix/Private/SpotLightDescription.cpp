#include "SpotLightDescription.h"

FSpotLightDescription::FSpotLightDescription() {
    this->InnerConeAngle = 0.00f;
    this->OuterConeAngle = 0.00f;
    this->bUseInverseSquaredFalloff = false;
    this->LightFalloffExponent = 0.00f;
    this->SourceRadius = 0.00f;
    this->SoftSourceRadius = 0.00f;
    this->SourceLength = 0.00f;
}

