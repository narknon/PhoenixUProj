#include "WorldMapBoundsVolume.h"

AWorldMapBoundsVolume::AWorldMapBoundsVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IsWorldMap = false;
    this->MapName = TEXT("DefaultMap");
}

