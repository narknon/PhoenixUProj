#include "HeaderWidget.h"

void UHeaderWidget::SetHeaderTitle(FText NewTitle) {
}

void UHeaderWidget::SetHeaderSubtitle(FText NewSubtitle) {
}


UHeaderWidget::UHeaderWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->Title = NULL;
    this->Subtitle = NULL;
}

