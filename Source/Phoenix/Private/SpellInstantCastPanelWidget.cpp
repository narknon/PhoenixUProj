#include "SpellInstantCastPanelWidget.h"

void USpellInstantCastPanelWidget::UpdateSpellGroup(bool OutAnimDone) {
}

void USpellInstantCastPanelWidget::UpdateSlotState(bool IsActive) {
}

void USpellInstantCastPanelWidget::UpdateAvailableSpellList(bool Next) {
}

void USpellInstantCastPanelWidget::ShowSpellPanel(bool Show) {
}

void USpellInstantCastPanelWidget::SetSpellName(FText NewName, int32 SpellIndex) {
}






void USpellInstantCastPanelWidget::InitSpells() {
}

void USpellInstantCastPanelWidget::GetSpellData() {
}

USpellInstantCastPanelWidget::USpellInstantCastPanelWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->Wand = NULL;
    this->BipedCharacter = NULL;
    this->NextLoadout = false;
    this->SpellGroupIndex = 0;
    this->Spell_0 = NULL;
    this->Spell_1 = NULL;
    this->SpellNameText_0 = NULL;
    this->SpellNameText_1 = NULL;
    this->SpellGroupIcon = NULL;
}

