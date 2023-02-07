#include "RootMotionModifierProperties_DodgeRoll.h"

URootMotionModifierProperties_DodgeRoll::URootMotionModifierProperties_DodgeRoll() {
    this->bShadowBlink = false;
    this->bShadowBlinkWithTarget = false;
    this->TurnToFaceInterpType = ECustomInterpType::EaseIn;
    this->TurnToFaceInterpSpeed = 0.10f;
    this->TurnToFaceInterpTime = 0.50f;
    this->RotationInterpType = ECustomInterpType::Constant;
    this->RotationInterpSpeed = 0.00f;
    this->RotationInterpTime = 0.50f;
    this->TranslationMultiplier = 1.00f;
    this->TranslationMultiplierCurve = NULL;
    this->BlinkSpeed = 1.00f;
}

