#include "PadlockComponent.h"

void UPadlockComponent::StartGlow() {
}

void UPadlockComponent::StartDelayedGlow() {
}

void UPadlockComponent::SetGlowStrength(float GlowWipeStrength) {
}

UPadlockComponent::UPadlockComponent() {
    this->LockDifficulty = ELockDifficulty::Level_1;
    this->ReverseLock = true;
    this->GlowCurve = NULL;
    this->GlowParticleSystem = NULL;
    this->LockMaterialInstance = NULL;
    this->RemovedMeshComponent = NULL;
}

