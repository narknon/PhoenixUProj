#include "UpdatePumpComponent.h"

UUpdatePumpComponent::UUpdatePumpComponent() {
    this->UpdatePumpMode = EUpdatePumpComponentMode::UPM_EDITORONLY;
    this->bSuspend = false;
}

