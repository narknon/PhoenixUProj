#include "NPC_Spline.h"
#include "Components/SplineComponent.h"

ANPC_Spline::ANPC_Spline(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bDrawUpArrows = true;
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
}

