#include "CreatureLookAtBehavior.h"

FCreatureLookAtBehavior::FCreatureLookAtBehavior() {
    this->TargetTrackerTargetID = ETargetID::None;
    this->TargetEvaluationMaxLOD = 0;
    this->TargetEvaluationConfig = NULL;
    this->LookAroundMinTime = 0.00f;
    this->LookAroundMaxTime = 0.00f;
    this->LookAroundMaxPitchUp = 0.00f;
    this->LookAroundMaxPitchDown = 0.00f;
    this->LookAroundMinYaw = 0.00f;
    this->LookAroundMaxYaw = 0.00f;
    this->LookAroundMinDistance = 0.00f;
    this->LookAroundMaxDistance = 0.00f;
    this->OwnerCreature = NULL;
}

