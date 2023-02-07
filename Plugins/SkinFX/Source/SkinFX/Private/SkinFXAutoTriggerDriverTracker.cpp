#include "SkinFXAutoTriggerDriverTracker.h"

FSkinFXAutoTriggerDriverTracker::FSkinFXAutoTriggerDriverTracker() {
    this->Driver = NULL;
    this->Priority = 0.00f;
    this->NiagaraComponent = NULL;
    this->bSignalledActive = false;
    this->bSignalledInactive = false;
}

