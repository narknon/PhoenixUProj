#include "RootMotionModifierProperties_FacingAssist.h"

URootMotionModifierProperties_FacingAssist::URootMotionModifierProperties_FacingAssist() {
    this->UseDirection = ERootMotionModTurnAssistUseDirection::FacingTarget_OR_DesiredDirection;
    this->bFaceNegativeDirectionIfCloser = false;
    this->bIgnoreTargetTracker = false;
    this->bAllowDesiredDirectionUpdates = false;
    this->bRotateRootTranslationIntoDesiredDirection = true;
    this->InterpType = ECustomInterpType::None;
    this->InterpSpeed = 0.00f;
    this->InterpTime = 0.50f;
    this->bDebug = false;
}

