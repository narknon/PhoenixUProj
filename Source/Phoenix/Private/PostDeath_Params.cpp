#include "PostDeath_Params.h"

FPostDeath_Params::FPostDeath_Params() {
    this->CleanUpEffect = EPostDeathCleanupEffect::Dissolve;
    this->CleanUpMode = EPostDeathCleanupMode::TriggerOnMaximumReached;
    this->SortingMode = EPostDeathSortingMode::FirstInFirstOut;
    this->BatchSize = 0;
    this->MaxAllowedDeadNPCs = 0;
    this->MinAllowedDeadNPCs = 0;
    this->TimeBetweenBatches = 0.00f;
    this->TimerModeDelay = 0.00f;
}

