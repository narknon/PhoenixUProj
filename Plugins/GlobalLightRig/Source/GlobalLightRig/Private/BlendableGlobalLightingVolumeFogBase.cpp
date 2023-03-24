#include "BlendableGlobalLightingVolumeFogBase.h"
#include "GlobalLightingBlendableExpHeightFogVolume.h"

ABlendableGlobalLightingVolumeFogBase::ABlendableGlobalLightingVolumeFogBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FogZMode = EGlobalLightingFogZMode::BaseOfVolume;
    this->Transmuter = NULL;
    this->Priority = 1.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bUnbounded = false;
    this->bEnabled = true;
    this->GlobalLightingBlendable = CreateDefaultSubobject<UGlobalLightingBlendableExpHeightFogVolume>(TEXT("FogBlendable"));
}

