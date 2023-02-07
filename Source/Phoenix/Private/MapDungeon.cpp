#include "MapDungeon.h"

class AMapDungeonActor;
class UDungeonMapScreen;

UDungeonMapScreen* UMapDungeon::GetMapScreenWidget() {
    return NULL;
}

AMapDungeonActor* UMapDungeon::GetDungeonMapActor() {
    return NULL;
}

void UMapDungeon::DungeonShowAll(bool Show) {
}

UMapDungeon::UMapDungeon() {
    this->DungeonMapActor = NULL;
    this->MapNavActorClass = NULL;
    this->MapWidget = NULL;
    this->DefaultIconScale = 4.00f;
    this->MapIconTier4ScaleFactor = 0.75f;
    this->MaxZoomDistance = 30000.00f;
    this->MaxRadius = 20000.00f;
    this->CursorScale = 20.00f;
    this->CursorScaleFactor = -30.00f;
}

