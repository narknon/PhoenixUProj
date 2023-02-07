#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "GameplayTagContainer.h"
#include "VariantMapHandle.h"
#include "BTCustomAction.h"
#include "EBTCustomActionType.h"
#include "LeafNodeSwitchedDelegate.h"
#include "NameToType.h"
#include "BTCustomComponent.generated.h"

class AActor;
class UBTTaskNode;
class UBehaviorTree;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class BTCUSTOMRUNTIME_API UBTCustomComponent : public UBehaviorTreeComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* BehaviorTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString GameplayTagPrefix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bManageGameLogicBoolVars;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLeafNodeSwitched LeafNodeSwitchedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag LeafNodeTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag LastLeafNodeTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UBTTaskNode* LastTaskNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bLockLeafNodeSwitcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bLeafNodeSwitcherQueued;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTag LeafNodeTagDuringLock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSubtree;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FNameToType> ActionNameToTypeMap;
    
public:
    UBTCustomComponent();
    UFUNCTION(BlueprintCallable)
    void OnCharacterLoadComplete(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void LeafNodeSwitcher(const FGameplayTag InLeafNodeTag);
    
    UFUNCTION(BlueprintCallable)
    FGameplayTag GetGameplayTagFromActiveLeafNode();
    
    UFUNCTION(BlueprintCallable)
    static FVariantMapHandle BroadcastAction_Actor(const AActor* OwnerActor, const FBTCustomAction ActionName, const TEnumAsByte<EBTCustomActionType::Type> ActionType, FVariantMapHandle VarMapHandle, bool bDestroyVarMap);
    
    UFUNCTION(BlueprintCallable)
    FVariantMapHandle BroadcastAction(const FBTCustomAction ActionName, const TEnumAsByte<EBTCustomActionType::Type> ActionType, FVariantMapHandle VarMapHandle, bool bDestroyVarMap);
    
};

