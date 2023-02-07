#include "AblNPC_PhysicsBallisticToTargetTask.h"

UAblNPC_PhysicsBallisticToTargetTask::UAblNPC_PhysicsBallisticToTargetTask() {
    this->Type = ENPC_PhysicsBallisticType::Target;
    this->bUseTarget = true;
    this->Mode = ENPC_PhysicsBallisticToTargetTaskMode::StartAndUpdate;
    this->EndMode = ENPC_PhysicsBallisticToTargetTaskMode::Update;
    this->bBallisticFromAttackData = false;
    this->OverrideGravity = 0.00f;
    this->bTrackTarget = false;
    this->ArcParam = 0.50f;
    this->TimeMult = 1.00f;
    this->TargetVelocityPredictionTime = 0.50f;
    this->MaxDistance = -1.00f;
    this->bIgnoreCollisionUntilApex = false;
    this->bIgnoreNonStatic = true;
    this->bCollateralDamage = true;
    this->fRandomAngleDeviationMin = 0.00f;
    this->fRandomAngleDeviationMax = 0.00f;
    this->fRandomDistanceDeviationMin = 0.00f;
    this->fRandomDistanceDeviationMax = 0.00f;
    this->PhysicsOnGroundMinTime = 1.00f;
    this->PhysicsOnGroundTimeout = 15.00f;
    this->PhysicsMinTime = 3.00f;
    this->PhysicsTimeout = 60.00f;
    this->MovementStopTolerance = 0.10f;
    this->bDisableCollisionResolution = false;
}

