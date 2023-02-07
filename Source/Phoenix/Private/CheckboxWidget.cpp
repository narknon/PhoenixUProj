#include "CheckboxWidget.h"

void UCheckboxWidget::StateChanged(bool State) {
}

void UCheckboxWidget::SetProperties(FText Label, int32 Index) {
}

void UCheckboxWidget::SetCheckboxOnOff(FText Label, bool checked) {
}


UCheckboxWidget::UCheckboxWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->PreTranslateText = false;
    this->IsChecked = false;
    this->TheCheckbox = NULL;
    this->CheckboxTextBlock = NULL;
}

