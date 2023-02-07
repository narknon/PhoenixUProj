#pragma once
#include "CoreMinimal.h"
#include "ESpawnVolumeType.h"
#include "ObjectVisualizationInfo.h"
#include "CustomButtonWidget.h"
#include "DbEditorButtonWidget.h"
#include "DbSingleColumnInfo.h"
#include "Engine/TargetPoint.h"
#include "GameplayTagContainer.h"
#include "AllEncounterEnemiesDeadEventDelegate.h"
#include "AllEncounterEnemiesSpawnedDelegate.h"
#include "EncounterVolumeActivatedDelegate.h"
#include "EncounterVolumeDeactivatedDelegate.h"
#include "EncounterVolume.generated.h"

class AActor;
class ADynamicObjectVolume;
class AEnemy_PerceptionPoint;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class AEncounterVolume : public ATargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectVisualizationInfo VolumeVisualization;
    
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
    bool bAutoGeneratePerception;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag EncounterTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString NameEncounterDataString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbEditorButtonWidget DBAccessButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbEditorButtonWidget DBInclusionButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbEditorButtonWidget DBExclusionButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbEditorButtonWidget DBDOVAccessButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString GuidString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnVolumeType SpawnVolumeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ADynamicObjectVolume*> SpawnZones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomButtonWidget SpawnerSearchButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo NamedRestrictionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceOverrideRestriction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCreatorEncounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowDataWrite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbEditorButtonWidget DBNamedRestrictionsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomButtonWidget ReportButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumIterationsPerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StartPlayerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EndPlayerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLocationTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* VolumeComponent;
    
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
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAllEncounterEnemiesDeadEvent OnAllEnemiesDeadEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAllEncounterEnemiesSpawned OnAllEnemiesSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterVolumeActivated OnEncounterVolumeActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterVolumeDeactivated OnEncounterVolumeDeactivated;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNamedEncounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AEnemy_PerceptionPoint* pEnemyPerception;
    
public:
    AEncounterVolume();
    UFUNCTION(BlueprintCallable)
    void SetEncounterActor(ADynamicObjectVolume* InActor);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowAutoActivation(bool bAllowAutoActivate);
    
    UFUNCTION(BlueprintCallable)
    void ProcessZoneData(const FString& ObjectName);
    
    UFUNCTION(BlueprintCallable)
    void ProcessSpawnerSearch(const FString& ObjectName);
    
    UFUNCTION(BlueprintCallable)
    void ProcessEncounterReport(const FString& ObjectName);
    
    UFUNCTION(BlueprintCallable)
    bool IsVolumeActive();
    
    UFUNCTION(BlueprintCallable)
    bool HasSpawned();
    
    UFUNCTION(BlueprintCallable)
    int32 GetSpawnActorCount();
    
    UFUNCTION(BlueprintCallable)
    TArray<AActor*> GetAllActiveSpawnedInstances();
    
    UFUNCTION(BlueprintCallable)
    int32 GetAliveActorCount();
    
    UFUNCTION(BlueprintCallable)
    int32 GetActiveActorCount();
    
    UFUNCTION(BlueprintCallable)
    void ForceDeactivate();
    
    UFUNCTION(BlueprintCallable)
    void ForceActivate();
    
    UFUNCTION(BlueprintCallable)
    bool DoneSpawning();
    
};

