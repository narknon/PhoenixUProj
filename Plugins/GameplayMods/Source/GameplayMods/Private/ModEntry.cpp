#include "ModEntry.h"

FModEntry::FModEntry() {
    this->Modifier = NULL;
    this->InputValueProvider = NULL;
    this->OwnerModComponent = NULL;
    this->CurrentLifeTime = 0.00f;
    this->bRemove = false;
}

