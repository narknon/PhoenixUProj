#include "AblPhysicalReactionBlendBackTask.h"

UAblPhysicalReactionBlendBackTask::UAblPhysicalReactionBlendBackTask() {
    this->bForcePopOutOfRagdollImmediately = false;
    this->bOverrideBlendDuration = false;
    this->BlendDurationOverride = 0.30f;
    this->bStationaryCapsuleWhileBlending = true;
}

