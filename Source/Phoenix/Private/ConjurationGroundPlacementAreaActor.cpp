#include "ConjurationGroundPlacementAreaActor.h"
#include "ConjurationGroundPlacementAreaComponent.h"

void AConjurationGroundPlacementAreaActor::BuildMesh() {
}

AConjurationGroundPlacementAreaActor::AConjurationGroundPlacementAreaActor() {
    this->GroundPlacementAreaComponent = CreateDefaultSubobject<UConjurationGroundPlacementAreaComponent>(TEXT("GroundPlacementAreaComponent"));
}

