#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESpawnAllowedResponse.h"
#include "Engine/EngineTypes.h"
#include "GameplayProperty_Float.h"
#include "Moddable.h"
#include "FertilizerEffect.h"
#include "PhxDbRegistryTypeManager.h"
#include "PlantDefinition.h"
#include "SeedInfo.h"
#include "HerbPlotManager.generated.h"

class AActor;
class AHerbPlot;
class UHerbPlotManager;
class UHerbPlotState;
class ULevel;
class UObject;
class UWorld;

UCLASS(Blueprintable)
class UHerbPlotManager : public UPhxDbRegistryTypeManager, public IModdable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, UHerbPlotState*> HerbPlotStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float GrowthTimeMultiplier;
    
public:
    UHerbPlotManager();
    UFUNCTION()
    AActor* SpawnShell(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel);
    
    UFUNCTION()
    AActor* Spawn(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer);
    
    UFUNCTION()
    void SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID);
    
    UFUNCTION(BlueprintCallable)
    void ResetHarvestPlantCounts();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
public:
    UFUNCTION(BlueprintCallable)
    static void GetOwnedSeeds(TArray<FSeedInfo>& OwnedSeeds);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGrowthTimeMultiplier() const;
    
    UFUNCTION(BlueprintCallable)
    static FFertilizerEffect GetFertilizerEffectStatic(FName FertilizerID);
    
private:
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetAllPlantNames();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void GetAllHerbologySeeds();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GetAllHerbologyByproducts(int32 AmountToGrant);
    
    UFUNCTION(BlueprintCallable)
    static bool DoesSeedFitInPlot(const FSeedInfo& SeedInfo, AHerbPlot* HerbPlot);
    
    UFUNCTION(BlueprintCallable)
    FPlantDefinition BP_GetPlantDefinition(FName PlantID, bool& DefinitionFound);
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UHerbPlotManager* BP_Get();
    
public:
    UFUNCTION()
    ESpawnAllowedResponse AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent);
    
    
    // Fix for true pure virtual functions not being implemented
};

