#include "PhoenixUserWidget.h"

class UObject;

void UPhoenixUserWidget::TriggerOutro(const int32 OutroType) {
}

void UPhoenixUserWidget::TriggerIntro(const int32 IntroType) {
}

void UPhoenixUserWidget::TriggerCustomOutro(const int32 OutroType, const float OutroDuration) {
}

void UPhoenixUserWidget::TriggerCustomIntro(const int32 IntroType, const float IntroDuration) {
}

void UPhoenixUserWidget::ReadMenu(const int32 DepthLevel, const EMenuReaderInterruptType InterruptType, UObject* InterruptOwnerFilter) {
}

void UPhoenixUserWidget::OverrideInitialIntroType(const int32 IntroType) {
}





bool UPhoenixUserWidget::IsTransitionInProgress() const {
    return false;
}

bool UPhoenixUserWidget::IsCurrentTransitionAnIntro() const {
    return false;
}

void UPhoenixUserWidget::InterruptMenuReader(const EMenuReaderInterruptType InterruptType, UObject* InterruptOwnerFilter) {
}

int32 UPhoenixUserWidget::GetCurrentTransitionType() const {
    return 0;
}

float UPhoenixUserWidget::GetCurrentTransitionProgress() const {
    return 0.0f;
}


UPhoenixUserWidget::UPhoenixUserWidget() {
    this->DefaultIntroDuration = 0.00f;
    this->DefaultOutroDuration = 0.00f;
    this->InterruptMenuReaderOnDestruct = true;
}

