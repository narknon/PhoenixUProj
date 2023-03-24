#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "NPC_DbIdInfo.h"
#include "ESpawnVolumeType.h"
#include "ObjectVisualizationInfo.h"
#include "SpawnerActorSpawnedSignatureDelegate.h"
#include "SpawnerFinishedSpawningSignatureDelegate.h"
#include "CustomButtonWidget.h"
#include "DbEditorButtonWidget.h"
#include "DbSingleColumnInfo.h"
#include "SpawnSelectInfo.h"
#include "PerPlatformProperties.h"
#include "Engine/TargetPoint.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "ActorDiedSignatureDelegate.h"
#include "AllEnemiesDeadEventDelegate.h"
#include "AllEnemiesSpawnedDelegate.h"
#include "ContinuousSpawnTriggerdEventDelegate.h"
#include "CreatureSpawnOverrides.h"
#include "DOVScheduleData.h"
#include "DynamicObjectGroupInfo.h"
#include "EDynamicObjectVolumeDiscoveryType.h"
#include "EDynamicObjectVolumeSpawnDistributionType.h"
#include "EncounterGroupInfo.h"
#include "Enemy_CharacterParams.h"
#include "LinkedSequenceTriggerdEventDelegate.h"
#include "ScheduledEntityCreatedDelegate.h"
#include "SpawnVolumeActivatedDelegate.h"
#include "SpawnVolumeDeactivatedDelegate.h"
#include "SpawnerActorSpawnInFinishedDelegate.h"
#include "DynamicObjectVolume.generated.h"

class AActor;
class ADynamicObjectVolume;
class APerceptionPointBox;
class ASpawnLocation;
class UEncounterSpawnComponent;
class UManualNavigationInvokerComponent;
class UMissionSpawnComponent;
class UOwnershipComponent;
class UPrimitiveComponent;
class UTextRenderComponent;

UCLASS(Blueprintable)
class PHOENIX_API ADynamicObjectVolume : public ATargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectVisualizationInfo VolumeVisualization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowActivationDistances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableAutoActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TriggerDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CullDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TriggerCullDiff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMaintainTriggerCullDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowContinuousSpawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ContinuousMaxActorCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ContinuousMinActorCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ContinuousTotalActorCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContinuousMinSpawnDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContinuousMaxSpawnDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableSpawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ScheduleTableFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDiscoveredSpawnLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerPlatformInt MaxActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnWhenActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCullWhenDeactivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFadeOutWhenCulled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlySpawnOnce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyDelayToFirstGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GroupMinDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GroupMaxDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DOVGUID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDynamicObjectVolumeSpawnDistributionType distributionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLimitUseToDiscoveredLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceDiscoveredLocsToDesiredType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo DesiredSpawnCategoryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDynamicObjectVolumeDiscoveryType DiscoveryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo NamedRestrictionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbEditorButtonWidget DBNamedRestrictionsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckRestrictionsWhileActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo MissionItemSwapID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo AssociatedLocationID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bQuestRelevantPassthrough;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ScheduleColumnFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ScheduleSearchFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ScheduleFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ScheduleFilterSelection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString WorldID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDOVScheduleData> CurrentSchedule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideWorldID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_CharacterParams EnemySpawnParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChangeSpawnedEnemyTeam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpawnedEnemyTeamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag OverrideGroupTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAttackTicketOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo AttackTicketOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo LootGroupOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo WorldRegionLevelOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo WorldAdjustmentLevelOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureSpawnOverrides CreatureSpawnOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InventoryObjectUnitCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnVolumeType SpawnVolumeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotEncounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsStaticSpawner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoAsyncDebugSpawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowIndexedSpawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGetRegionLevelOverrideFromLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpawnSelectInfo> ItemsToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FDynamicObjectGroupInfo> SpawnGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ADynamicObjectVolume*> LinkedDOVs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActivateLinksAt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TriggerLinksOnStealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterGroupInfo EncounterGroupInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbEditorButtonWidget DBAccessButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomButtonWidget SpawnerSearchButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEncounterSpawnComponent* EncounterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDissolveOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFadeOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoDeathCamOnLastDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoDeathCamBulletTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* VolumeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UManualNavigationInvokerComponent* NavInvokerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMissionSpawnComponent* MissionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwnershipComponent* OwnershipComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAllEnemiesDeadEvent OnAllEnemiesDeadEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinkedSequenceTriggerdEvent OnLinkedSequenceTriggeredEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FContinuousSpawnTriggerdEvent OnContinuousSpawnTriggeredEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAllEnemiesSpawned OnAllEnemiesSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnVolumeActivated OnSpawnVolumeActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnVolumeDeactivated OnSpawnVolumeDeactivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnerActorSpawnedSignature OnActorSpawnedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorDiedSignature OnActorDiedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnerFinishedSpawningSignature OnFinishedSpawningEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScheduledEntityCreated OnScheduledEntityCreatedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnerActorSpawnInFinished OnActerSpawnInFinishedEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextRenderComponent* DebugTextVisualizer;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isConstructed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFromNamedEncounter;
    
