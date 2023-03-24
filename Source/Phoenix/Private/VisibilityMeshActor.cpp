#include "VisibilityMeshActor.h"
#include "Components/StaticMeshComponent.h"

AVisibilityMeshActor::AVisibilityMeshActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VisibilityMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("T4VisibilityMesh"));
}

