#include "PostProcessingVarsComponentBase.h"

void UPostProcessingVarsComponentBase::SetPriority(float NewPriority) {
}

UPostProcessingVarsComponentBase::UPostProcessingVarsComponentBase() {
    this->Driver = NULL;
    this->DriverValue = 0.00f;
    this->Priority = 1.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbounded = false;
    this->bDriverValueValid = false;
}

