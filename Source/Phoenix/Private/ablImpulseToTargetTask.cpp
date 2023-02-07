#include "ablImpulseToTargetTask.h"

UablImpulseToTargetTask::UablImpulseToTargetTask() {
    this->DistFromTarget = 100.00f;
    this->MaxTravelDist = 300.00f;
    this->bAllowNegative = true;
    this->bAllowPositive = true;
    this->bStopOnTargetHit = true;
    this->bAddCapsuleRadiusToDistanceFromTarget = false;
    this->CapsuleRadiusMultiplier = 1.00f;
    this->bAddTargetCapsuleRadiusToDistanceFromTarget = false;
    this->bOnlyTowardsAvatar = false;
    this->bApplyCurrentHeightAsOffset = false;
    this->bApplyCustomOffset = false;
    this->bUseForImpact = true;
    this->bTrackTarget = true;
    this->bTrackLateral = false;
    this->TrackTargetMinDist = 20.00f;
    this->TrackTargetMaxDist = 300.00f;
    this->bUseMaxHeadingFromFwd = false;
    this->MaxHeadingFromFwd = 45.00f;
}

