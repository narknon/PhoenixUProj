#include "SystemMenuWidget.h"

class UPopupScreen;




void USystemMenuWidget::OnExitPopupGone() {
}

void USystemMenuWidget::OnExitPopupDismissed(UPopupScreen* Popup, int32 ConfirmationResult) {
}

void USystemMenuWidget::HandleConfirmExitDialog(EUMGInputAction ExitAction, EInputEvent ExitEvent, const FString& TitleText, const FString& DescText) {
}

bool USystemMenuWidget::ExecuteSave(const int32 CharacterID) {
    return false;
}

bool USystemMenuWidget::ExecuteLoad(const FString& Filename, const int32 CharacterID) {
    return false;
}

USystemMenuWidget::USystemMenuWidget() {
    this->HasShownExitConfirmation = false;
}

