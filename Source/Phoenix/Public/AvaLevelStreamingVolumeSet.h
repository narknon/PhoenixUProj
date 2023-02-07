#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AvaStreamingVolumeSet.h"
#include "AvaLevelStreamingVolumeSet.generated.h"

class AActor;
class ULevelStreamingDynamic;
class UObject;
class UWorld;

UCLASS(Blueprintable)
class PHOENIX_API AAvaLevelStreamingVolumeSet : public AAvaStreamingVolumeSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsExterior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExemptFromInteriorExteriorCulling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSwapsPrecomputedVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentLevelsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DependentLevelAdditionalBoundsRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LevelPlacementActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> LevelLODDistances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldDitherLODTransitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentSpringLevelsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentSummerLevelsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentFallLevelsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> DependentWinterLevelsToStream;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> LevelLodToStream0;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> LevelLodToStream1;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> LevelLodToStream2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelStreamingDynamic* LoadedLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULevelStreamingDynamic*> LoadedDependentLevels;
    
    AAvaLevelStreamingVolumeSet();
    UFUNCTION(BlueprintCallable)
    void SetShouldBeVisible(bool InShouldBeVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetShouldBeLoaded(bool InShouldBeLoaded);
    
    UFUNCTION(BlueprintCallable)
    TArray<float> GetLODDistances();
    
    UFUNCTION(BlueprintCallable)
    ULevelStreamingDynamic* GetLoadedLevel();
    
    UFUNCTION(BlueprintCallable)
    FRotator GetLevelRot();
    
    UFUNCTION(BlueprintCallable)
    FVector GetLevelLoc();
    
    UFUNCTION(BlueprintCallable)
    void ForceUnload();
    
    UFUNCTION(BlueprintCallable)
    void ForceLoad();
    
};

