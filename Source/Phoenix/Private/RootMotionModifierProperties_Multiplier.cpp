#include "RootMotionModifierProperties_Multiplier.h"

URootMotionModifierProperties_Multiplier::URootMotionModifierProperties_Multiplier() {
    this->MultiplyType = EMultiplierType::MultiplyByAxis;
    this->XAxis_Multiplier = 1.00f;
    this->YAxis_Multiplier = 1.00f;
    this->ZAxis_Multiplier = 1.00f;
    this->Multiplier = 1.00f;
}

