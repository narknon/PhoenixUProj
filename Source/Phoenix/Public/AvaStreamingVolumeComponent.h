#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AvaStreamingLevelVolumeComponentBase.h"
#include "AvaStreamingVolumeComponent.generated.h"

class ULevelStreamingDynamic;
class UWorld;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAvaStreamingVolumeComponent : public UAvaStreamingLevelVolumeComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsExterior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExemptFromInteriorExteriorCulling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentLevelsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> LevelLODDistances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldDitherLODTransitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DependentLevelAdditionalBoundsRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSwapsPrecomputedVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentSpringLevelsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentSummerLevelsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentFallLevelsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentWinterLevelsToStream;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelLodToStream0;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelLodToStream1;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelLodToStream2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LodLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULevelStreamingDynamic*> LoadedDependentLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULevelStreamingDynamic*> LoadedDependentSeasonLevels;
    
    UAvaStreamingVolumeComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateSeasonState();
    
    UFUNCTION(BlueprintCallable)
    void SetShouldBeVisible(bool InShouldBeVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetShouldBeLoaded(bool InShouldBeLoaded);
    
    UFUNCTION()
    void SetLodTime(double InLodTime);
    
    UFUNCTION(BlueprintCallable)
    void SetLodLevel(int32 InLodLevel);
    
    UFUNCTION(BlueprintCallable)
    void ProposeLodLevel(int32 InLodLevel, FVector2D InBorderDist);
    
    UFUNCTION(BlueprintCallable)
    void PropagateState();
    
    UFUNCTION(BlueprintCallable)
    bool GetShouldBeVisible();
    
    UFUNCTION(BlueprintCallable)
    bool GetShouldBeLoaded();
    
    UFUNCTION(BlueprintCallable)
    int32 GetProposedLodLevel();
    
    UFUNCTION()
    double GetLodTime();
    
    UFUNCTION(BlueprintCallable)
    int32 GetLodLevel();
    
    UFUNCTION(BlueprintCallable)
    TArray<float> GetLODDistances();
    
    UFUNCTION(BlueprintCallable)
    ULevelStreamingDynamic* GetLoadedLevel();
    
    UFUNCTION(BlueprintCallable)
    void ForceUnload();
    
    UFUNCTION(BlueprintCallable)
    void ForceLoad();
    
    UFUNCTION()
    bool CommitLodLevel(double InLodTime);
    
};

