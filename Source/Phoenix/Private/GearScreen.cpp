#include "GearScreen.h"

bool UGearScreen::UnequipGearItem(EGearSlotIDEnum GearSlot, FGearItemID& NewGearItemId) {
    return false;
}

FGearItemID UGearScreen::MakeGearIdForAppearance(FName GearID, EGearSlotIDEnum SlotID) {
    return FGearItemID{};
}

bool UGearScreen::IsPlayerOnMount() {
    return false;
}

bool UGearScreen::IsPlayerOnBroom() {
    return false;
}

void UGearScreen::GetUnlockedAppearanceGear(EGearSlotIDEnum SlotID, TArray<FString>& OutCostumes, TArray<FString>& OutGeneral) {
}

TArray<FInventoryResult> UGearScreen::GetSortedTools(FName ActiveHolderID, FName StorageHolderID) {
    return TArray<FInventoryResult>();
}

TArray<FRPGUIInfo> UGearScreen::GetActiveBuffData() {
    return TArray<FRPGUIInfo>();
}

bool UGearScreen::EquipGearItem(FGearItemID GearItemID, FGearItemID& NewGearItemId) {
    return false;
}

UGearScreen::UGearScreen() {
    this->MenuCharacter = NULL;
    this->WandActor = NULL;
    this->BroomProxyActor = NULL;
    this->MountActor = NULL;
    this->ShowAppearanceGear = false;
    this->IsAppearanceInventory = false;
}

