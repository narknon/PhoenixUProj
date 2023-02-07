#include "ActionSelectionScreenBase.h"

class UCommonActionsBase;

void UActionSelectionScreenBase::UpdateMacroCode(const FString& ItemName, const FString& Variation, FName HolderID, EUIQActionBarType ItemType) {
}

void UActionSelectionScreenBase::ToggleListenForSpellSlottingEvents(bool ShouldListen) {
}

void UActionSelectionScreenBase::ToggleListenForSpellGroupEvents(bool ShouldListen) {
}

void UActionSelectionScreenBase::SetSlottedSpells() {
}

void UActionSelectionScreenBase::SetItemDataCode(int32 GroupId) {
}












void UActionSelectionScreenBase::OnChangeDiamondTop() {
}

void UActionSelectionScreenBase::OnChangeDiamondRight() {
}

void UActionSelectionScreenBase::OnChangeDiamondLeft() {
}

void UActionSelectionScreenBase::OnChangeDiamondBottom() {
}

void UActionSelectionScreenBase::OnCastTopSpell() {
}

void UActionSelectionScreenBase::OnCastRightSpell() {
}

void UActionSelectionScreenBase::OnCastLeftSpell() {
}

void UActionSelectionScreenBase::OnCastBottomSpell() {
}

void UActionSelectionScreenBase::HideCursorIfInTutorial() {
}

bool UActionSelectionScreenBase::HandleViewSpellButtonPress() {
    return false;
}

bool UActionSelectionScreenBase::HandleRightTriggerRelease() {
    return false;
}

bool UActionSelectionScreenBase::HandleRightTriggerPress() {
    return false;
}

bool UActionSelectionScreenBase::HandleKeyUp(EUMGInputAction InputAction) {
    return false;
}

bool UActionSelectionScreenBase::HandleKeyDown(EUMGInputAction InputAction) {
    return false;
}

bool UActionSelectionScreenBase::HandleCloseScreenButtonPress() {
    return false;
}

bool UActionSelectionScreenBase::HandleBackButtonPress() {
    return false;
}

void UActionSelectionScreenBase::ExitActionSelection() {
}

bool UActionSelectionScreenBase::CanSlotSpell() {
    return false;
}

bool UActionSelectionScreenBase::CanExitScreen() {
    return false;
}

void UActionSelectionScreenBase::AttachCommonAction(UCommonActionsBase* ActionsWidget) {
}

UActionSelectionScreenBase::UActionSelectionScreenBase() {
    this->CommonActionsCode = NULL;
    this->CurrentHighlightedItemType = EUIQActionBarType::QuickAction_None;
    this->IsSpellVideoShowing = false;
    this->CurrentHighlightedItemIsUnlocked = false;
    this->CurrentHighlightedItemIsBlacklisted = false;
    this->InSlottingMode = false;
    this->RequestedSpellSlotted = false;
    this->NeedsAutosave = false;
    this->LeviosoTutorialActive = false;
    this->AccioTutorialActive = false;
    this->VanishmentTutorialActive = false;
    this->ConjurationTutorialActive = false;
    this->CreatureBrushTutorialActive = false;
    this->CreatureFeedTutorialActive = false;
    this->AlterationTutorialActive = false;
    this->EquippingIncendioTutorialActive = false;
}

