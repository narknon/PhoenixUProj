#include "NonUniformSplineComponent.h"

void UNonUniformSplineComponent::InitializeFromPoints(const TArray<FVector>& InPoints) {
}

float UNonUniformSplineComponent::GetTimeAtDistance(float Distance) const {
    return 0.0f;
}

FVector UNonUniformSplineComponent::GetTangent(float NormalizedTime) const {
    return FVector{};
}

float UNonUniformSplineComponent::GetSplineLength() const {
    return 0.0f;
}

FVector UNonUniformSplineComponent::GetPositionAtDistanceAlongSpline(float Distance) const {
    return FVector{};
}

FVector UNonUniformSplineComponent::GetPosition(float NormalizedTime) const {
    return FVector{};
}

float UNonUniformSplineComponent::GetDistance(float NormalizedTime) const {
    return 0.0f;
}

float UNonUniformSplineComponent::FindNearestTimeOnSpline(const FVector& InLocation) const {
    return 0.0f;
}

FVector UNonUniformSplineComponent::FindNearestPointOnSpline(const FVector& InLocation) const {
    return FVector{};
}

float UNonUniformSplineComponent::FindClosestDistanceSqToSpline(const FVector& InLocation) const {
    return 0.0f;
}

void UNonUniformSplineComponent::DebugDraw(int32 SegmentsPerPoint, float Duration, bool bDrawTangents, bool bDrawArtificialEndPoints, bool bDrawDistances, FVector PruneCenterpoint, float PruneOutsideCenterpointRadius) const {
}

UNonUniformSplineComponent::UNonUniformSplineComponent() {
    this->ParameterizationExponent = 0.50f;
    this->DistanceSamplesPerInterval = 10;
}

