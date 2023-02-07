#include "InventoryState.h"

class UUserWidget;

void UInventoryState::OnEndState_Implementation() {
}

void UInventoryState::InitializeState_Implementation(UUserWidget* OwningWidget) {
}

bool UInventoryState::HandleUMGInputAction_Implementation(EUMGInputAction InputAction, EInputEvent InputEvent, UUserWidget* InventoryButton) {
    return false;
}

bool UInventoryState::HandleClicked_Implementation(UUserWidget* InventoryButton) {
    return false;
}

void UInventoryState::GetTooltipLegendData_Implementation(FInventoryResult InventoryItem, TArray<FLegendItemData>& LegendData) {
}

UUserWidget* UInventoryState::GetTooltipContent_Implementation(UUserWidget* hoveredButton) {
    return NULL;
}

TArray<UUserWidget*> UInventoryState::GetNonExpandableTooltipContent_Implementation(UUserWidget* hoveredButton) {
    return TArray<UUserWidget*>();
}

FString UInventoryState::GetMenuTitle_Implementation(EInventoryTabCategory TabCategory) {
    return TEXT("");
}

TArray<FInventoryHolder> UInventoryState::GetInventoryItemData_Implementation(const EInventorySortType SortType) {
    return TArray<FInventoryHolder>();
}

EInventoryTabCategory UInventoryState::GetDefaultInventoryTab_Implementation() {
    return EInventoryTabCategory::DefaultInventory;
}

UInventoryState::UInventoryState() {
    this->InventoryOwner = NULL;
}

