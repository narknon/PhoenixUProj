#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "EMerOctreeDebugDrawMode.h"
#include "MercunaNavOctree.generated.h"

class AMercunaNavModifierVolume;
class UMerNavOctreeRenderingComponent;
class UMercunaOctreeSettings;
class UMercunaPath;
class UMercunaSpline;

UCLASS(Blueprintable)
class MERCUNA_API AMercunaNavOctree : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMercunaRebuildComplete, AActor*, Volume);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMercunaLoadComplete);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMercunaBuildComplete);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMercunaOctreeSettings* SettingsOverride;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CellSize;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinPawnRadius;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxPawnRadius;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeverSave;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowOctreeMerging;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> GeometryCollisionChannel;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecordOctreeDeltas;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaBuildComplete OnBuildComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaBuildComplete OnBuildLowResReady;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaRebuildComplete OnRebuildComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaRebuildComplete OnRebuildLowResReady;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaLoadComplete OnLoadComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaLoadComplete OnShortRangeLoadComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EMerOctreeDebugDrawMode DebugDrawMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMerNavOctreeRenderingComponent* MerNavOctreeRenderingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBuildAsSublevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsRebuild;
    
public:
    AMercunaNavOctree();
    UFUNCTION(BlueprintCallable)
    void UpdateModifierVolumeParams(AMercunaNavModifierVolume* ModifierVolume);
    
    UFUNCTION(BlueprintCallable)
    void SetNavigationRotation(const FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable)
    void RemoveModifierVolume(AMercunaNavModifierVolume* ModifierVolume);
    
    UFUNCTION(BlueprintCallable)
    void RebuildVolumes(const TArray<FBox>& Volumes, bool StagedBuild);
    
    UFUNCTION(BlueprintCallable)
    void RebuildActorVolume(AActor* Volume, bool StagedBuild);
    
    UFUNCTION(BlueprintCallable)
    void Raycast(FVector Start, FVector End, float NavigationRadius, FVector& HitPosition, bool& RayHit);
    
    UFUNCTION(BlueprintCallable)
    bool IsReachableSingle(FVector Start, FVector End, float NavigationRadius, float MaxPathLength);
    
    UFUNCTION(BlueprintCallable)
    bool IsReachable(FVector Start, FVector End, float NavigationRadius, float MaxPathLength, bool AccuratePathLength);
    
    UFUNCTION(BlueprintCallable)
    void IsNavigableMulti(const TArray<FVector>& Positions, float NavigationRadius, TArray<bool>& Results);
    
    UFUNCTION(BlueprintCallable)
    void IsNavigable(FVector Position, float NavigationRadius, bool& Result);
    
    UFUNCTION(BlueprintCallable)
    UMercunaSpline* FindSplineToLocation(FVector Start, FVector End, float NavigationRadius, float MaxSpeed, float MaxAcceleration, bool AllowPartial, float MaxPathLength);
    
    UFUNCTION(BlueprintCallable)
    UMercunaPath* FindPathToLocation(FVector Start, FVector End, float NavigationRadius, bool AllowPartial, float MaxPathLength);
    
    UFUNCTION(BlueprintCallable)
    UMercunaPath* FindPathToActor(FVector Start, AActor* GoalActor, float NavigationRadius, bool AllowPartial, float MaxPathLength);
    
    UFUNCTION(BlueprintCallable)
    void ClampToNavigable(FVector Position, float NavigationRadius, float SearchRadius, FVector& ClampedPosition, bool& Result);
    
    UFUNCTION(BlueprintCallable)
    void CheckReachable(FVector Start, FVector End, float NavigationRadius, float MaxPathLength, bool& Result);
    
    UFUNCTION(BlueprintCallable)
    void Build();
    
};

