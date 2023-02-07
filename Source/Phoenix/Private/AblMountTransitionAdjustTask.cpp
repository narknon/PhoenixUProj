#include "AblMountTransitionAdjustTask.h"

UAblMountTransitionAdjustTask::UAblMountTransitionAdjustTask() {
    this->CreatureMountSocketName = TEXT("MountTransitionSocket");
    this->CreatureTransitionBoneName = TEXT("attachment_mount_01");
    this->CreatureAttachSocketName = TEXT("MountSocket");
    this->AttachBlendTime = 0.20f;
    this->MaxInterpolateFactor = 100.00f;
    this->bDrawDebug = false;
}

