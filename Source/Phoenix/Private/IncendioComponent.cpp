#include "IncendioComponent.h"
#include "Components/SphereComponent.h"

bool UIncendioComponent::IsPointOnFire(FVector Point, bool LimitToRing) const {
    return false;
}

bool UIncendioComponent::IsComplete() const {
    return false;
}

UIncendioComponent::UIncendioComponent() {
    this->InitialRadius = 10.00f;
    this->RingWidth = 10.00f;
    this->BurnRate = 5.00f;
    this->BurnRateScale = 1.00f;
    this->JumpDistance = 60.00f;
    this->ParticleSpawnRateScale = 1.00f;
    this->ContainmentSphere = CreateDefaultSubobject<USphereComponent>(TEXT("FireSphere"));
    this->MaterialPropertyData = NULL;
    this->OrigMeshComponent = NULL;
}

