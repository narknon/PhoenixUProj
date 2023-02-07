#include "TimeRigInstanceContext.h"

UTimeRigInstanceContext::UTimeRigInstanceContext() {
    this->TimeRig = NULL;
    this->IsHammerTime = false;
    this->InitializeAsPaused = false;
    this->IsInEditor = false;
    this->EventUpdateToken = 0;
    this->bSkippingEnabled = false;
    this->bInUnskippableSection = false;
    this->bSkipping = false;
}

