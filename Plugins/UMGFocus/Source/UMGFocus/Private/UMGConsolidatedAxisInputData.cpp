#include "UMGConsolidatedAxisInputData.h"

FUMGConsolidatedAxisInputData::FUMGConsolidatedAxisInputData() {
    this->bAnyAxisInputSinceLastTick = false;
    this->LeftTriggerAxisValue = 0.00f;
    this->RightTriggerAxisValue = 0.00f;
    this->MouseWheelAxisValue = 0.00f;
}

