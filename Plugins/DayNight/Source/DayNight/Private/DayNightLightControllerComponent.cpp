#include "DayNightLightControllerComponent.h"

void UDayNightLightControllerComponent::IsLightControllerEnabled(bool& bIsControllerEnabled) const {
}

void UDayNightLightControllerComponent::EnableLightController(bool bEnableController) {
}

UDayNightLightControllerComponent::UDayNightLightControllerComponent() {
    this->UpdateThresholdDegrees = 0.10f;
    this->bEnabled = true;
    this->bDeepScanChildren = true;
    this->LastSunAngleUpdate = -99.00f;
}

