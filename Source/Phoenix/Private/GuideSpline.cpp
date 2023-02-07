#include "GuideSpline.h"
#include "Components/SplineComponent.h"
#include "NonUniformSplineComponent.h"

void AGuideSpline::RemovePath() {
}




void AGuideSpline::InitializeFromPath(const TArray<FVector>& Path) {
}

TArray<FVector> AGuideSpline::GetTrajectoryPoints() const {
    return TArray<FVector>();
}

void AGuideSpline::CompletePathRemoval() {
}

AGuideSpline::AGuideSpline() {
    this->TimeOutPeriod = 0.00f;
    this->MaximumDistanceFromPlayer = 1500.00f;
    this->MaximumDistanceFromPlayerMounted = 5000.00f;
    this->DestinationArrivalDistance = 300.00f;
    this->HeightAdjustCollissionPassRange = 30000.00f;
    this->MinHeightOffset = 100.00f;
    this->MaxHeightOffset = 200.00f;
    this->MaxHeightTurnDepth = 500.00f;
    this->ShootForwardOffset = 100.00f;
    this->LoopAroundYawThreshold = 20.00f;
    this->LoopAroundPitchThreshold = 20.00f;
    this->SplineStartRestoreAngleThreshold = 60.00f;
    this->RoughTimeBetweenAdjustStartAndVFX = 0.10f;
    this->RoughTimeBetweenInitializeAndVFX = 0.60f;
    this->ResimulationNumBufferPoints = 5;
    this->DrawDebugSegmentsPerPoint = 10;
    this->BaseSpline = CreateDefaultSubobject<UNonUniformSplineComponent>(TEXT("BaseSpline"));
    this->SmoothedSpline = CreateDefaultSubobject<USplineComponent>(TEXT("SmoothedSpline"));
}

