#include "CooldownPickup.h"

class AActor;

void ACooldownPickup::UnpauseAndShow() {
}

void ACooldownPickup::PauseAndHide() {
}

void ACooldownPickup::OnPickedUp(AActor* InActor) {
}

float ACooldownPickup::GetDisablePickupTime() const {
    return 0.0f;
}

bool ACooldownPickup::CanPickup() {
    return false;
}

ACooldownPickup::ACooldownPickup() {
    this->Prim = NULL;
}

