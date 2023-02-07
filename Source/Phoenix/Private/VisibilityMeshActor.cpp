#include "VisibilityMeshActor.h"
#include "Components/StaticMeshComponent.h"

AVisibilityMeshActor::AVisibilityMeshActor() {
    this->VisibilityMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("T4VisibilityMesh"));
}

