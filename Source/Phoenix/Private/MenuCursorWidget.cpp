#include "MenuCursorWidget.h"


void UMenuCursorWidget::ScaleCursor(bool IsHover) {
}

void UMenuCursorWidget::ResetTooltipState() {
}


void UMenuCursorWidget::Cursor_FadeOutDone() {
}


void UMenuCursorWidget::Cursor_FadeInDone() {
}


UMenuCursorWidget::UMenuCursorWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->IsScaledDown = false;
    this->DefaultExpandState = true;
    this->FadeInStarted = false;
    this->FadeOutStarted = false;
    this->DoneFading = true;
    this->FadeSpeed = 1.00f;
    this->DefaultFadeSpeed = 1.00f;
}

