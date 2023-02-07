#include "UMGFocusWidget.h"

void UUMGFocusWidget::UnregisterUMGInputAxis(EUMGInputAxis InputAxis) {
}

void UUMGFocusWidget::UnregisterUMGInputAction(EUMGInputAction InputAction, TEnumAsByte<EInputEvent> InputEvent) {
}

void UUMGFocusWidget::UnregisterAllUMGInputAxis() {
}

void UUMGFocusWidget::UnregisterAllUMGInputActions(TEnumAsByte<EInputEvent> InputEvent) {
}

void UUMGFocusWidget::RegisterUMGInputAxis(EUMGInputAxis InputAxis) {
}

void UUMGFocusWidget::RegisterUMGInputAction(EUMGInputAction InputAction, TEnumAsByte<EInputEvent> InputEvent) {
}

void UUMGFocusWidget::RegisterAllUMGInputAxis() {
}

void UUMGFocusWidget::RegisterAllUMGInputActions(TEnumAsByte<EInputEvent> InputEvent) {
}

void UUMGFocusWidget::LoseFocus() {
}

bool UUMGFocusWidget::HasFocus() const {
    return false;
}





void UUMGFocusWidget::AcquireFocus() {
}

UUMGFocusWidget::UUMGFocusWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->FocusInputPriority = 100;
    this->bHasFocus = false;
}

