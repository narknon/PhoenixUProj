#include "WandLinkWidget.h"




void UWandLinkWidget::Start() {
}



float UWandLinkWidget::GetWandLinkPercentage() const {
    return 0.0f;
}

float UWandLinkWidget::GetSuccessRatio() const {
    return 0.0f;
}

void UWandLinkWidget::End() {
}

UWandLinkWidget::UWandLinkWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->bUsingKeyboard = false;
}

