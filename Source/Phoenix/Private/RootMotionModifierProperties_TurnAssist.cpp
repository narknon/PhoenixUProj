#include "RootMotionModifierProperties_TurnAssist.h"

URootMotionModifierProperties_TurnAssist::URootMotionModifierProperties_TurnAssist() {
    this->UseDirection = ERootMotionModTurnAssistUseDirection::FacingTarget_OR_DesiredDirection;
    this->UseMethod = ERootMotionModTurnAssistMethod::UseCurve;
    this->RotationInterpType = ECustomInterpType::EaseInOut;
    this->RegularSpeedRotationInterpSpeed = 0.10f;
    this->bScaleRotationBasedOnSpeed = false;
    this->LowSpeedRotationInterpSpeed = 0.10f;
    this->SpringHalflife = 0.20f;
    this->SpringLowSpeedHalflifeMultiplier = 1.75f;
    this->bAdjustTranslationBasedOnTurn = false;
    this->TranslationAdjustMinMultiplier = 0.70f;
    this->bUseFixedDirection = false;
    this->TurnAssistCurve = NULL;
    this->TurnAssistTimeMultiplier = NULL;
    this->MinRotationScaleBasedOnSpeed = 0.25f;
    this->bIgnoreTargetTracker = false;
    this->bAllowDesiredDirectionUpdates = true;
    this->DesiredDirectionUpdateDuration = -1.00f;
    this->bDebug = false;
    this->SplineRotationInterpType = ECustomInterpType::EaseInOut;
    this->SplineRotationInterpSpeed = 0.10f;
}

