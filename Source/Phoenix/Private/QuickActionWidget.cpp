#include "QuickActionWidget.h"

void UQuickActionWidget::SetItemArray(const TArray<FInventoryResult>& Items, int32 StartingIndex) {
}


UQuickActionWidget::UQuickActionWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->StartIndex = 0;
}

