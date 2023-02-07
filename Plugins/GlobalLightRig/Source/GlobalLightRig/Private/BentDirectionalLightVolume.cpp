#include "BentDirectionalLightVolume.h"
#include "Components/BoxComponent.h"

ABentDirectionalLightVolume::ABentDirectionalLightVolume() {
    this->GlobalLightingBlendable = NULL;
    this->BoundingBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoundingBox"));
    this->Priority = 0.00f;
    this->BlendRadius = 25.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->PositionalBlendWeight = 0.00f;
}

