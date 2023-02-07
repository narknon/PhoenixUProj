#include "InventoryManagerInterface.h"

class AActor;

bool UInventoryManagerInterface::UseItemByName(const FName CharacterID, FName ItemId, const FName Variation) {
    return false;
}

bool UInventoryManagerInterface::UseItem(const FName CharacterID, FInventoryResult InventoryResult) {
    return false;
}

bool UInventoryManagerInterface::TransferItemToPlayerInventoryBP(FInventoryResult TransferItem, int32 AmountToTransfer) {
    return false;
}

bool UInventoryManagerInterface::TransferItemToContainerBP(FInventoryResult ItemToTransfer, FName CharacterID, FName HolderID, int32 AmountToTransfer) {
    return false;
}

void UInventoryManagerInterface::SetPlayerExpandedInventoryBP(int32 newInventoryAmount) {
}

bool UInventoryManagerInterface::SellItemFromPlayerInventoryBP(FInventoryResult TransferItem, int32 SoldCount, FName VendorName, int32& OutKnutsEarned) {
    return false;
}

void UInventoryManagerInterface::ResetInventory(const FName CharacterID, FName HolderID) {
}

bool UInventoryManagerInterface::IsAbilityActive(AActor* Actor, FName AbilityName) {
    return false;
}

bool UInventoryManagerInterface::HasAnyInventory(const FName CharacterID, const FName HolderID) {
    return false;
}

TArray<FName> UInventoryManagerInterface::GetQuestItems() {
    return TArray<FName>();
}

TArray<FName> UInventoryManagerInterface::GetPlayerUnlimitedHolders() {
    return TArray<FName>();
}

int32 UInventoryManagerInterface::GetPlayerStolenItemCount() {
    return 0;
}

TArray<FName> UInventoryManagerInterface::GetPlayerLimitedHolders() {
    return TArray<FName>();
}

int32 UInventoryManagerInterface::GetPlayerExpandedInventoryBP() {
    return 0;
}

int32 UInventoryManagerInterface::GetPlayerAvailableCapacity(FName ItemId, bool UseMaxCapacityWhenNoReturnExcess) {
    return 0;
}

FName UInventoryManagerInterface::GetItemInventoryFullString(FName ItemId) {
    return NAME_None;
}

bool UInventoryManagerInterface::GetIsInspectableBP(const FString& ItemId) {
    return false;
}

void UInventoryManagerInterface::GetInventoryTypesBP(TArray<FName>& InventoryTypeArray) {
}

void UInventoryManagerInterface::GetInventoryTextBP(const FName InCharacterID, const FName InItemTypeID, TArray<FInventoryResult>& InventoryResultArray, const FInventoryFilter InventoryFilter, const FName HolderID, bool SkipLockedItems, bool SpecifiedHolderOnly) {
}

int32 UInventoryManagerInterface::GetInventorySellPriceBP(FName CharacterID, FName HolderID) {
    return 0;
}

int32 UInventoryManagerInterface::GetHolderMaxSlotsBP(FName HolderID) {
    return 0;
}

FName UInventoryManagerInterface::GetHolderInventoryFullString(FName HolderID) {
    return NAME_None;
}

int32 UInventoryManagerInterface::GetCount(const FName CharacterID, const FName InventoryObjectID, const EInventoryObjectType InventoryObjectType, const EStolenType StolenType, const FName HolderID, const FName Variation) {
    return 0;
}

int32 UInventoryManagerInterface::GetCost(const FName InventoryObjectID, const FName Variation) {
    return 0;
}

int32 UInventoryManagerInterface::GetContainerMaxSlotsBP(FName ContainerID) {
    return 0;
}

bool UInventoryManagerInterface::DropItemBP(FInventoryResult ItemToDrop, int32 AmountToDrop) {
    return false;
}

int32 UInventoryManagerInterface::CanAddItem(const FName CharacterID, const FName ItemId, const FName HolderID, const FName Variation, int32 Count) {
    return 0;
}

int32 UInventoryManagerInterface::AdjustCount(const FName CharacterID, const FName InventoryObjectID, const int32 Delta, const EInventoryChangeReason Reason, const FName HolderID, const FName Variation, const bool SuppressHUDNotification, const bool SpecialHUDNotification, const FName OtherCharacterID, const bool IsUnique, const bool IsStolen, const bool KeepOnReset) {
    return 0;
}

UInventoryManagerInterface::UInventoryManagerInterface() {
}

