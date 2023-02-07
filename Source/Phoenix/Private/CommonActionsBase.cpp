#include "CommonActionsBase.h"

class UMiniSelectionDiamondBase;
class USpellSelectionDiamondBase;

void UCommonActionsBase::ToggleButtonCallouts(bool IsSlotting) {
}

void UCommonActionsBase::ShowSelected(int32 GroupIndex) {
}

void UCommonActionsBase::SetSelectedIndex(int32 Index) {
}

void UCommonActionsBase::SetMainLoadout(USpellSelectionDiamondBase* Loadout) {
}

void UCommonActionsBase::SetItemData(int32 GroupIndex) {
}

void UCommonActionsBase::PopulateMainLoadout() {
}





void UCommonActionsBase::HandleDPadUp() {
}

void UCommonActionsBase::HandleDPadRight() {
}

void UCommonActionsBase::HandleDPadLeft() {
}

void UCommonActionsBase::HandleDPadDown() {
}

void UCommonActionsBase::AddMiniSelectionItem(UMiniSelectionDiamondBase* Item) {
}

void UCommonActionsBase::AddItemToGroup(const FString& ItemName, const FString& Variation, FName HolderID, int32 Amount, EUIQActionBarType ItemType) {
}

void UCommonActionsBase::ActivateCurrentMiniDiamond(bool Activate) {
}

UCommonActionsBase::UCommonActionsBase() : UUserWidget(FObjectInitializer::Get()) {
    this->AvailableGroups = 1;
    this->CurrentGroupIndex = 0;
    this->MainLoadout = NULL;
}

