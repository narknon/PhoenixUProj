#include "CreaturePettingBrushFloatingComponent.h"

void UCreaturePettingBrushFloatingComponent::SetTargetTransformAndVelocity(const FTransform& InTargetTransform, const FVector& InVelocity) {
}

void UCreaturePettingBrushFloatingComponent::SetOscillationEnabled(const bool bInEnabled) {
}

void UCreaturePettingBrushFloatingComponent::SetFloatingState(const ECreaturePettingBrushFloatingState InFloatingState) {
}

UCreaturePettingBrushFloatingComponent::UCreaturePettingBrushFloatingComponent() {
    this->FloatingAmplitude = 50.00f;
    this->FloatingFrequency = 3.00f;
    this->FloatingStiffness = 4.00f;
    this->FloatingMaxExtension = 1000.00f;
    this->FloatingDamping = 4.00f;
    this->FloatingScaleInterpolationSpeed = 1.00f;
    this->FloatingRotationInterpolationSpeed = 1.00f;
    this->FloatingMaxForce = 1000000.00f;
    this->bClampForce = false;
    this->AttachedBlendTime = 3.00f;
    this->AttachedDamping = 8.00f;
    this->AttachedLocationInterpolationSpeedMin = 10.00f;
    this->AttachedLocationInterpolationSpeedMax = 100.00f;
    this->AttachedRotationInterpolationSpeedMin = 10.00f;
    this->AttachedRotationInterpolationSpeedMax = 100.00f;
    this->AttachedScaleInterpolationSpeedMin = 10.00f;
    this->AttachedScaleInterpolationSpeedMax = 100.00f;
    this->AttachedInterpolationSpeedAfterBlend = 1000.00f;
    this->bApplyScaling = true;
}

