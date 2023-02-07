#include "RPGAbilityEventListener_OnItemConsumed.h"

void URPGAbilityEventListener_OnItemConsumed::OnItemConsumed(FName CharacterID, FName ItemId, FName Variation, FName ItemType, FName ItemUsageType) {
}

URPGAbilityEventListener_OnItemConsumed::URPGAbilityEventListener_OnItemConsumed() {
    this->bUseItemTypeFilter = false;
    this->bUseItemUsageTypeFilter = false;
}

