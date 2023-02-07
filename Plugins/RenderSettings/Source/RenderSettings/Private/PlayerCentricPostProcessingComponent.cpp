#include "PlayerCentricPostProcessingComponent.h"

UPlayerCentricPostProcessingComponent::UPlayerCentricPostProcessingComponent() {
    this->PlayerEyeDistanceSameThreshold = 20.00f;
    this->bIncludeBlendables = false;
    this->Priority = 0.00f;
    this->bInVolumeList = false;
}

