#include "InstancedTrailActor.h"
#include "Components/InstancedStaticMeshComponent.h"

void AInstancedTrailActor::Reset() {
}

void AInstancedTrailActor::Regenerate() {
}

AInstancedTrailActor::AInstancedTrailActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxMeshes = 256;
    this->TrailMemberMesh = NULL;
    this->spacing = 25.00f;
    this->RandomizeSpacingPercent = 20.00f;
    this->Burst = 1;
    this->bEnabled = true;
    this->TrailMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("TrailMeshes"));
    this->NextTrailMember = 0;
}

