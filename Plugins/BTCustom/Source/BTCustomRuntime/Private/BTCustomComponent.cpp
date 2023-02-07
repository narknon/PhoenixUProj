#include "BTCustomComponent.h"

class AActor;

void UBTCustomComponent::OnCharacterLoadComplete(AActor* Actor) {
}

void UBTCustomComponent::LeafNodeSwitcher(const FGameplayTag InLeafNodeTag) {
}

FGameplayTag UBTCustomComponent::GetGameplayTagFromActiveLeafNode() {
    return FGameplayTag{};
}

FVariantMapHandle UBTCustomComponent::BroadcastAction_Actor(const AActor* OwnerActor, const FBTCustomAction ActionName, const TEnumAsByte<EBTCustomActionType::Type> ActionType, FVariantMapHandle VarMapHandle, bool bDestroyVarMap) {
    return FVariantMapHandle{};
}

FVariantMapHandle UBTCustomComponent::BroadcastAction(const FBTCustomAction ActionName, const TEnumAsByte<EBTCustomActionType::Type> ActionType, FVariantMapHandle VarMapHandle, bool bDestroyVarMap) {
    return FVariantMapHandle{};
}

UBTCustomComponent::UBTCustomComponent() {
    this->BehaviorTree = NULL;
    this->bManageGameLogicBoolVars = false;
    this->LastTaskNode = NULL;
    this->bLockLeafNodeSwitcher = false;
    this->bLeafNodeSwitcherQueued = false;
    this->bSubtree = false;
}

