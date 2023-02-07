#include "StartPageWidget.h"

class UObject;
class UPhoenixUserWidget;






void UStartPageWidget::OnUserProfileChange(const UObject* i_caller, const FString& UserName) {
}

void UStartPageWidget::OnStartPageOutroStarted(UPhoenixUserWidget* PhoenixWidget, int32 OutroType) {
}

void UStartPageWidget::OnStartPageOutroEnded(UPhoenixUserWidget* PhoenixWidget, int32 OutroType) {
}

void UStartPageWidget::OnStartPageIntroStarted(UPhoenixUserWidget* PhoenixWidget, int32 IntroType) {
}

UStartPageWidget::UStartPageWidget() {
    this->CanProceed = false;
}

