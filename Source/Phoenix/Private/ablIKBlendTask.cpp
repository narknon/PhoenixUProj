#include "ablIKBlendTask.h"

UablIKBlendTask::UablIKBlendTask() {
    this->bDisableAllIK = true;
    this->bDisableFloorContact = false;
    this->bDisableLookAt = false;
    this->bDisablePoseFixup = false;
    this->BlendOutDuration = 0.50f;
    this->BlendInDuration = 0.50f;
    this->LowestAllowedLookAtPriority = EAnimationDirectionSource::Gameplay;
}

