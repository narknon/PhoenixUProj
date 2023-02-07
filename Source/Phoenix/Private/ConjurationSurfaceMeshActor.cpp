#include "ConjurationSurfaceMeshActor.h"
#include "Components/BoxComponent.h"
#include "ConjurationSurfaceMeshComponent.h"

void AConjurationSurfaceMeshActor::BuildMesh() {
}

AConjurationSurfaceMeshActor::AConjurationSurfaceMeshActor() {
    this->VolumeComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("VolumeComponent"));
    this->SurfaceMeshComponent = CreateDefaultSubobject<UConjurationSurfaceMeshComponent>(TEXT("SurfaceMeshComponent"));
}

