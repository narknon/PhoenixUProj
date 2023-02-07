#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EncounterTracker.generated.h"

class AActor;
class ACombatVolume;
class UCombatVolumeGroup;
class UDuelTechniquesController;

UCLASS(Blueprintable)
class UEncounterTracker : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<ACombatVolume>> m_combatVolumesPlayerOverlaps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCombatVolumeGroup* m_currentCombatVolumeGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDuelTechniquesController* DuelTechniquesController;
    
public:
    UEncounterTracker();
private:
    UFUNCTION(BlueprintCallable)
    void TryEndEncounter();
    
public:
    UFUNCTION(BlueprintCallable)
    static bool StartEncounterForPlayersCombatVolume();
    
private:
    UFUNCTION(BlueprintCallable)
    void ResetTryEndEncounterTimer();
    
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
    UFUNCTION(BlueprintCallable)
    void OnCombatVolumeDeath(ACombatVolume* CombatVolume, AActor* DeadActor);
    
    UFUNCTION(BlueprintCallable)
    void OnCombatVolumeActorSpawned(ACombatVolume* CombatVolume, AActor* SpawnedActor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerInAnEncounter();
    
};

