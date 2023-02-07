#include "Actor_CreatureReleasedFromInventory.h"

UActor_CreatureReleasedFromInventory::UActor_CreatureReleasedFromInventory() {
    this->bGetSavedCreature = false;
    this->bUseExistingDOV = false;
    this->ExistingDOV = NULL;
}

