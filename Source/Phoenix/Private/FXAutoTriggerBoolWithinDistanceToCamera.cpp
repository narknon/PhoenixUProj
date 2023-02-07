#include "FXAutoTriggerBoolWithinDistanceToCamera.h"

void UFXAutoTriggerBoolWithinDistanceToCamera::SetMaxCameraDistanceMeters(float MaxCameraDistanceMeters) const {
}

UFXAutoTriggerBoolWithinDistanceToCamera::UFXAutoTriggerBoolWithinDistanceToCamera() {
    this->DistanceInMeters = 5.00f;
    this->bInFrontOnly = false;
    this->MaxCameraDistanceSquared = 250000.00f;
}

