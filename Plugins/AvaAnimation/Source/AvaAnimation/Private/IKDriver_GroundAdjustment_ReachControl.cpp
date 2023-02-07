#include "IKDriver_GroundAdjustment_ReachControl.h"

FIKDriver_GroundAdjustment_ReachControl::FIKDriver_GroundAdjustment_ReachControl() {
    this->InterpSpeed = 0.00f;
    this->InterpDampingFactor = 0.00f;
    this->FilteringSpeed = 0.00f;
    this->FilteringDampingFactor = 0.00f;
    this->LowestOrAverage = 0.00f;
    this->MaxControlAdjustment = 0.00f;
}

