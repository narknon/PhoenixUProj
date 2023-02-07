#include "ConjurationSpellTool.h"

void AConjurationSpellTool::UpdatePreviewResourceRequirementsMet() {
}

void AConjurationSpellTool::UpdateHoldConjuring(float TimeRatio) {
}

void AConjurationSpellTool::UndoLastConjuredItem() {
}

void AConjurationSpellTool::StartHoldConjuring() {
}

void AConjurationSpellTool::ShowItemPreview(FName InItemID, FName InColorID) {
}

void AConjurationSpellTool::SetCategory(FName CategoryID) {
}

TArray<FLockableTransfigurationItem> AConjurationSpellTool::GetSubCategories(const FName CategoryName) {
    return TArray<FLockableTransfigurationItem>();
}

TArray<FLockableTransfigurationItem> AConjurationSpellTool::GetItemList() {
    return TArray<FLockableTransfigurationItem>();
}

FLockableTransfigurationItem AConjurationSpellTool::GetItemData(FName ItemOrCategoryName) const {
    return FLockableTransfigurationItem{};
}

FName AConjurationSpellTool::GetCurrentCategory() const {
    return NAME_None;
}

FString AConjurationSpellTool::GetCategoryTextKey() const {
    return TEXT("");
}

void AConjurationSpellTool::FinishHoldConjuring() {
}

void AConjurationSpellTool::ConjureMenuFullStop() {
}

bool AConjurationSpellTool::CanUndoLastItem() const {
    return false;
}

void AConjurationSpellTool::CannotHoldConjuring() {
}

void AConjurationSpellTool::CancelHoldConjuring(float TimeRatio) {
}

AConjurationSpellTool::AConjurationSpellTool() {
    this->SelectedCategory = 0;
    this->SelectedSubcategory = 0;
    this->SelectedIcon = 0;
    this->MovementThresholdToSpawnNextPreview = 20.00f;
    this->AngleThresholdToSpawnNextPreview = 5.00f;
    this->MinConjurationDuration = 0.50f;
    this->MaxConjurationDuration = 4.00f;
    this->MaxNumItemsForConjurationDurationMax = 180;
    this->bUseDefaultVanishmentForSingleObjectUndo = true;
    this->UndoPreviewActorClass = NULL;
    this->MinSecondsBetweenUndoVanishments = 0.50f;
}

