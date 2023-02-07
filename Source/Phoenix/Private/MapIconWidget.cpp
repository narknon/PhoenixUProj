#include "MapIconWidget.h"


float UMapIconWidget::GetZoomFactor() {
    return 0.0f;
}

float UMapIconWidget::GetPitchFactor() {
    return 0.0f;
}

float UMapIconWidget::GetDistanceFromGround() {
    return 0.0f;
}

UMapIconWidget::UMapIconWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->IconName = NULL;
    this->RegionBorder = NULL;
}

