#include "AblReactionsCapsuleScalingTask.h"

UAblReactionsCapsuleScalingTask::UAblReactionsCapsuleScalingTask() {
    this->bUseHeightAsRadius = false;
    this->RadiusMultiplier = 1.00f;
    this->HalfHeightMultiplier = 1.00f;
    this->bRestoreAtEndTask = false;
}

