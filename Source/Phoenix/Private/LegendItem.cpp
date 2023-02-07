#include "LegendItem.h"


void ULegendItem::StopHolding() {
}

void ULegendItem::StartHolding() {
}


void ULegendItem::SetProgressUsed(const bool ProgressUsed) {
}

void ULegendItem::SetProgress(const float Progress) {
}

void ULegendItem::SetLegendItemData(const FLegendItemData& LegendItemData) {
}

void ULegendItem::SetHoldDuration(const float NewHoldDuration) {
}

void ULegendItem::SetDisabledState(const bool Disabled) {
}




FLegendItemData ULegendItem::GetLegendItemData() const {
    return FLegendItemData{};
}


ULegendItem::ULegendItem() {
    this->mIsHolding = false;
    this->mProgress = 0.00f;
    this->mDisabledState = false;
    this->mHoldTimeRemaining = 0.00f;
}

