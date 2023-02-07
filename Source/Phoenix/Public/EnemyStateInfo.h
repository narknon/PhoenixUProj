#pragma once
#include "CoreMinimal.h"
#include "CharacterStateInfo.h"
#include "EnemyStateInfo.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class UEnemyStateInfo : public UCharacterStateInfo {
    GENERATED_BODY()
public:
    UEnemyStateInfo();
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateMass();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetPullsAggroAmount(float InAmount);
    
    UFUNCTION(BlueprintCallable)
    void SetPullsAggro(bool bInPullsAggro);
    
    UFUNCTION(BlueprintCallable)
    void SetInvulnerableToStaticObjects(bool bInInvulnerable);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreActorHitFrom(AActor* IgnoreActor);
    
    UFUNCTION(BlueprintCallable)
    void RemoveIgnoreActorHitFrom();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PullsAggro() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPullAggroAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UClass*> GetFriendlyFireTypeList() const;
    
};

