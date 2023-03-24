#include "BroomSpline.h"
#include "Components/SplineComponent.h"

void ABroomSpline::GetSplinePointWorldPositions(TArray<FVector>& OutSplinePathPoints) {
}

void ABroomSpline::CopySelectedSpline() {
}

ABroomSpline::ABroomSpline(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
}

