#include "WindDeflectorComponent.h"

void UWindDeflectorComponent::SetTransitionDistanceAlongDirection(float InNewTransitionDistanceAlongDirection) {
}

void UWindDeflectorComponent::SetStrength(float InNewStrength) {
}

void UWindDeflectorComponent::SetSpeedMod(float InNewSpeed) {
}

void UWindDeflectorComponent::SetPriority(float InNewPriority) {
}

void UWindDeflectorComponent::SetOutdoors(float InNewOutdoors) {
}

void UWindDeflectorComponent::SetFullEffectAlongNormal(float InNewFullEffectAlongNormal) {
}

void UWindDeflectorComponent::SetFlipNormal(bool bInNewFlipNormal) {
}

void UWindDeflectorComponent::SetBidirectional(bool bInNewBidirectional) {
}

UWindDeflectorComponent::UWindDeflectorComponent() {
    this->Outdoors = 1.00f;
    this->Priority = 9999.00f;
    this->Strength = 1.00f;
    this->SpeedMod = 1.00f;
    this->TransitionDistanceAlongDirection = 150.00f;
    this->FullEffectAlongNormal = 50.00f;
    this->bBidirectional = true;
    this->bFlipNormal = false;
}

