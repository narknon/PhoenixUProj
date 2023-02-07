#include "OverlapEffectsVelocityTracker.h"

FOverlapEffectsVelocityTracker::FOverlapEffectsVelocityTracker() {
    this->Speed = 0.00f;
    this->AngularVelocity = 0.00f;
    this->LastDistanceMoved = 0.00f;
    this->bInitialized = false;
}

