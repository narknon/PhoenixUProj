#include "AblNpcMoveInDirectionTask.h"

UAblNpcMoveInDirectionTask::UAblNpcMoveInDirectionTask() {
    this->DirectionType = ENpcMoveDirectionType::Local;
    this->MinSpeed = 100.00f;
    this->MaxSpeed = 100.00f;
    this->RandAngleCone = 0.00f;
    this->MovementMode = MOVE_Falling;
    this->bModifyGravityAtTaskStart = false;
    this->GravityScaleAtTaskStart = 1.00f;
    this->bRestoreGravityScaleAtTaskEnd = true;
    this->bAddMomentumAtTaskEnd = true;
    this->bIgnoreZ = false;
    this->bUseNpcMaxHeight = false;
    this->bOverrideMaxHeight = false;
    this->MaxHeightOverride = 100.00f;
    this->bUseCurveSpeedManipulation = false;
    this->bLoopCurve = false;
    this->bRandStartTimeOnCurve = false;
    this->bUseCurveValueAsMultiplier = false;
    this->bFitCurveToTaskDuration = false;
}

