#include "SimpleUpdatePumpComponent.h"

USimpleUpdatePumpComponent::USimpleUpdatePumpComponent() {
    this->SimpleUpdatePumpMode = ESimpleUpdatePumpComponentMode::UPM_EDITORONLY;
    this->bSuspend = false;
}

