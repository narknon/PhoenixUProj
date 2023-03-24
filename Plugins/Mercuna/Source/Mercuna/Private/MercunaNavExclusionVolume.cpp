#include "MercunaNavExclusionVolume.h"

AMercunaNavExclusionVolume::AMercunaNavExclusionVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bApplyToAllNavOctrees = true;
}

