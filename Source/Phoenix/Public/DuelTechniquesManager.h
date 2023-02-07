#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DuelTechniqueEncounterState.h"
#include "DuelTechniquesManager.generated.h"

class UDuelTechniqueStat;

UCLASS(Blueprintable)
class PHOENIX_API UDuelTechniquesManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> CombatVolumeGroupDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FDuelTechniqueEncounterState> DuelTechniquesEncounterDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UDuelTechniqueStat*> DuelTechniqueIDToStats;
    
public:
    UDuelTechniquesManager();
private:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
};

