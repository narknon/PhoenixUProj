#include "SeasonFXOverrideVolume.h"

ASeasonFXOverrideVolume::ASeasonFXOverrideVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SeasonOverride = ESeasonEnum::Season_Invalid;
    this->PhaseOverride = 0;
}

