#include "FlockingActor.h"
#include "Components/StaticMeshComponent.h"

void AFlockingActor::SetFlockingStrength(float Strength) {
}

void AFlockingActor::SetAdjustableParameters(FFlockingParametersAdjustable Parameters, float BlendTimeSeconds) {
}

void AFlockingActor::Reset() {
}

FFlockingParametersAdjustable AFlockingActor::LerpFlockingParameters(FFlockingParametersAdjustable A, FFlockingParametersAdjustable B, float Alpha) {
    return FFlockingParametersAdjustable{};
}

void AFlockingActor::GetAdjustableParameters(FFlockingParametersAdjustable& Parameters) const {
}

void AFlockingActor::Generate() {
}

AFlockingActor::AFlockingActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Leader = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeaderMesh"));
    this->bEnableCollisions = false;
    this->bEnableFlocking = true;
    this->FlockingStrength = 1.00f;
    this->bEnablePersonalities = true;
}

