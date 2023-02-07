#include "BlendableGlobalLightingVolumeFogDefaultsBase.h"

UBlendableGlobalLightingVolumeFogDefaultsBase::UBlendableGlobalLightingVolumeFogDefaultsBase() {
    this->FogZMode = EGlobalLightingFogZMode::BaseOfVolume;
    this->Transmuter = NULL;
    this->Priority = 1.00f;
    this->BlendRadius = 100.00f;
}

