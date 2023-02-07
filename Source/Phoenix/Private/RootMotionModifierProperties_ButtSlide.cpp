#include "RootMotionModifierProperties_ButtSlide.h"

URootMotionModifierProperties_ButtSlide::URootMotionModifierProperties_ButtSlide() {
    this->DownwardForce = 980.00f;
    this->Friction = 0.01f;
    this->RotationInterpType = ECustomInterpType::EaseInOut;
    this->RotationInterpSpeed = 0.90f;
}

