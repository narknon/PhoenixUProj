#include "LegendItemData.h"

FLegendItemData::FLegendItemData() {
    this->CompletionButton = EUMGInputAction::UMGConfirm;
    this->TextStringIsLocalized = false;
    this->PressAndHold = false;
    this->HoldDuration = 0.00f;
}

