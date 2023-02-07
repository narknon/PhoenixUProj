#include "AnimationProvider_Conditional.h"

UAnimationProvider_Conditional::UAnimationProvider_Conditional() {
    this->Condition = NULL;
    this->AnimationIfTrue = NULL;
    this->AnimationIfFalse = NULL;
}

