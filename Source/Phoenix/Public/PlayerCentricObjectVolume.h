#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ESpawnVolumeType.h"
#include "ObjectVisualizationInfo.h"
#include "SpawnerActorSpawnedSignatureDelegate.h"
#include "SpawnerFinishedSpawningSignatureDelegate.h"
#include "SpawnSelectInfo.h"
#include "Engine/TargetPoint.h"
#include "AllEnemiesDeadEventDelegate.h"
#include "AllEnemiesSpawnedDelegate.h"
#include "DynamicObjectGroupInfo.h"
#include "SpawnVolumeActivatedDelegate.h"
#include "SpawnVolumeDeactivatedDelegate.h"
#include "PlayerCentricObjectVolume.generated.h"

class AActor;
class UManualNavigationInvokerComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class APlayerCentricObjectVolume : public ATargetPoint {
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
    bool bEnableSpawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtentsPercentageForDefaultSpawnLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RespawnDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerOffsetForDefaultSpawnLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnVolumeType SpawnVolumeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpawnSelectInfo> ItemsToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FDynamicObjectGroupInfo> SpawnGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* VolumeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UManualNavigationInvokerComponent* NavInvokerComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAllEnemiesDeadEvent OnAllEnemiesDeadEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAllEnemiesSpawned OnAllEnemiesSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnVolumeActivated OnSpawnVolumeActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnVolumeDeactivated OnSpawnVolumeDeactivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnerActorSpawnedSignature OnActorSpawnedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnerFinishedSpawningSignature OnFinishedSpawningEvent;
    
    APlayerCentricObjectVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetSpawnBoundsFromVectors(const FVector& Min, const FVector& Max);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnBounds(const FBox& SpawnBounds);
    
    UFUNCTION(BlueprintCallable)
    void SetEnableSpawning(bool bSpawningEnabled, bool bCullActive);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowAutoActivation(bool bAllowAutoActivate);
    
    UFUNCTION(BlueprintCallable)
    void OnFinishedSpawning(const FName& GroupName);
    
    UFUNCTION(BlueprintCallable)
    void OnActorSpawned(AActor* SpawnedActor, const FName& GroupName);
    
    UFUNCTION(BlueprintCallable)
    void ObjectLoaded();
    
    UFUNCTION(BlueprintCallable)
    bool HasSpawned();
    
    UFUNCTION(BlueprintCallable)
    FVector GetVolumeExtents();
    
    UFUNCTION(BlueprintCallable)
    FBox GetVolumeBounds();
    
    UFUNCTION(BlueprintCallable)
    FBox GetSpawnBounds();
    
    UFUNCTION(BlueprintCallable)
    int32 GetSpawnActorCount();
    
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

