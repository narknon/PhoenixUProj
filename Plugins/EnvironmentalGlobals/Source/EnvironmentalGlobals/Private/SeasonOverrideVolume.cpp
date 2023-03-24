#include "SeasonOverrideVolume.h"

void ASeasonOverrideVolume::SetPriority(float NewPriority) {
}

ASeasonOverrideVolume::ASeasonOverrideVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Priority = 0.00f;
    this->bEnabled = true;
}

