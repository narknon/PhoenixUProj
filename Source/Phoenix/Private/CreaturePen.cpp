#include "CreaturePen.h"

void ACreaturePen::UpdateCallout() {
}

void ACreaturePen::OnDressingReady() {
}




bool ACreaturePen::IsReadyToSlotCreature_Implementation() const {
    return false;
}

bool ACreaturePen::IsOccupied() const {
    return false;
}

ACreaturePen::ACreaturePen() {
    this->CachedWalkOutTrigger = NULL;
}

