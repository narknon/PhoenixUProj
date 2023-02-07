#include "GlobalLightingBlendableSkyAtmosphere.h"

UGlobalLightingBlendableSkyAtmosphere::UGlobalLightingBlendableSkyAtmosphere() {
    this->SkyAtmosphereParameters = NULL;
    this->OverrideSource = EGlobalLightingBlendableInputType::CombinedValues;
}

