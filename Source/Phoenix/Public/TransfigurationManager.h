#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESpawnAllowedResponse.h"
#include "Engine/EngineTypes.h"
#include "CachedColovariaComponentInfo.h"
#include "CachedColovariaMaterialArray.h"
#include "EConjurationContext.h"
#include "EDisciplineType.h"
#include "PhxDbRegistryTypeManager.h"
#include "TransfigSlotPool.h"
#include "TransfigurationResource.h"
#include "TransfigurationUnlockSource.h"
#include "TransfigurationManager.generated.h"

class AActor;
class UDeferredChildActorComponent;
class UFoliageRemoverContainer;
class ULevel;
class UObject;
class UPhysicalResponseReporter;
class UTransformAllLoadController;
class UVanishmentQueue;
class UWorld;

UCLASS(Blueprintable)
class UTransfigurationManager : public UPhxDbRegistryTypeManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FCachedColovariaMaterialArray> CachedColovariaMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCachedColovariaComponentInfo> ColovariaCacheRequiredComponentQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCachedColovariaComponentInfo> ColovariaCacheAdditionalComponentQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVanishmentQueue* VanishmentQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicalResponseReporter* PhysicalResponseReporter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTransformAllLoadController* TransformAllController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFoliageRemoverContainer* FoliageRemoverContainer;
    
public:
    UTransfigurationManager();
    UFUNCTION(BlueprintCallable)
    static void VanishObject(AActor* InActor, bool bShowEffect, bool bReturnResources, bool bReturnAllRequiredResources, UClass* InPreviewActorClass, bool bDeferNotification);
    
    UFUNCTION(BlueprintCallable)
    static void UnlockTransfigurationItemsForCurriculum(TMap<EDisciplineType, int32> CurriculumYearsCompleted, bool bIncludePurchasableLocks, bool bIncludeMissionRewardLocks);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnAllColorChangeItemsBlueprint();
    
    UFUNCTION()
    AActor* Spawn(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer);
    
    UFUNCTION(BlueprintCallable)
    static void SetPowerpointSnappingEnabledBlueprint(bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetMoveablePlaceholderObjectsEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetConjurationContextBlueprint(const EConjurationContext InContext);
    
    UFUNCTION(BlueprintCallable)
    static void ResetTransfigurationObjectTransform(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDeferredChildActorSpawned(UDeferredChildActorComponent* InChildActorComponent);
    
public:
    UFUNCTION(BlueprintCallable)
    static bool IsVanishmentQueueEmpty();
    
    UFUNCTION(BlueprintCallable)
    static bool IsTransformAllQueueEmpty();
    
    UFUNCTION(BlueprintCallable)
    static bool IsSpawnQueueEmpty();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasTransfigSlotAvailableToConjureFromObjectCategory(const FName CategoryName, const EConjurationContext Context);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasEnoughConjurationBudgetToConjure(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static FTransfigurationUnlockSource GetUnlockSourceForLockID_static(const FName LockId);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetTransformationObjectList(const FName& CategoryName);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetTransformationGroups(const FName& ObjectName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetTransformationGroupForObject(const FName ObjectName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetTransformationCategory(const FName& ObjectName);
    
    UFUNCTION(BlueprintCallable)
    static void GetTransfigurationItemsFromLockID(const FName LockId, TArray<FName>& ItemNames, TArray<FName>& ItemCategories);
    
    UFUNCTION(BlueprintCallable)
    static void GetTransfigurationItemFromLockID(const FName LockId, bool& bUniqueItemFound, FName& ItemName, FName& ItemCategory);
    
    UFUNCTION(BlueprintCallable)
    static FTransfigSlotPool GetTransfigSlotPoolFromObjectCategory(const FName CategoryName, bool& bOutPoolExists);
    
    UFUNCTION(BlueprintCallable)
    static FTransfigSlotPool GetTransfigSlotPoolFromClassName(const FName ObjectClass, bool& bOutPoolExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetObjectTransfigSlotIDFromActor(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetObjectCostConjurationBudgetFromActor(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetObjectCostConjurationBudget(const FName CategoryName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetNumExpansions(const EConjurationContext InContext, int32& OutNumAvailableExpansions, int32& OutNumTotalExpansions);
    
    UFUNCTION(BlueprintCallable)
    static FName GetLockIDForObject(const FName inObjectName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetLevelConjurationBudget(const EConjurationContext Context);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EConjurationContext GetConjurationContext();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetConjurationCategoriesFromStatsCategory(const FName InStatsCategory, bool bIgnoreEmptyCategories);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetConjurationBudgetPerExpansion(const EConjurationContext InContext, float& OutMainExpansionBudget, float& OutBudgetPerUnlockableExpansion);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetConjurationBudgetCurrentlyUsed(const EConjurationContext Context);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetAllTransfigurationLocks(bool bIncludeAlreadyUnlocked);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetAllTransfigurationCategories();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool DoesTransfigurationObjectExist(int32 ObjectUID);
    
    UFUNCTION(BlueprintCallable)
    static void ColorObject(AActor* InActor, const FName InColorID, bool bShowEffect);
    
    UFUNCTION(BlueprintCallable)
    static bool BP_IsColovariaCacheRequiredQueueEmpty();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FTransfigurationResource> BP_GetResourcesRequiredForCategory(const FName CategoryName);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FTransfigurationResource> BP_GetResourcesRequired(const FName TypeID);
    
    UFUNCTION()
    ESpawnAllowedResponse AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent);
    
};

