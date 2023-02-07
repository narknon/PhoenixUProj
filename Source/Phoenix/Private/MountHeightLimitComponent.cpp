#include "MountHeightLimitComponent.h"

void UMountHeightLimitComponent::SetHeightOverrides(float InTargetHeight, float InHeightBuffer) {
}

float UMountHeightLimitComponent::GetFlyHeight() const {
    return 0.0f;
}

void UMountHeightLimitComponent::ClearHeightOverrides() {
}

UMountHeightLimitComponent::UMountHeightLimitComponent() {
    this->RegionHeights = NULL;
}

