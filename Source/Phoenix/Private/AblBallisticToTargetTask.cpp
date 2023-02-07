#include "AblBallisticToTargetTask.h"

UAblBallisticToTargetTask::UAblBallisticToTargetTask() {
    this->Speed = 200.00f;
    this->OverrideGravity = 0.00f;
    this->ArcParam = 0.50f;
    this->TimeMult = 1.00f;
    this->MaxDistance = -1.00f;
    this->bBounce = true;
    this->bIgnoreNonStatic = true;
    this->bCollateralDamage = true;
    this->fRandomAngleDeviationMin = 0.00f;
    this->fRandomAngleDeviationMax = 0.00f;
    this->fRandomDistanceDeviationMin = 0.00f;
    this->fRandomDistanceDeviationMax = 0.00f;
}

