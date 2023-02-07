#include "RPGAbilityComponent.h"

class AActor;

void URPGAbilityComponent::RemoveAbility(const FGuid& AbilityID) {
}

void URPGAbilityComponent::OnSaveGameLoad() {
}

void URPGAbilityComponent::OnGameToBeSaved() {
}

void URPGAbilityComponent::OnEndOfDay() {
}

bool URPGAbilityComponent::HasAbilityTagBP(const AActor* Owner, FGameplayTag Tag) {
    return false;
}

bool URPGAbilityComponent::CanAddAbility(FName AbilityName) {
    return false;
}

FGuid URPGAbilityComponent::AddAbility(FName AbilityName, bool bForceSyncLoad) {
    return FGuid{};
}

URPGAbilityComponent::URPGAbilityComponent() {
    this->bTickOnScheduler = true;
}

