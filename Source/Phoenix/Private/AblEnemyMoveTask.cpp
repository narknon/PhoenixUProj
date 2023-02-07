#include "AblEnemyMoveTask.h"

UAblEnemyMoveTask::UAblEnemyMoveTask() {
    this->m_Target = Self;
    this->VelocitySource = External;
    this->CustomSpeed = 0.00f;
    this->ZDirectionOffset = 0.00f;
    this->bRestoreMovementMode = true;
    this->bApplyGravity = true;
    this->GravityMultiplier = 1.00f;
    this->MaxDownwardVelocityDueToGravity = 5300.00f;
    this->bOverrideJumpArc = false;
    this->OverrideJumpArc = 0.50f;
    this->bForceApplyingGravityForJumps = true;
    this->bDebugDrawJump = false;
    this->SlideSpeed = 500.00f;
    this->SlideTargetTolerance = 100.00f;
    this->ZeroVelocityTolerance = 0.00f;
    this->bApplyVelocityTowardsInstigator = false;
    this->NoMovementOccuredTolerance = 0.00f;
    this->AcceptanceDistance = 50.00f;
    this->bDiminishVelocity = false;
    this->TimeToStop = 1.00f;
    this->DegreeOfEaseOutCurve = 2.00f;
    this->bCanVaryTowardsInstigator = false;
    this->VaryingCurve = NULL;
    this->MinimumDistance = 100.00f;
    this->bDiminishVelocityDueToGravity = false;
    this->OnGroundDetectionDistance = 20.00f;
    this->bIgnoreAllFloorHits = false;
    this->bSlideAcrossGroundInitially = false;
    this->bSlideAcrossGroundAlways = false;
    this->bLockZPosition = false;
    this->bCutOffMovement = false;
    this->CutoffDistance = 0.00f;
}

