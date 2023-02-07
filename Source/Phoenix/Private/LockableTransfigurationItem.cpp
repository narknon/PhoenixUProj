#include "LockableTransfigurationItem.h"

FLockableTransfigurationItem::FLockableTransfigurationItem() {
    this->bIsUnlocked = false;
    this->bHasTransformationOptions = false;
    this->bHasColorOptions = false;
    this->SortingIndex = 0;
    this->bIsPrefab = false;
}

