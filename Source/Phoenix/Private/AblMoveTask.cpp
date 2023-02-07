#include "AblMoveTask.h"

UAblMoveTask::UAblMoveTask() {
    this->VelocitySource = EAblMoveTaskVelocitySource::Stratchpad;
    this->DestSource = EAblMoveTaskBallisticDestinationSource::ToLoc;
    this->bApplyGravity = true;
    this->OverrideGravity = 0.00f;
    this->ArcParamMin = 0.50f;
    this->ArcParamMax = 0.50f;
    this->TimeMult = 1.00f;
    this->Distance = 0.00f;
    this->MaxDistance = -1.00f;
    this->bIgnoreNonStatic = true;
    this->bCollateralDamage = true;
}

