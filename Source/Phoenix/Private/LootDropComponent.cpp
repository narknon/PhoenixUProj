#include "LootDropComponent.h"

class AActor;
class ULootDropComponent;

void ULootDropComponent::SetupInventory() {
}

void ULootDropComponent::SetLootLevel(int32 Level) {
}

void ULootDropComponent::SetLoopGroup(const FString& lootGroup) {
}

void ULootDropComponent::SetCurrentLootCategoryID() {
}

void ULootDropComponent::SaveLootToInventory() {
}

void ULootDropComponent::SaveLootItemsToInventory(TArray<FLootSlot>& InLootItems) {
}

bool ULootDropComponent::IsContainerEmpty() {
    return false;
}

int32 ULootDropComponent::GetLootLevel() {
    return 0;
}

TArray<FLootSlot> ULootDropComponent::GetLootItems() {
    return TArray<FLootSlot>();
}

ULootDropComponent* ULootDropComponent::GetLootDropComponent(const AActor* InActor) {
    return NULL;
}

TArray<FInventoryResult> ULootDropComponent::GetInventoryInfo() {
    return TArray<FInventoryResult>();
}

void ULootDropComponent::FillFromInventory() {
}

void ULootDropComponent::ClearCurrentLootCategoryID() {
}

ULootDropComponent::ULootDropComponent() {
    this->LootDropLevel = 0;
    this->PlayerLevelOverride = false;
    this->SecondsBeforeRerollingLoot = 259200;
    this->bCogOverride = true;
    this->bResetExpiryIfUnique = false;
    this->bPreloadLootDropItemsFromDb = false;
}

