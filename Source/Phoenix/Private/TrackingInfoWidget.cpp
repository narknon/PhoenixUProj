#include "TrackingInfoWidget.h"

void UTrackingInfoWidget::OnDisplayInputReleased() {
}

bool UTrackingInfoWidget::GetIsExtended() {
    return false;
}

bool UTrackingInfoWidget::GetIsDisplayed() {
    return false;
}




UTrackingInfoWidget::UTrackingInfoWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->DisplayDuration = 8.00f;
}

