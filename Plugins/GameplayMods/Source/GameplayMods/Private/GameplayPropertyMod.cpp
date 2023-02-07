#include "GameplayPropertyMod.h"




UGameplayPropertyMod::UGameplayPropertyMod() {
    this->bEvaluateInputOnAddOnly = false;
    this->ExternalInputSource = EModExternalInputMethod::CallExternalInputFunction;
    this->LifeTime = -1.00f;
    this->bApplyOnceOnly = false;
    this->bDelayedRemoveAfterUse = false;
    this->bStackable = true;
}

