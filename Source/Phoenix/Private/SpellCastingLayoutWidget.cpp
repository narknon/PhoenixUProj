#include "SpellCastingLayoutWidget.h"

void USpellCastingLayoutWidget::SpellSelected() {
}




void USpellCastingLayoutWidget::EnterSpellMode(bool InSpellMode) {
}

USpellCastingLayoutWidget::USpellCastingLayoutWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->ActiveLayout = false;
    this->ParentWidget = NULL;
}

