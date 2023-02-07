#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "ERegionType.h"
#include "LevelStreamingAnyLoadedStatusDelegate.h"
#include "LandscapeManager.generated.h"

class ULandscapeManager;
class ULevel;
class ULevelStreaming;
class URegionData;
class URegionSplineContainer;

UCLASS(Blueprintable)
class ULandscapeManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelStreamingAnyLoadedStatus OnAnyLevelLoaded;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URegionData*> OverlandRegionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERegionType, URegionSplineContainer*> MapRegions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERegionType, URegionSplineContainer*> LevelRegions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERegionType, URegionSplineContainer*> SubLevelRegions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERegionType, URegionSplineContainer*> InnerLevelRegions;
    
public:
    ULandscapeManager();
    UFUNCTION(BlueprintCallable)
    void RemoveCriticalLevel(ULevelStreaming* InLevel);
    
    UFUNCTION(BlueprintCallable)
    void PrepareMapCapture();
    
    UFUNCTION(BlueprintCallable)
    void OnShow();
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoad();
    
    UFUNCTION(BlueprintCallable)
    void OnLoad();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToSave();
    
    UFUNCTION(BlueprintCallable)
    bool IsReadyForMapCapture();
    
    UFUNCTION(BlueprintCallable)
    bool IsLocationExploredRegion(FVector Location, float MapScale);
    
    UFUNCTION(BlueprintCallable)
    bool IsLocationExploredFog(FVector Location, float MapScale);
    
    UFUNCTION(BlueprintCallable)
    bool IsLoadedLevelCritical(ULevel* InLevel);
    
    UFUNCTION(BlueprintCallable)
    bool IsLevelCritical(ULevelStreaming* InLevel);
    
    UFUNCTION(BlueprintCallable)
    int32 GetNumActiveLevelLoads(bool InCriticalOnly);
    
    UFUNCTION(BlueprintCallable)
    FBox GetLandscapeWorldBounds();
    
    UFUNCTION(BlueprintCallable)
    static ULandscapeManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void ForceLandscapeLODs();
    
    UFUNCTION(BlueprintCallable)
    void DoMapCapture();
    
    UFUNCTION(BlueprintCallable)
    void ClearCriticalLevels();
    
    UFUNCTION(BlueprintCallable)
    void CleanupMapCapture();
    
    UFUNCTION(BlueprintCallable)
    void AddCriticalLevel(ULevelStreaming* InLevel);
    
};

