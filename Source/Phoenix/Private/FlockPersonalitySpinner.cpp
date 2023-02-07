#include "FlockPersonalitySpinner.h"

FFlockPersonalitySpinner::FFlockPersonalitySpinner() {
    this->MinWaitTime = 0.00f;
    this->MaxWaitTime = 0.00f;
    this->MinSpinDuration = 0.00f;
    this->MaxSpinDuration = 0.00f;
    this->Axis = EFlockPersonalityAxis::FPA_PITCH;
    this->SpinSpeed = 0.00f;
    this->bInWorld = false;
}

