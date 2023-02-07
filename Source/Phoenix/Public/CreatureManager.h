#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ESpawnAllowedResponse.h"
#include "Engine/EngineTypes.h"
#include "GameplayProperty_Float.h"
#include "Moddable.h"
#include "ECreatureInteraction.h"
#include "PhxDbRegistryTypeManager.h"
#include "CreatureManager.generated.h"

class AActor;
class ABiped_Player;
class ACreaturePen;
class UCreatureDefinition;
class UCreatureFeedingStationState;
class UCreatureManager;
class UCreatureScalabilityManager;
class UCreatureState;
class ULevel;
class UObject;
class UWorld;

UCLASS(Blueprintable)
class PHOENIX_API UCreatureManager : public UPhxDbRegistryTypeManager, public IModdable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, UCreatureState*> CreatureStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UCreatureDefinition*> CreatureDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureScalabilityManager* CreatureScalabilityManager;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, UCreatureFeedingStationState*> FeedingStationStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float ByproductProductionTimeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float RareVariationSpawnMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float BreedRareVariationChanceMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> PreLoadedAssets;
    
public:
    UCreatureManager();
    UFUNCTION(BlueprintCallable)
    void UpdateCreatureName(UCreatureState* CreatureState, const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockAllCreatureToys();
    
    UFUNCTION(BlueprintCallable)
    void TeleportCreatureActorsToPen(ACreaturePen* PenActor);
    
    UFUNCTION(BlueprintCallable)
    bool SummonCreature(UCreatureState* InCreatureState, const ABiped_Player* InSummoningPlayer, FString& OutErrorKey);
    
    UFUNCTION()
    AActor* SpawnShell(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel);
    
    UFUNCTION()
    AActor* Spawn(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UCreatureState*> SortCreaturesByHappiness(TArray<UCreatureState*> Creatures);
    
    UFUNCTION(BlueprintCallable)
    void SetCreatureInspectedByPlayerUID(const int32 InCreatureUID);
    
    UFUNCTION(BlueprintCallable)
    void ScrapCreature(const int32 InCreatureUID);
    
    UFUNCTION()
    void SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID);
    
    UFUNCTION(BlueprintCallable)
    void SaveCreatureUID(const FString& InSaveID, int32 InUIDToSave);
    
    UFUNCTION()
    void RestoreData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSavedCreature(const FString& InSaveID);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCreatureFromInventory(const int32 InCreatureUID, bool bInRemovedByMission, bool bInSuppressHUDNotification);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseCreatureToNurturingSpace(const int32 InCreatureUID, const FName InNurturingSpaceID, const ABiped_Player* InReleasingPlayer);
    
    UFUNCTION(BlueprintCallable)
    UCreatureState* RegisterCapturedCreature(const FName InTypeID, const bool bInIsMale, const FName InColorVariation);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
    UFUNCTION(BlueprintCallable)
    void OnCreatureInteractedWith(AActor* InCreature, const ECreatureInteraction InInteractionType, const FName InKnowledgeGainedActor, const FName InActorInteractedWithTypeID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool IsPenOccupied(const int32 PenUID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCreatureInInventory(const int32 InCreatureUID) const;
    
    UFUNCTION(BlueprintCallable)
    bool HasCapturedCreatureInventoryEnoughSpace();
    
    UFUNCTION(BlueprintCallable)
    bool GetShellSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath);
    
    UFUNCTION(BlueprintCallable)
    UCreatureState* GetSavedCreature(const FString& InSaveID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRandomCreatureUIDFromInventory(const FName InCreatureTypeID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UCreatureState* GetOffspringCreatureInPen(const int32 PenUID) const;
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    int32 GetNumberOfBreedableCreaturesOfTypeInNurtureSpace(FName TypeID, FName NurturingSpaceID, bool bIncludeMale, bool bIncludeFemale) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UCreatureState* GetMotherCreatureInPen(const int32 PenUID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    int32 GetMaxNumSpeciesInNurturingSpace(const FName InNurturingSpaceID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    int32 GetMaxNumCreaturesInNurturingSpace(const FName InNurturingSpaceID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    int32 GetMaxCreatureTierInNurturingSpace(const FName InNurturingSpaceID) const;
    
    UFUNCTION()
    float GetHealth(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<UCreatureState*> GetHappyCreaturesInSanctuary() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDeathTimeoutPercentage(const FString& InCreatureID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    FName GetCurrentCreatureNurturingSpaceID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCreatureUIDFromVariationName(const FName InUIDName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCreatureInspectedByPlayerUID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCreatureEconomyValue(FName InCreatureUID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<UCreatureState*> GetCapturedCreatureStatesOfType(const FName InAdultTypeID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<int32> GetCapturedCreaturesOfType(const FName InTypeID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCapturedCreatureInventorySize() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetByproductProductionTimeModifier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TMap<FName, int32> GetAllCreatureSpeciesInNurturingSpace(const FName InNurturingSpaceID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<UCreatureState*> GetAllCreaturesInNurturingSpace(const FName InNurturingSpaceID, bool bIncludeUnbornCreatures, bool bIncludeEggs, bool bSortByTimeInNurturingSpace) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<UCreatureDefinition*> GetAllCreatureDefinitions() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void GetAllCreatureByproducts(int32 AmountToGrant);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<FName> GetAllColorVariationsForCreature(const FName InTypeID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UCreatureManager* Get();
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    AActor* FindCreatureActorByUID(const int32 InCreatureUID) const;
    
private:
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureStateBackup();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureSpawnWildMany(FName TypeID, int32 Count);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureSpawnWild(FName TypeID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureSpawnMany(FName TypeID, int32 Count);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureSpawn(FName TypeID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureSimulateCapturePregnant(FName TypeID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureSimulateCapture(FName TypeID, bool bIsMale, FName ColorVariation);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureSimulateBreeding(FName TypeID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureResetAllNeeds();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureRemoveAll();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureRegisterAllCreaturesInLevel();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreaturePetNearest();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureMeetAllNeeds();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureFeedNearest();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureClearCapturedInventory();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureAdvancedSpawn(FName TypeID, bool bIsMale, FName ColorVariation, float ScaleVariation, const FString& CreatureName, int32 BreedingGeneration);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureAddToBiomeIfNeeded(FName InCreatureType, FName InBiomeID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureAddNamedToInventory(FName NamedCreatureID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreatureAddHappinessToAll(float Amount);
    
    UFUNCTION(BlueprintCallable)
    void CaptureCreature(const int32 InCreatureUID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool CanReleaseCreatureToNurturingSpace(UCreatureState* InCreatureState, const FName InNurturingSpaceID, const ABiped_Player* InReleasingPlayer, FString& OutErrorKey) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool CanCreaturePairBreed(const int32 InCreatureA, const int32 InCreatureB, FString& CreatureAErrorMsg, FString& CreatureBErrorMsg) const;
    
    UFUNCTION(BlueprintCallable)
    void BreedCreatures(UCreatureState* MotherState, UCreatureState* FatherState, ACreaturePen* CreaturePen);
    
    UFUNCTION(BlueprintCallable)
    void BP_ScrapCreatureByFName(const FName InCreatureUID);
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UCreatureState* BP_GetCreatureStateByUID(const int32 InCreatureUID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UCreatureState* BP_GetCreatureStateByFName(const FName InCreatureUID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UCreatureState* BP_GetCreatureStateByActor(AActor* InCreature) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UCreatureDefinition* BP_GetCreatureDefinitionForActor(AActor* InCreature) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UCreatureDefinition* BP_GetCreatureDefinitionByType(const FName InTypeID) const;
    
public:
    UFUNCTION(BlueprintCallable)
    void BeginCreatureGrowUp(AActor* InCreature);
    
    UFUNCTION()
    ESpawnAllowedResponse AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent);
    
    
    // Fix for true pure virtual functions not being implemented
};

