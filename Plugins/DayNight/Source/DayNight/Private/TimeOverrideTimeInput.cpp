#include "TimeOverrideTimeInput.h"

UTimeOverrideTimeInput::UTimeOverrideTimeInput() {
    this->Type = ETimeOverrideType::NormalizedTime;
    this->Priority = 0.00f;
    this->bEnabled = true;
}

