#include "MapDungeonActor.h"

AMapDungeonActor::AMapDungeonActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DungeonMaterialDynamic = NULL;
    this->DungeonMaterial = NULL;
    this->MapDungeonComponent = NULL;
    this->CurrentLayer = 0;
}

