#include "WindAlignComponent.h"

void UWindAlignComponent::SetTransitionDistance(float InTransitionDistance) {
}

void UWindAlignComponent::SetStrength(float InNewStrength) {
}

void UWindAlignComponent::SetSpeedMod(float InNewSpeed) {
}

void UWindAlignComponent::SetPriority(float InNewPriority) {
}

void UWindAlignComponent::SetOutdoors(float InNewOutdoors) {
}

void UWindAlignComponent::SetBidirectional(bool bInNewBidirectional) {
}

UWindAlignComponent::UWindAlignComponent() {
    this->Outdoors = 1.00f;
    this->Priority = 9999.00f;
    this->Strength = 1.00f;
    this->SpeedMod = 1.00f;
    this->TransitionDistance = 100.00f;
    this->bBidirectional = true;
}

