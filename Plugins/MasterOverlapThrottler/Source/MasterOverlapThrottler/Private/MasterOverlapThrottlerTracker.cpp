#include "MasterOverlapThrottlerTracker.h"

FMasterOverlapThrottlerTracker::FMasterOverlapThrottlerTracker() {
    this->bDisableThrottling = false;
    this->OriginalCollisionType = ECollisionEnabled::NoCollision;
}

