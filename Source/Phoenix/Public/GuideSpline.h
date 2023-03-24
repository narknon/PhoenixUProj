#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "GuideSplineTrajectory.h"
#include "GuideSpline.generated.h"

class UNonUniformSplineComponent;
class USplineComponent;

UCLASS(Blueprintable)
class AGuideSpline : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeOutPeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumDistanceFromPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumDistanceFromPlayerMounted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DestinationArrivalDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightAdjustCollissionPassRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinHeightOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHeightOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHeightTurnDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShootForwardOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D LoopSideOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoopAroundYawThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoopAroundPitchThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SplineStartRestoreAngleThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RoughTimeBetweenAdjustStartAndVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RoughTimeBetweenInitializeAndVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuideSplineTrajectory Trajectory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ResimulationNumBufferPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DrawDebugSegmentsPerPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNonUniformSplineComponent* BaseSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SmoothedSpline;
    
    AGuideSpline(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RemovePath();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PreparePathRemoval();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPathInitialized();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPathArrived();
    
    UFUNCTION(BlueprintCallable)
    void InitializeFromPath(const TArray<FVector>& Path);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FVector> GetTrajectoryPoints() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void CompletePathRemoval();
    
};

