#include "AnimatedLightClusterComponent.h"

void UAnimatedLightClusterComponent::RebuildLights() {
}

UAnimatedLightClusterComponent::UAnimatedLightClusterComponent() {
    this->MaxVisibleDistance = 0.00f;
    this->SleepDeltaTime = 0.00f;
    this->bCanForceUpdates = false;
}

