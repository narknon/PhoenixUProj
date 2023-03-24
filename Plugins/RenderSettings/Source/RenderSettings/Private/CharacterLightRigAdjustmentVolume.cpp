#include "CharacterLightRigAdjustmentVolume.h"

ACharacterLightRigAdjustmentVolume::ACharacterLightRigAdjustmentVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Priority = 0;
    this->bEnabled = true;
    this->InterpolationDistance = 100.00f;
    this->bUnbounded = false;
}

