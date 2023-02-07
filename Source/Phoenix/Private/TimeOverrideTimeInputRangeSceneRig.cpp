#include "TimeOverrideTimeInputRangeSceneRig.h"

UTimeOverrideTimeInputRangeSceneRig::UTimeOverrideTimeInputRangeSceneRig() {
    this->Type = ETimeOverrideType::NormalizedTime;
    this->Priority = 0.00f;
    this->bUseEndTime = false;
}

