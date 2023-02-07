#include "ManagedStateComponent.h"

class AActor;
class UObject;

void UManagedStateComponent::BP_TryFinishSettingHiddenUnprioritized(AActor* Actor, UObject* Provider) {
}

void UManagedStateComponent::BP_StartSettingHiddenUnprioritized(AActor* Actor, bool IsHidden, UObject* Provider) {
}

void UManagedStateComponent::BP_StartSettingHiddenPrioritized(AActor* Actor, bool IsHidden, EManagedVisibilityPriority Priority, UObject* Provider) {
}

void UManagedStateComponent::BP_FinishSettingHiddenUnprioritized(AActor* Actor, UObject* Provider) {
}

void UManagedStateComponent::BP_FinishSettingHiddenPrioritized(AActor* Actor, EManagedVisibilityPriority Priority, UObject* Provider) {
}

UManagedStateComponent::UManagedStateComponent() {
}

