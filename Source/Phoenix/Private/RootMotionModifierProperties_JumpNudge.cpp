#include "RootMotionModifierProperties_JumpNudge.h"

URootMotionModifierProperties_JumpNudge::URootMotionModifierProperties_JumpNudge() {
    this->TimeWhenPlayerCanChangeJumpType = 0.20f;
    this->TurnToFaceInterpType = ECustomInterpType::EaseIn;
    this->TurnToFaceInterpSpeed = 0.10f;
    this->DeadZoneCurve = NULL;
    this->StrafeInterpType = ECustomInterpType::EaseIn;
    this->StrafeInterpSpeed = 0.10f;
    this->StrafeRotationInterpType = ECustomInterpType::Constant;
    this->StrafeRotationInterpSpeed = 0.00f;
    this->StrafeTranslationInterpType = ECustomInterpType::EaseIn;
    this->StrafeTranslationInterpSpeed = 0.10f;
    this->ShortJumpRotationInterpType = ECustomInterpType::EaseIn;
    this->ShortJumpRotationInterpSpeed = 0.50f;
    this->LongJumpRotationInterpType = ECustomInterpType::EaseIn;
    this->LongJumpRotationInterpSpeed = 0.50f;
    this->LongJumpMinStickPercentage = 80.00f;
    this->LongJumpPullBackOnStickPercentage = 70.00f;
    this->SprintJumpRotationInterpType = ECustomInterpType::EaseIn;
    this->SprintJumpRotationInterpSpeed = 0.50f;
    this->SprintJumpMinStickPercentage = 80.00f;
    this->SprintJumpPullBackOnStickPercentage = 70.00f;
}

