#include "GameplayProperty.h"

FGameplayProperty::FGameplayProperty() {
    this->OnUpdatedCallback = NULL;
    this->bSkipUpdateOnTick = false;
}

