#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventoryAbilityManager.generated.h"

class AActor;

UCLASS(Blueprintable)
class UInventoryAbilityManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName PolyJuiceCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentEffectiveness;
    
public:
    UInventoryAbilityManager();
    UFUNCTION(BlueprintCallable)
    void SetPolyJuiceCharacter(FName PolyJuiceCharacterName);
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeLoaded();
    
    UFUNCTION(BlueprintCallable)
    FName GetPolyJuiceCharacter();
    
    UFUNCTION(BlueprintCallable)
    float GetItemeffectivenessMultiplier(AActor* OwnerActor, FName ItemName);
    
    UFUNCTION(BlueprintCallable)
    float GetCurrentEffectivenessMultiplier();
    
    UFUNCTION(BlueprintCallable)
    void AddWellRestedToPlayer();
    
    UFUNCTION(BlueprintCallable)
    void AddWellFedToPlayer();
    
    UFUNCTION(BlueprintCallable)
    void AddSocialNotorietyToPlayer();
    
    UFUNCTION(BlueprintCallable)
    void AddSocialInfamousToPlayer();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddPermenantWellRestedToPlayer();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddPermenantWellFedToPlayer();
    
    UFUNCTION(BlueprintCallable)
    void AddOrRefreshAbility(AActor* OwnerActor, FName ItemName, FName Name);
    
    UFUNCTION(BlueprintCallable)
    void AddHouseLeaderToPlayer();
    
};

