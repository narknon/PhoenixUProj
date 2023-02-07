#include "CastingSlotWidget.h"

void UCastingSlotWidget::SetImage(const FString& ImageName) {
}



UCastingSlotWidget::UCastingSlotWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->SpellDirection = ESpellDirection::SpellDir_East;
    this->SpellIconName = TEXT("UI_T_Unknown");
}

