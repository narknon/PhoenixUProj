#include "TextButtonWidget.h"

void UTextButtonWidget::SetText(FText NewKey) {
}


FText UTextButtonWidget::GetText() {
    return FText::GetEmpty();
}

void UTextButtonWidget::ChangeTextColorOnButtonUnHover() {
}

void UTextButtonWidget::ChangeTextColorOnButtonHover() {
}

UTextButtonWidget::UTextButtonWidget() {
    this->IsButtonPressed = false;
    this->UserData = NULL;
    this->TheButton = NULL;
    this->TheText = NULL;
}

