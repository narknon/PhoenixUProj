#include "LootDrop.h"

void ULootDrop::SetContainerID(const FString& ContainerID) {
}

bool ULootDrop::RemoveItems(const FString& Item, int32 Quantity, const FString& Variation) {
    return false;
}

void ULootDrop::RemoveAllItems() {
}

void ULootDrop::LootDropGenerateContents(const FString& ContentCategory, int32 Level) {
}

TArray<FLootSlot> ULootDrop::GetContents() {
    return TArray<FLootSlot>();
}

FString ULootDrop::GetContainerID() {
    return TEXT("");
}

TArray<FLootSlot> ULootDrop::GenerateContents(const FString& Category, int32 Level, bool bForceGeneration) {
    return TArray<FLootSlot>();
}

bool ULootDrop::AddItems(const FString& Item, int32 Quantity, const FString& Variation, bool IsUnique, bool IsAlreadyIdentified) {
    return false;
}

ULootDrop::ULootDrop() {
}

