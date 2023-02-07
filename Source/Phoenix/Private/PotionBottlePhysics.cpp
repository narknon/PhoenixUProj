#include "PotionBottlePhysics.h"
#include "Components/StaticMeshComponent.h"

APotionBottlePhysics::APotionBottlePhysics() {
    this->PotionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PotionStaticMesh"));
    this->FadeDelay = 3.00f;
    this->FadeDuration = 1.50f;
}

