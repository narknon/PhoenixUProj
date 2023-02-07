#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlueprintBase.h"
#include "GameplayTagContainer.h"
#include "VariantMapHandle.h"
#include "BTAvaAITree_Interface.h"
#include "BTCustomAction.h"
#include "EBTCustomActionType.h"
#include "BTService_AvaAITree.generated.h"

class AActor;
class UAnimInstance;
class UBlackboardComponent;

UCLASS(Abstract, Blueprintable)
class BTCUSTOMRUNTIME_API UBTService_AvaAITree : public UBTService_BlueprintBase, public IBTAvaAITree_Interface {
    GENERATED_BODY()
public:
    UBTService_AvaAITree();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServiceEnd(const AActor* OwnerActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServiceBegin(const AActor* OwnerActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void LeafNodeSwitcher(const FGameplayTag InLeafNodeTag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FGameplayTag GetLastLeafNode();
    
    UFUNCTION(BlueprintCallable)
    UBlackboardComponent* GetBlackboardComponent();
    
    UFUNCTION(BlueprintCallable)
    UAnimInstance* GetAnimInstance();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetActorOwner();
    
    UFUNCTION(BlueprintCallable)
    FGameplayTag GetActiveLeafNodeTag();
    
    UFUNCTION(BlueprintCallable)
    FName GetActiveLeafNodeName();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Consume();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void BroadcastAction(const FBTCustomAction ActionName, const EBTCustomActionType::Type ActionType, FVariantMapHandle VarMapHandle, bool bDestroyVarMap);
    
    
    // Fix for true pure virtual functions not being implemented
};

