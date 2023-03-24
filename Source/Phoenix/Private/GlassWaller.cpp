#include "GlassWaller.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SplineComponent.h"

bool AGlassWaller::WithEditor() {
    return false;
}

void AGlassWaller::SetMobility(EComponentMobility::Type InMobility) {
}

AGlassWaller::AGlassWaller(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline Component"));
    this->InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Instanced Static Mesh Component"));
    this->NavigationGeometryGatheringMode = ENavDataGatheringMode::Default;
    this->bDisableWhenPlayerMounted = false;
}

