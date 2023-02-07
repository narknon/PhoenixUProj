#include "RootMotionModProperties_Interact.h"

URootMotionModProperties_Interact::URootMotionModProperties_Interact() {
    this->TurnToFaceRule = EInteractTurnToFaceRules::None;
    this->UseTargetAxisForFacing = EInteractUseTargetAxis::NegXAxis;
    this->RotateInterpType = ECustomInterpType::None;
    this->RotateInterpSpeed = 1.00f;
    this->RotateInterpTime = 0.20f;
    this->OffsetRule = EInteractOffsetRules::None;
    this->UseTargetAxisForOffset = EInteractUseTargetAxis::XAxis;
    this->MinOffset = 0.00f;
    this->MaxOffset = 0.00f;
    this->OffsetInterpType = ECustomInterpType::None;
    this->OffsetInterpSpeed = 1.00f;
    this->OffsetInterpTime = 0.20f;
}

