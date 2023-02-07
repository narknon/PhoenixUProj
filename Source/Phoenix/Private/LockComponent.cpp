#include "LockComponent.h"

class AActor;

bool ULockComponent::UnlockWithKey(const FGameplayTagContainer& Key, AActor* Instigator) {
    return false;
}

bool ULockComponent::Unlock(float UnlockValue, bool bCompleteAttempt) {
    return false;
}

void ULockComponent::Lock() {
}

bool ULockComponent::IsLocked() const {
    return false;
}

float ULockComponent::GetUnlockedPercent() const {
    return 0.0f;
}

float ULockComponent::GetMaxLockValue() const {
    return 0.0f;
}

ELockLevel ULockComponent::GetLockLevel() const {
    return ELockLevel::LockLevel1;
}

float ULockComponent::GetCurrentLockValue() const {
    return 0.0f;
}

ULockComponent::ULockComponent() {
    this->LockLevel = ELockLevel::LockLevel1;
    this->LockValue = 1.00f;
    this->ConsumeKey = false;
}

