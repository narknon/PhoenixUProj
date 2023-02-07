#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "EEnemyAIAnimTransState.h"
#include "Enemy_AnimInstance_Interface.generated.h"

class UEnemyAISpawnData;

UINTERFACE(Blueprintable, MinimalAPI)
class UEnemy_AnimInstance_Interface : public UInterface {
    GENERATED_BODY()
};

class IEnemy_AnimInstance_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTransState(const TEnumAsByte<EEnemyAIAnimTransState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSpawnData(UEnemyAISpawnData* InSpawnDataPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAttackTypeTag(FGameplayTag InType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    EEnemyAIAnimTransState::Type GetTransState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UEnemyAISpawnData* GetSpawnData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FGameplayTag GetAttackTypeTag() const;
    
};

