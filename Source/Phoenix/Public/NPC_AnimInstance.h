#pragma once
#include "CoreMinimal.h"
#include "Ambulatory_AnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EEnemyAIAnimState.h"
#include "EEnemy_Ability.h"
#include "EEnemy_AnimMainState.h"
#include "ENPC_SpawnState.h"
#include "NPC_AnimInstance_Interface.h"
#include "NPC_AnimInstance.generated.h"

class AActor;
class AAmbulatory_Character;


UCLASS(Blueprintable, NonTransient)
class UNPC_AnimInstance : public UAmbulatory_AnimInstance, public INPC_AnimInstance_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyAIAnimState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyAIAnimState LastState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AnimMainState MainState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AnimMainState LastMainState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LookAtAlpha;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAnimationAsset> ParryAnimAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParryAnimTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bParryAnimTimeSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_SpawnState SpawnState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_Ability ActiveAbility;
    
    UNPC_AnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetState(const EEnemyAIAnimState& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetMainState(const EEnemy_AnimMainState& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAnimSpawnState(ENPC_SpawnState InAnimSpawnState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAbilityActive(EEnemy_Ability InAbility, bool bUse);
    
    UFUNCTION(BlueprintCallable)
    void OnTeleport(AAmbulatory_Character* Character, FVector AmountDisplaced, FRotator AmountRotated);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleHeadTracking(AActor* Owner);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    EEnemyAIAnimState GetState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    EEnemy_AnimMainState GetMainState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    ENPC_SpawnState GetAnimSpawnState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    EEnemy_Ability GetActiveAbility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool GetAbilityActive(EEnemy_Ability InAbility) const;
    
    
    // Fix for true pure virtual functions not being implemented
};

