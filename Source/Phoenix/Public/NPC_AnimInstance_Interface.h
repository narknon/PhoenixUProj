#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EEnemyAIAnimState.h"
#include "EEnemy_Ability.h"
#include "EEnemy_AnimMainState.h"
#include "NPC_AnimInstance_Interface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UNPC_AnimInstance_Interface : public UInterface {
    GENERATED_BODY()
};

class INPC_AnimInstance_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetState(const EEnemyAIAnimState& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMainState(const EEnemy_AnimMainState& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAbilityActive(EEnemy_Ability InAbility, bool bUse);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleHeadTracking(AActor* Owner);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    EEnemyAIAnimState GetState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    EEnemy_AnimMainState GetMainState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    EEnemy_Ability GetActiveAbility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetAbilityActive(EEnemy_Ability InAbility) const;
    
};

