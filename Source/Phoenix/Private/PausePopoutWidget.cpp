#include "PausePopoutWidget.h"

void UPausePopoutWidget::SetPopoutData(FText NewTitle, FText NewDescription) {
}


UPausePopoutWidget::UPausePopoutWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->PopoutHeader = NULL;
    this->PopoutDescription = NULL;
    this->LegendText = NULL;
}

