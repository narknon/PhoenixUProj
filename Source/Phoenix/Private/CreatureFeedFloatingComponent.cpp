#include "CreatureFeedFloatingComponent.h"

FVector UCreatureFeedFloatingComponent::GetAveragePelletLocation() const {
    return FVector{};
}

UCreatureFeedFloatingComponent::UCreatureFeedFloatingComponent() {
    this->OscillationBlendInTime = 2.00f;
    this->OscillationAmplitudeVert = 4.00f;
    this->OscillationFrequencyVert = 1.00f;
    this->OscillationAmplitudeHoriz = 4.00f;
    this->OscillationFrequencyHoriz = 0.50f;
    this->OscillationRotationSpeedDegMax = 20.00f;
    this->FloatingBlendTime = 3.00f;
    this->FloatingBlendPow = 3.00f;
    this->FloatingStiffnessDistanceMax = 200.00f;
    this->FloatingStiffnessMin = 3.00f;
    this->FloatingStiffnessMax = 64.00f;
    this->FloatingStiffnessRange = 3.00f;
    this->FloatingCriticalDampingFactor = 0.70f;
    this->FloatingInterpolationSpeed = 1.00f;
    this->FloatingExpandTime = 0.25f;
    this->FloatingExpandDistanace = 40.00f;
    this->AttachStartDelay = 0.30f;
    this->AttachedBlendTime = 2.00f;
    this->AttachedBlendPow = 3.00f;
    this->AttachedInterpolationSpeed = 30.00f;
    this->AttachTargetActor = NULL;
}

