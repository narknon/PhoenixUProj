#include "ablTurnAssistTask.h"

UablTurnAssistTask::UablTurnAssistTask() {
    this->UseDirection = ETurnAssistUseDirection::FacingTarget_OR_DesiredDirection;
    this->bUseFixedDirection = false;
    this->FixedDeltaTurnAssistCurve = NULL;
    this->TurnAssistCurve = NULL;
    this->TurnAssistTimeMultiplier = NULL;
    this->bScaleRotationBasedOnSpeed = false;
    this->MinRotationScaleBasedOnSpeed = 0.25f;
    this->StrafeTurnAssistCurve = NULL;
    this->StrafeTurnAssistTimeMultiplier = NULL;
    this->bIgnoreTargetTracker = false;
}

