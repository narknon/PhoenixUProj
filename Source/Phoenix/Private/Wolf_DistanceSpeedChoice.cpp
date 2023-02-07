#include "Wolf_DistanceSpeedChoice.h"

UWolf_DistanceSpeedChoice::UWolf_DistanceSpeedChoice() {
    this->DistanceFromTargetTrotThreshold = 1400.00f;
    this->DistanceFromPathGoalTrotThreshold = 1400.00f;
    this->DistanceFromPathGoalToTargetTrotThreshold = 1000.00f;
    this->UpdateTimeDelta = 2.00f;
    this->UpdateTimeDeltaRandomNudge = 1.00f;
}

