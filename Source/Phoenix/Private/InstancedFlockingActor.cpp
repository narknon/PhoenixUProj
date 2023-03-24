#include "InstancedFlockingActor.h"
#include "Components/InstancedStaticMeshComponent.h"

void AInstancedFlockingActor::StartFade() {
}

void AInstancedFlockingActor::SetFlockingStrength(float Strength) {
}

void AInstancedFlockingActor::SetAdjustableParameters(FFlockingParametersAdjustable Parameters, float BlendTimeSeconds) {
}

void AInstancedFlockingActor::Reset() {
}

void AInstancedFlockingActor::GetAdjustableParameters(FFlockingParametersAdjustable& Parameters) const {
}

void AInstancedFlockingActor::Generate() {
}

AInstancedFlockingActor::AInstancedFlockingActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FlockMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("FlockMeshes"));
    this->bEnableCollisions = false;
    this->bEnableFlocking = true;
    this->FlockingStrength = 1.00f;
    this->bFlockFade = false;
    this->bEnablePersonalities = true;
    this->Age = 0.00f;
    this->FlockFadeRadius = 0.00f;
    this->FlockOriginalMaterial = NULL;
    this->FlockFadeMaterial = NULL;
}

