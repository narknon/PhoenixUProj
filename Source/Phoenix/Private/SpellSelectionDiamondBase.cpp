#include "SpellSelectionDiamondBase.h"

class USelectionRingItemBase;

void USpellSelectionDiamondBase::SlotNewItem(const FString& NewItem, const FString& Variation, FName ItemHolder, int32 Count, EUIQActionBarType Type) {
}

void USpellSelectionDiamondBase::SetSelectedIndex(int32 Index) {
}

void USpellSelectionDiamondBase::CollectItemData(int32 GroupIndex) {
}

void USpellSelectionDiamondBase::AddItemToWidgetArray(USelectionRingItemBase* Widget) {
}

USpellSelectionDiamondBase::USpellSelectionDiamondBase() : UUserWidget(FObjectInitializer::Get()) {
    this->SelectedIndex = 0;
}

