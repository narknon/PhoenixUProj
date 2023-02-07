#include "BTService_AvaAITree.h"

class AActor;
class UAnimInstance;
class UBlackboardComponent;



void UBTService_AvaAITree::LeafNodeSwitcher_Implementation(const FGameplayTag InLeafNodeTag) {
}

FGameplayTag UBTService_AvaAITree::GetLastLeafNode_Implementation() {
    return FGameplayTag{};
}

UBlackboardComponent* UBTService_AvaAITree::GetBlackboardComponent() {
    return NULL;
}

UAnimInstance* UBTService_AvaAITree::GetAnimInstance() {
    return NULL;
}

AActor* UBTService_AvaAITree::GetActorOwner() {
    return NULL;
}

FGameplayTag UBTService_AvaAITree::GetActiveLeafNodeTag() {
    return FGameplayTag{};
}

FName UBTService_AvaAITree::GetActiveLeafNodeName() {
    return NAME_None;
}

void UBTService_AvaAITree::Consume_Implementation() {
}

void UBTService_AvaAITree::BroadcastAction_Implementation(const FBTCustomAction ActionName, const EBTCustomActionType::Type ActionType, FVariantMapHandle VarMapHandle, bool bDestroyVarMap) {
}

UBTService_AvaAITree::UBTService_AvaAITree() {
}

