#include "PerSeasonFXOverrideVolume.h"

APerSeasonFXOverrideVolume::APerSeasonFXOverrideVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FallOverride = ESeasonEnum::Season_Invalid;
    this->FallPhaseOverride = 0;
    this->WinterOverride = ESeasonEnum::Season_Invalid;
    this->WinterPhaseOverride = 0;
    this->SpringOverride = ESeasonEnum::Season_Invalid;
    this->SpringPhaseOverride = 0;
    this->SummerOverride = ESeasonEnum::Season_Invalid;
    this->SummerPhaseOverride = 0;
}

