#include "WaterInteractionComponent.h"

void UWaterInteractionComponent::WakeUp(bool bEnableForWater) {
}

void UWaterInteractionComponent::Sleep() {
}

UWaterInteractionComponent::UWaterInteractionComponent() {
    this->bCanRipple = true;
    this->Radius = 30.00f;
    this->IntensityMultiplier = 1.00f;
}

