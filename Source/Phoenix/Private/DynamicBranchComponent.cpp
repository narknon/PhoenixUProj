#include "DynamicBranchComponent.h"

void UDynamicBranchComponent::StartDynamicBranch(EEnemy_Ability InAbility, EEnemy_Ability InNextAbility, bool bStartImmediate) {
}

void UDynamicBranchComponent::SetAbilitySupported(EEnemy_Ability InAbility) {
}

void UDynamicBranchComponent::SetAbilityActive(EEnemy_Ability InAbility, bool bActive) {
}

bool UDynamicBranchComponent::IsAbilitySupported(EEnemy_Ability InAbility) const {
    return false;
}

bool UDynamicBranchComponent::IsAbilityActive(EEnemy_Ability InAbility) const {
    return false;
}

EEnemy_Ability UDynamicBranchComponent::GetActiveAbility() const {
    return EEnemy_Ability::Idle;
}

void UDynamicBranchComponent::ClearAbilitySupported(EEnemy_Ability InAbility) {
}

UDynamicBranchComponent::UDynamicBranchComponent() {
    this->SupportedAbilities = 0;
    this->bStartImmediateBranchIfBranchTaskNotActive = false;
    this->AbilityComponent = NULL;
}

