#include "AblObjectStateDropLootTask.h"

UAblObjectStateDropLootTask::UAblObjectStateDropLootTask() {
    this->bSpawnOnFloor = false;
    this->bApplyImpulse = false;
    this->ImpulseDirectionRandAngle = 0.00f;
    this->MinImpulse = 0.00f;
    this->MaxImpulse = 0.00f;
}

