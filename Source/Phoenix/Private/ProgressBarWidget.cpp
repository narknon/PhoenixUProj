#include "ProgressBarWidget.h"

void UProgressBarWidget::SetProgress(float NewProgress) {
}

void UProgressBarWidget::SetLabel(FText NewLabel) {
}


UProgressBarWidget::UProgressBarWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->ProgressPct = 0.50f;
    this->Label = NULL;
    this->Progress = NULL;
}