public:
    ADynamicObjectVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TerminateContinuousSpawning();
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnSequenceComplete();
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnLocations(TArray<ASpawnLocation*> InSpawnLocations);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnBoundsFromVectors(const FVector& Min, const FVector& Max);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnBounds(const FBox& SpawnBounds);
    
    UFUNCTION(BlueprintCallable)
    void SetEnableSpawning(bool bSpawningEnabled, bool bCullActive);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowAutoActivation(bool bAllowAutoActivate);
    
    UFUNCTION(BlueprintCallable)
    void ResetContinuousSpawning();
    
    UFUNCTION(BlueprintCallable)
    void OnFinishedSpawning(const FName& GroupName);
    
    UFUNCTION(BlueprintCallable)
    void OnActorSpawnPrep(const FString& SpawnGroup);
    
    UFUNCTION(BlueprintCallable)
    void OnActorSpawnInFinished(AActor* SpawnedActor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorSpawnFinished(AActor* SpawnedActor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorSpawnFinalize(AActor* SpawnedActor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorSpawned(AActor* SpawnedActor, const FName& GroupName);
    
    UFUNCTION(BlueprintCallable)
    void OnActorDeadEvent(AActor* DeadActor);
    
    UFUNCTION(BlueprintCallable)
    void ObjectLoaded();
    
    UFUNCTION(BlueprintCallable)
    void ObjectInfoComplete(FNPC_DbIdInfo InObjectIDs);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpawningEnabled() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsAutoActivationEnabled();
    
    UFUNCTION(BlueprintCallable)
    void InitializeTags(FGameplayTagContainer InTagsToConsider);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSpawned() const;
    
    UFUNCTION(BlueprintCallable)
    FVector GetVolumeExtents();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBox GetVolumeBounds() const;
    
    UFUNCTION(BlueprintCallable)
    FBox GetSpawnBounds();
    
    UFUNCTION(BlueprintCallable)
    int32 GetSpawnActorCount();
    
    UFUNCTION(BlueprintCallable)
    int32 GetObjectCount();
    
    UFUNCTION(BlueprintCallable)
    int32 GetKillActorCount();
    
    UFUNCTION(BlueprintCallable)
    void GetAllActiveInstances(TArray<AActor*>& OutInstances);
    
    UFUNCTION(BlueprintCallable)
    int32 GetAliveActorCount();
    
    UFUNCTION(BlueprintCallable)
    bool GetActiveInstances(const FString& InSpawnGroup, TArray<AActor*>& OutInstances);
    
    UFUNCTION(BlueprintCallable)
    int32 GetActiveActorCount();
    
    UFUNCTION(BlueprintCallable)
    void ForceSpawn();
    
    UFUNCTION(BlueprintCallable)
    void ForceDeactivate();
    
    UFUNCTION(BlueprintCallable)
    void ForceActivate();
    
    UFUNCTION(BlueprintCallable)
    void EncounterDeactivate();
    
    UFUNCTION(BlueprintCallable)
    void EncounterActivate();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoneSpawning() const;
    
    UFUNCTION(BlueprintCallable)
    void DestroySpawnedActor(AActor* actorToDestroy);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ContinuousSpawnDelayed();
    
public:
    UFUNCTION(BlueprintCallable)
    void ClearTeamShareVolumes();
    
    UFUNCTION(BlueprintCallable)
    void ClearTargetExcludeVolumes();
    
    UFUNCTION(BlueprintCallable)
    void ClearStayInVolumes();
    
    UFUNCTION(BlueprintCallable)
    void ClearPerceiveVolumes();
    
    UFUNCTION(BlueprintCallable)
    void ClearKillVolumes();
    
    UFUNCTION(BlueprintCallable)
    void ClearForcePerceiveVolumes();
    
    UFUNCTION(BlueprintCallable)
    void ClearAliveVolumes();
    
    UFUNCTION(BlueprintCallable)
    void AttachEncompassingSpawners(const FString& ObjectName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllowLinkedEvent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllowAllDeadEvent() const;
    
    UFUNCTION(BlueprintCallable)
    void AddTeamShareVolume(APerceptionPointBox* InVolume);
    
    UFUNCTION(BlueprintCallable)
    void AddTargetExcludeVolume(APerceptionPointBox* InVolume);
    
    UFUNCTION(BlueprintCallable)
    void AddStayInVolume(APerceptionPointBox* InVolume);
    
    UFUNCTION(BlueprintCallable)
    void AddPerceiveVolume(APerceptionPointBox* InVolume);
    
    UFUNCTION(BlueprintCallable)
    void AddKillVolume(APerceptionPointBox* InVolume);
    
    UFUNCTION(BlueprintCallable)
    void AddForcePerceiveVolume(APerceptionPointBox* InVolume);
    
    UFUNCTION(BlueprintCallable)
    void AddAliveVolume(APerceptionPointBox* InVolume);
    
};

