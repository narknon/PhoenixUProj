#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EEnemyAIDodgeState.h"
#include "Enemy_AnimInstance_Interface.h"
#include "NPC_AnimInstance.h"
#include "Enemy_AnimInstance.generated.h"

class UEnemyAISpawnData;

UCLASS(Blueprintable, NonTransient)
class UEnemy_AnimInstance : public UNPC_AnimInstance, public IEnemy_AnimInstance_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyAIDodgeState DodgeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AttackTypeTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 WeaponActivateStoredIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyAISpawnData* SpawnDataPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnGround;
    
    UEnemy_AnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetSpawnData(UEnemyAISpawnData* InSpawnDataPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAttackTypeTag(FGameplayTag InType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAnimDodgeState(EEnemyAIDodgeState InDodgeState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    UEnemyAISpawnData* GetSpawnData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FGameplayTag GetAttackTypeTag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    EEnemyAIDodgeState GetAnimDodgeState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanExitAttackLoop() const;
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_ImpulseToTarget(float ActiveFrames, float DistFromTarget, float MaxTravelDist);
    
    
    // Fix for true pure virtual functions not being implemented
};

