#include "TesselatedPlane.h"
#include "TesselatedPlaneComponent.h"

void ATesselatedPlane::Construct() {
}

ATesselatedPlane::ATesselatedPlane(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PlaneMesh = CreateDefaultSubobject<UTesselatedPlaneComponent>(TEXT("GeneratedPlaneMesh"));
    this->bUseDynamicMaterial = false;
    this->PlaneDynamicMaterial = NULL;
}

