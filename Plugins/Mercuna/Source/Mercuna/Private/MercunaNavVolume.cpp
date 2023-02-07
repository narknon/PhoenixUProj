#include "MercunaNavVolume.h"

class AMercunaNavOctree;

void AMercunaNavVolume::SetSize(FVector Size) {
}

void AMercunaNavVolume::SetNavigationRotation(const FRotator& Rotation) {
}

void AMercunaNavVolume::AddToOctree(AMercunaNavOctree* NewNavOctree) {
}

AMercunaNavVolume::AMercunaNavVolume() {
    this->NavOctree = NULL;
    this->PreciseBoundaries = true;
    this->LOD = EMercunaLevelOfDetail::Full;
    this->FullDetailBuild = true;
    this->PreciseDirections.AddDefaulted(4);
}

