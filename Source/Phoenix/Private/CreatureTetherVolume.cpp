#include "CreatureTetherVolume.h"

ACreatureTetherVolume::ACreatureTetherVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsActive = true;
    this->bCanBeAutoDetected = true;
}

