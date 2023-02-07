#include "CreatureSpawnSlotComponent.h"

bool UCreatureSpawnSlotComponent::IsOccupied() {
    return false;
}

FTransform UCreatureSpawnSlotComponent::GetSpawnTransform() const {
    return FTransform{};
}

UCreatureSpawnSlotComponent::UCreatureSpawnSlotComponent() {
    this->bIsOffspringSlot = false;
    this->bSpawnPerched = false;
    this->bUseExitAnimation = true;
    this->ExitAnimationAsset = NULL;
    this->bExitFlying = false;
    this->bRestrictSpecies = false;
}

