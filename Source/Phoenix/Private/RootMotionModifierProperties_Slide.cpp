#include "RootMotionModifierProperties_Slide.h"

URootMotionModifierProperties_Slide::URootMotionModifierProperties_Slide() {
    this->DesiredSlopeSpeed = 1.00f;
    this->SlopeVelocityInterpType = ECustomInterpType::EaseIn;
    this->SlopeVelocityInterpSpeed = 1.00f;
    this->ToFlatGroundInterpType = ECustomInterpType::EaseIn;
    this->ToFlatGroundInterpSpeed = 1.00f;
}

