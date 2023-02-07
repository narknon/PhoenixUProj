#include "InventoryObjectManagerBPInterface.h"

class UStaticMesh;

UStaticMesh* UInventoryObjectManagerBPInterface::GetItemStaticMesh(const FName InventoryObjectID) {
    return NULL;
}

int32 UInventoryObjectManagerBPInterface::GetItemSellPrice(int32 DbPrice, int32 EconomyValue) {
    return 0;
}

bool UInventoryObjectManagerBPInterface::GetItemProperties(const FName InventoryObjectID, FItemProperties& ItemProperties, FName Variation) {
    return false;
}

int32 UInventoryObjectManagerBPInterface::GetInventorySlotCapacityByName(FName ItemId, FName ItemType, FName SlotLevelName) {
    return 0;
}

int32 UInventoryObjectManagerBPInterface::GetInventorySlotCapacityByIndex(FName ItemId, FName ItemType, int32 SlotLevelIndex) {
    return 0;
}

UInventoryObjectManagerBPInterface::UInventoryObjectManagerBPInterface() {
}

