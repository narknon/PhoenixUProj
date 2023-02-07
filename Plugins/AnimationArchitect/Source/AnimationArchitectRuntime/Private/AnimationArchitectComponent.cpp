#include "AnimationArchitectComponent.h"

void UAnimationArchitectComponent::RemoveObjectArchitectGameplayTag(const FGameplayTag& InGameplayTag) {
}

void UAnimationArchitectComponent::RemoveInteractionArchitectGameplayTag(const FGameplayTag& InGameplayTag) {
}

void UAnimationArchitectComponent::RemoveAnimationArchitectGameplayTag(const FGameplayTag& InGameplayTag) {
}

bool UAnimationArchitectComponent::InteractionArchitectTagContainerHasTag(const FGameplayTag& InGameplayTag) {
    return false;
}

bool UAnimationArchitectComponent::InteractionArchitectTagContainerHasAny(const FGameplayTagContainer& InGameplayTagContainer) {
    return false;
}

void UAnimationArchitectComponent::AddObjectArchitectGameplayTag(const FGameplayTag& InGameplayTag) {
}

void UAnimationArchitectComponent::AddInteractionArchitectPersistentGameplayTags(const FGameplayTagContainer& InGameplayTags) {
}

void UAnimationArchitectComponent::AddInteractionArchitectGameplayTag(const FGameplayTag& InGameplayTag) {
}

void UAnimationArchitectComponent::AddAnimationArchitectPersistentGameplayTags(const FGameplayTagContainer& InGameplayTags) {
}

void UAnimationArchitectComponent::AddAnimationArchitectGameplayTag(const FGameplayTag& InGameplayTag) {
}

UAnimationArchitectComponent::UAnimationArchitectComponent() {
    this->AssetType = ANIMATION_ARCHITECT;
    this->TempAnimationArchitectAsset = NULL;
}

