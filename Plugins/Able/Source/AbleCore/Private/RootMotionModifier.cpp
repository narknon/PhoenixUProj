#include "RootMotionModifier.h"

URootMotionModifier::URootMotionModifier() {
    this->RootMotionModifierProperties = NULL;
    this->Instigator = NULL;
    this->RootMotionModifierOrder = ERootMotionModifierOrder::Primary;
    this->Duration = 0.00f;
}

