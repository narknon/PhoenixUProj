#include "AblAbilityComponent.h"

class AActor;
class UAblAbility;
class UAblAbilityContext;

void UAblAbilityComponent::UnpauseAllAbilities() {
}

void UAblAbilityComponent::TriggerAbleEvent(const AActor* AbleOwner, const AActor* AbleSender, const FName EventName) {
}

void UAblAbilityComponent::SetIgnorePlayAbility(bool bFlag) {
}

void UAblAbilityComponent::RemoveTag(const FGameplayTag Tag) {
}

void UAblAbilityComponent::PauseAllAbilities() {
}

void UAblAbilityComponent::PauseAbility(bool bEnable, const UAblAbility* Abilit) {
}

bool UAblAbilityComponent::MatchesQuery(const FGameplayTagQuery Query) const {
    return false;
}

bool UAblAbilityComponent::MatchesAnyTag(const FGameplayTagContainer Container) const {
    return false;
}

bool UAblAbilityComponent::MatchesAllTags(const FGameplayTagContainer Container) const {
    return false;
}

bool UAblAbilityComponent::IsPlayingAbility() const {
    return false;
}

bool UAblAbilityComponent::IsPassiveActive(const UAblAbility* Ability) const {
    return false;
}

bool UAblAbilityComponent::IsAbilityPaused(const UAblAbility* Ability) {
    return false;
}

bool UAblAbilityComponent::HasTag(const FGameplayTag Tag) const {
    return false;
}

bool UAblAbilityComponent::HasAbilityAnimation() const {
    return false;
}

FGameplayTagContainer UAblAbilityComponent::GetGameplayTagContainerBP() const {
    return FGameplayTagContainer{};
}

UAblAbility* UAblAbilityComponent::GetActiveAbility_New(const FName ChannelName) {
    return NULL;
}

UAblAbility* UAblAbilityComponent::GetActiveAbility() const {
    return NULL;
}

void UAblAbilityComponent::CancelAllAbilities(EAblAbilityTaskResult ResultToUse, bool bHideActor) {
}

void UAblAbilityComponent::CancelAbilityChannel(const FName& ChannelName, TEnumAsByte<EAblAbilityTaskResult> ResultToUse, bool bHideActor) {
}

void UAblAbilityComponent::CancelAbility(const UAblAbility* Ability, TEnumAsByte<EAblAbilityTaskResult> ResultToUse) {
}

EAblAbilityStartResult UAblAbilityComponent::CanActivateAbility(UAblAbilityContext* Context) const {
    return EAblAbilityStartResult::InvalidTarget;
}

EAblAbilityStartResult UAblAbilityComponent::BranchAbility(UAblAbilityContext* Context) {
    return EAblAbilityStartResult::InvalidTarget;
}

void UAblAbilityComponent::AddTag(const FGameplayTag Tag) {
}

void UAblAbilityComponent::ActorHiddenTimeout() {
}

EAblAbilityStartResult UAblAbilityComponent::ActivateAbility(UAblAbilityContext* Context) {
    return EAblAbilityStartResult::InvalidTarget;
}

UAblAbilityComponent::UAblAbilityComponent() {
    this->GlobalPlayRate = 1.00f;
    this->GlobalMeshScale = 1.00f;
    this->m_Verbose = true;
    this->AblAbilityAsset = NULL;
    this->SkeletalMeshComponent = NULL;
}

