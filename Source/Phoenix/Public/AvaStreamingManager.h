#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "AsyncLoadAssetListCompleteDelegate.h"
#include "EStreamingBehaviorMode.h"
#include "EStreamingBehaviorTactic.h"
#include "HighPriorityStreamingCompleteDelegate.h"
#include "StreamingBehaviorChangeDelegate.h"
#include "AvaStreamingManager.generated.h"

class AActor;
class APostProcessVolumeWithBlendDomain;
class UAvaStreamingManager;
class ULevel;
class ULevelStreaming;
class ULevelStreamingLatencyProfiler;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Blueprintable)
class PHOENIX_API UAvaStreamingManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHighPriorityStreamingComplete OnHighPriorityStreamingComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAsyncLoadAssetListComplete OnAsyncLoadAssetListComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStreamingBehaviorChange OnStreamingBehaviorAboutToChangeEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStreamingBehaviorChange OnStreamingBehaviorHasChangedEvent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULevel*> LevelsToKeep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelStreamingLatencyProfiler* LevelStreamingLatencyProfiler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APostProcessVolumeWithBlendDomain* LowEndFogCullingVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* LowEndFogCullingMaterialInstanceDynamic;
    
public:
    UAvaStreamingManager();
    UFUNCTION(BlueprintCallable)
    void UpdateOverlaps();
    
    UFUNCTION(BlueprintCallable)
    bool UnregisterInterestPointActor(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static void UnloadLevelInstance(ULevelStreaming* InLevel);
    
    UFUNCTION(BlueprintCallable)
    void UnloadAllButCurrentLevel();
    
    UFUNCTION(BlueprintCallable)
    void SuppressPauseStreamingAutoReset(bool bSuppress);
    
    UFUNCTION(BlueprintCallable)
    void SetStreamingBehaviorMode(EStreamingBehaviorMode BehaviorMode);
    
    UFUNCTION(BlueprintCallable)
    void SetLowEndFog(APostProcessVolumeWithBlendDomain* LowEndFog, UMaterialInterface* LowEndFogMaterialBase);
    
    UFUNCTION(BlueprintCallable)
    void ResumeStreaming(bool bForceImmediate, bool bResumeTileStreaming);
    
    UFUNCTION(BlueprintCallable)
    bool RegisterInterestPointActor(AActor* InActor, float InAdditionalRadius, bool InAffectsInteriors, bool InAffectsTileRegionVolumes);
    
    UFUNCTION(BlueprintCallable)
    void PreventInteriorLoads(bool bPrevent);
    
    UFUNCTION(BlueprintCallable)
    void PauseStreaming(bool bWorldTilesOnly);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnLoadScreenDismissed();
    
public:
    UFUNCTION(BlueprintCallable)
    void LowerCurtainUntilStreamingComplete();
    
    UFUNCTION(BlueprintCallable)
    void LoadGlobalLevels();
    
    UFUNCTION(BlueprintCallable)
    bool IsTileRenderingEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool IsStreamingPaused();
    
    UFUNCTION(BlueprintCallable)
    bool IsStreamingCompleteFullCycle(bool bCheckOnlyLOD0, bool bUseDelay);
    
    UFUNCTION(BlueprintCallable)
    bool IsStreamingCompleteAtLocationFullCycle(const FVector& InQueryPoint, bool InQueryWorldTiles, bool InUseSlowAccurateCheck, bool InConsiderFutureRequestAtLocation);
    
    UFUNCTION(BlueprintCallable)
    bool IsStreamingCompleteAtLocation(const FVector& InQueryPoint, bool InQueryWorldTiles, bool InUseSlowAccurateCheck, bool InConsiderFutureRequestAtLocation, int32 MinPriorityToCheck, bool bCheckTextureAndMeshStreaming);
    
    UFUNCTION(BlueprintCallable)
    bool IsStreamingComplete(bool bCheckOnlyLOD0, bool bUseDelay, bool bConsiderUpdatePending, bool bConsiderUnloads);
    
    UFUNCTION(BlueprintCallable)
    void InvalidateStreamingComplete(bool InRequireFullUpdates);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EStreamingBehaviorTactic GetStreamingBehaviorTactic() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EStreamingBehaviorMode GetStreamingBehaviorMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAvaStreamingManager* GetPure();
    
    UFUNCTION(BlueprintCallable)
    static UAvaStreamingManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void FlushStreaming();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void AsyncLoadAssetList(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UObject>>& AssetsToStream, int32& UniqueId);
    
};

