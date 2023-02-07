#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "NonUniformSplineComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FXUTIL_API UNonUniformSplineComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParameterizationExponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DistanceSamplesPerInterval;
    
    UNonUniformSplineComponent();
    UFUNCTION(BlueprintCallable)
    void InitializeFromPoints(const TArray<FVector>& InPoints);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeAtDistance(float Distance) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetTangent(float NormalizedTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSplineLength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPositionAtDistanceAlongSpline(float Distance) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPosition(float NormalizedTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDistance(float NormalizedTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float FindNearestTimeOnSpline(const FVector& InLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector FindNearestPointOnSpline(const FVector& InLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float FindClosestDistanceSqToSpline(const FVector& InLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void DebugDraw(int32 SegmentsPerPoint, float Duration, bool bDrawTangents, bool bDrawArtificialEndPoints, bool bDrawDistances, FVector PruneCenterpoint, float PruneOutsideCenterpointRadius) const;
    
};

