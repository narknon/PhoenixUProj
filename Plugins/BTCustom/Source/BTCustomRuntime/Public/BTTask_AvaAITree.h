#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "GameplayTagContainer.h"
#include "VariantMapHandle.h"
#include "BTAvaAITree_Interface.h"
#include "BTCustomAction.h"
#include "EBTCustomActionType.h"
#include "BTTask_AvaAITree.generated.h"

class AActor;
class UAnimInstance;
class UBlackboardComponent;

UCLASS(Abstract, Blueprintable)
class UBTTask_AvaAITree : public UBTTask_BlueprintBase, public IBTAvaAITree_Interface {
    GENERATED_BODY()
public:
    UBTTask_AvaAITree();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void LeafNodeSwitcher(const FGameplayTag LeafNodeTag);
    
    UFUNCTION(BlueprintCallable)
    void LeafNodeSwitched();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FGameplayTag GetLastLeafNode();
    
    UFUNCTION(BlueprintCallable)
    UBlackboardComponent* GetBlackboardComponent();
    
    UFUNCTION(BlueprintCallable)
    UAnimInstance* GetAnimInstance();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetActorOwner();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitTask(const AActor* OwnerActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Consume();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void BroadcastAction(const FBTCustomAction ActionName, const EBTCustomActionType::Type ActionType, FVariantMapHandle VarMapHandle, bool bDestroyVarMap);
    
    
    // Fix for true pure virtual functions not being implemented
};

