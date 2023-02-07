#include "MasterOverlapThrottlerSettings.h"

FMasterOverlapThrottlerSettings::FMasterOverlapThrottlerSettings() {
    this->NoOverlapEventsRadiusMeters = 0.00f;
    this->bManageOverlapsEnabled = false;
    this->bManageCollisionEnabled = false;
    this->bPhysicsCollisionsEnabled = false;
}

