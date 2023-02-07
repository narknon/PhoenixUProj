#include "CapturingWidget.h"


void UCapturingWidget::RemoveFromHUD() {
}


UCapturingWidget::UCapturingWidget() {
    this->CaptureDevice = NULL;
    this->AttachedComponent = NULL;
    this->bIsProjectedFromOffscreen = false;
}

