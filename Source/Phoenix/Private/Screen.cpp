#include "Screen.h"

class UPhoenixUserWidget;

void UScreen::ScreenUnregisterAllUMGInputAxis() {
}

void UScreen::ScreenUnregisterAllUMGInputActions(EInputEvent InputEvent) {
}

void UScreen::ScreenRegisterAllUMGInputAxis() {
}

void UScreen::ScreenRegisterAllUMGInputActions(EInputEvent InputEvent) {
}

void UScreen::OnScreenOutroComplete(UPhoenixUserWidget* PhoenixWidget, int32 OutroType) {
}

bool UScreen::IsInputEnabled() const {
    return false;
}

int32 UScreen::GetZOrderOffsetForScreenType(EUIScreenType InScreenType) {
    return 0;
}


void UScreen::CloseScreenWithOutro() {
}


UScreen::UScreen() {
    this->ScreenType = EUIScreenType::UIST_Screen;
    this->PopupPriority = EUIPopupPriority::UIPP_Normal;
    this->ShouldShowCursor = true;
    this->ShouldHideCursorOnRemove = false;
    this->HandleBackButton = true;
    this->MouseLockMode = EMouseLockMode::DoNotLock;
    this->bAutoAcquireUMGFocus = true;
}

