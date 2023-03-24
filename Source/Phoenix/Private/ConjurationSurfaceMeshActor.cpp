#include "ConjurationSurfaceMeshActor.h"
#include "Components/BoxComponent.h"
#include "ConjurationSurfaceMeshComponent.h"

void AConjurationSurfaceMeshActor::BuildMesh() {
}

AConjurationSurfaceMeshActor::AConjurationSurfaceMeshActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VolumeComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("VolumeComponent"));
    this->SurfaceMeshComponent = CreateDefaultSubobject<UConjurationSurfaceMeshComponent>(TEXT("SurfaceMeshComponent"));
}

