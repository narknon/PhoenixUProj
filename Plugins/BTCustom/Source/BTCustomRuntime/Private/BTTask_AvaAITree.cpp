#include "BTTask_AvaAITree.h"

class AActor;
class UAnimInstance;
class UBlackboardComponent;

void UBTTask_AvaAITree::LeafNodeSwitcher_Implementation(const FGameplayTag LeafNodeTag) {
}

void UBTTask_AvaAITree::LeafNodeSwitched() {
}

FGameplayTag UBTTask_AvaAITree::GetLastLeafNode_Implementation() {
    return FGameplayTag{};
}

UBlackboardComponent* UBTTask_AvaAITree::GetBlackboardComponent() {
    return NULL;
}

UAnimInstance* UBTTask_AvaAITree::GetAnimInstance() {
    return NULL;
}

AActor* UBTTask_AvaAITree::GetActorOwner() {
    return NULL;
}


void UBTTask_AvaAITree::Consume_Implementation() {
}

void UBTTask_AvaAITree::BroadcastAction_Implementation(const FBTCustomAction ActionName, const EBTCustomActionType::Type ActionType, FVariantMapHandle VarMapHandle, bool bDestroyVarMap) {
}

UBTTask_AvaAITree::UBTTask_AvaAITree() {
}

