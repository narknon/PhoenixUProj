#include "GroundSwarmingTargetTracker.h"

FGroundSwarmingTargetTracker::FGroundSwarmingTargetTracker() {
    this->Target = NULL;
    this->Hits = 0;
    this->ThresholdMetDelayTimer = 0.00f;
    this->bSignalledThresholdResult = false;
}

