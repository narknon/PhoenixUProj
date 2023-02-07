#include "ablMotionAdjustTask.h"

UablMotionAdjustTask::UablMotionAdjustTask() {
    this->TargetLocationGetter = NULL;
    this->bTrackTarget = true;
    this->bUseRootMotionForPrediction = true;
    this->bIgnoreMeshScale = false;
    this->InterceptTime = 0.00f;
    this->bLimitMaxImpulse = false;
    this->MaxImpulse = 5000.00f;
    this->AdjustCurve = EAlphaBlendOption::Linear;
    this->bCanAdjustZAxis = false;
    this->bGuaranteeOnTargetAtTaskEnd = false;
    this->TaskEndMovementMode = MOVE_None;
    this->bDebugDrawEnabled = false;
    this->bDebugDrawTranslationCorrection = false;
    this->bDebugDrawTarget = false;
    this->bDebugDrawRootMotion = false;
    this->bDebugDrawTransform = false;
}

