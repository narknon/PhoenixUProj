#include "SpellBarSlotWidget.h"



void USpellBarSlotWidget::SetImage(const FString& ImageName) {
}


USpellBarSlotWidget::USpellBarSlotWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->IconName = TEXT("UI_T_Unknown");
    this->slotIcon = NULL;
}

