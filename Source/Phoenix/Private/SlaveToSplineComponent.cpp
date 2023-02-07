#include "SlaveToSplineComponent.h"

class USplineComponent;

void USlaveToSplineComponent::SetSplineT(float newT, bool& Done) {
}

void USlaveToSplineComponent::Reset() {
}

USplineComponent* USlaveToSplineComponent::GetFollowSpline() const {
    return NULL;
}

USlaveToSplineComponent::USlaveToSplineComponent() {
    this->Mode = ESlaveToSplineUpdateMode::Wrap;
    this->DurationFactor = 1.00f;
    this->SplineT = 0.00f;
    this->SplineTReset = 0.00f;
    this->bUseConstantVelocity = false;
    this->bPositionOnly = true;
    this->bIncludeScale = false;
    this->bReverseDirection = false;
    this->bFollowEnabled = true;
}

