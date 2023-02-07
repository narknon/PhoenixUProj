#pragma once
#include "CoreMinimal.h"
#include "InputContextWithType.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "VariantMapHandle.h"
#include "BTCustomAction.h"
#include "EBTCustomActionType.h"
#include "BTAvaAITree_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UBTAvaAITree_Interface : public UInterface {
    GENERATED_BODY()
};

class IBTAvaAITree_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetManagedContext(const FInputContextWithType InContext, const bool bFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LeafNodeSwitcher(const FGameplayTag InLeafNodeTag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetManagedContext(const FInputContextWithType InContext);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FGameplayTag GetLastLeafNode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Consume();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BroadcastAction(const FBTCustomAction ActionName, const EBTCustomActionType::Type ActionType, FVariantMapHandle VarMapHandle, bool bDestroyVarMap);
    
};

