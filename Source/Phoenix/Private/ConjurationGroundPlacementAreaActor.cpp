#include "ConjurationGroundPlacementAreaActor.h"
#include "ConjurationGroundPlacementAreaComponent.h"

void AConjurationGroundPlacementAreaActor::BuildMesh() {
}

AConjurationGroundPlacementAreaActor::AConjurationGroundPlacementAreaActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GroundPlacementAreaComponent = CreateDefaultSubobject<UConjurationGroundPlacementAreaComponent>(TEXT("GroundPlacementAreaComponent"));
}

