#include "ToolTipPopoutWidget.h"

void UToolTipPopoutWidget::SetHeaderData(FText NewTitle, FText NewSubtitle) {
}

void UToolTipPopoutWidget::SetDescription(FText NewDescription) {
}

void UToolTipPopoutWidget::SetButtonLegend(FText Legend) {
}


UToolTipPopoutWidget::UToolTipPopoutWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->Header = NULL;
    this->Description = NULL;
}

