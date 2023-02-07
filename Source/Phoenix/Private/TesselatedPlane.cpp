#include "TesselatedPlane.h"
#include "TesselatedPlaneComponent.h"

void ATesselatedPlane::Construct() {
}

ATesselatedPlane::ATesselatedPlane() {
    this->PlaneMesh = CreateDefaultSubobject<UTesselatedPlaneComponent>(TEXT("GeneratedPlaneMesh"));
    this->bUseDynamicMaterial = false;
    this->PlaneDynamicMaterial = NULL;
}

