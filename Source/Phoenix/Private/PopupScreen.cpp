#include "PopupScreen.h"

class UPhoenixUserWidget;







void UPopupScreen::SetCachedUsesWaitIndicator(const bool bUsesWaitIndicator) {
}

void UPopupScreen::SetCachedCompletionActions(const TArray<FInputActionHoldInfo>& CompletionActions) {
}

void UPopupScreen::SetAutoCloseOnButtonPress(const bool bInAutoCloseOnButtonPress) {
}

void UPopupScreen::PopupButtonPressCompleted(const int32 CompletionActionIndex) {
}

void UPopupScreen::OpenPopup(const bool bPauseTheGame) {
}

void UPopupScreen::OnPopupOutroEnded(UPhoenixUserWidget* PhoenixWidget, int32 OutroType) {
}

int32 UPopupScreen::GetPopupID() {
    return 0;
}

void UPopupScreen::ClosePopup(const int32 CompletionActionIndex) {
}

UPopupScreen::UPopupScreen() {
    this->PopupID = 0;
    this->bCachedUsesWaitIndicator = false;
    this->bPausedTheGame = false;
    this->bAutoCloseOnButtonPress = false;
    this->bPopupClosedEventSent = false;
}

