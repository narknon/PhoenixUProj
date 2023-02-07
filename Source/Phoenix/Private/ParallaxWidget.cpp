#include "ParallaxWidget.h"

class UCanvasPanelSlot;

void UParallaxWidget::SyncParallaxToCursor(UCanvasPanelSlot* ParallaxingObject) {
}

void UParallaxWidget::SetInitialCursorPosition(UCanvasPanelSlot* ParallaxingObject) {
}

void UParallaxWidget::IgnoreParallax() {
}

UCanvasPanelSlot* UParallaxWidget::GetSlot() {
    return NULL;
}

void UParallaxWidget::ApplyParallaxEffect(UCanvasPanelSlot* ParallaxingObject) {
}

void UParallaxWidget::ApplyParallax() {
}

UParallaxWidget::UParallaxWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->SlideRate = 0.00f;
}

