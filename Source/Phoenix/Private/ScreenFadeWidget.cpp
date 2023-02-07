#include "ScreenFadeWidget.h"


bool UScreenFadeWidget::UI_IsFading() {
    return false;
}


void UScreenFadeWidget::UI_FadeOutDone() {
}


void UScreenFadeWidget::UI_FadeInDone() {
}



void UScreenFadeWidget::OnCurtainLowered() {
}

UScreenFadeWidget::UScreenFadeWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->FadeInStarted = false;
    this->FadeOutStarted = false;
    this->DoneFading = true;
    this->FadeSpeed = 1.00f;
    this->DefaultFadeSpeed = 1.00f;
}

