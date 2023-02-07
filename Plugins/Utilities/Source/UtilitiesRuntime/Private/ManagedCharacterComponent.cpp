#include "ManagedCharacterComponent.h"

class UObject;

void UManagedCharacterComponent::StartSettingMovementMode(EMovementMode InMovementMode, EManagedMovementModePriority Priority, const UObject* Provider) {
}

void UManagedCharacterComponent::SetStartFacialEmotionWithTags(EFacialEmotion Emotion, UObject* Provider, float Transition, EManagedFacialEmotionPriority ManagedFacialEmotionPriority, FGameplayTagContainer AnimTags) {
}

void UManagedCharacterComponent::SetStartFacialEmotion(EFacialEmotion Emotion, UObject* Provider, float Transition, EManagedFacialEmotionPriority ManagedFacialEmotionPriority) {
}

void UManagedCharacterComponent::SetFinishFacialEmotion(UObject* Provider, EManagedFacialEmotionPriority ManagedFacialEmotionPriority) {
}

void UManagedCharacterComponent::SetDefaultFacialEmotion(EFacialEmotion Emotion, float Transition) {
}

void UManagedCharacterComponent::FinishSettingMovementMode(EManagedMovementModePriority Priority, const UObject* Provider) {
}

UManagedCharacterComponent::UManagedCharacterComponent() {
}

