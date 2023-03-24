#include "MercunaNavModifierVolume.h"

class AMercunaNavOctree;

void AMercunaNavModifierVolume::SetUsageTypes(const FMercunaNavUsageTypes& NewUsageTypes) {
}

void AMercunaNavModifierVolume::SetSize(FVector Size) {
}

void AMercunaNavModifierVolume::SetLocationAndSize(FVector Location, FVector Size) {
}

void AMercunaNavModifierVolume::SetLocation(FVector Location) {
}

void AMercunaNavModifierVolume::SetEnabled(bool Enabled) {
}

void AMercunaNavModifierVolume::SetCostMultiplier(float NewCostMultiplier) {
}

void AMercunaNavModifierVolume::AddToOctree(AMercunaNavOctree* NewNavOctree) {
}

AMercunaNavModifierVolume::AMercunaNavModifierVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnabled = true;
    this->CostMultiplier = 1.00f;
    this->CostMultipler = 1.00f;
    this->NavOctree = NULL;
}

