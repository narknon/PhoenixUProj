#include "MapData.h"

class UMapData;
class UMapLocation;

UMapLocation* UMapData::FindLocationThatContainsPoint(FVector Point, UMapLocation* StartLocation) {
    return NULL;
}

UMapLocation* UMapData::FindLocationByName(const FString& Name, UMapLocation* StartLocation) {
    return NULL;
}

int32 UMapData::FindDepthOfLocation(UMapLocation* LocationIn, UMapLocation* SearchRoot, int32 CurrentDepth) {
    return 0;
}

UMapData* UMapData::CreateMapData() {
    return NULL;
}

bool UMapData::ContainsLocation(const FString& LocationName) {
    return false;
}

bool UMapData::AddLocationInternal(UMapLocation* MapLocation, UMapLocation* Parent) {
    return false;
}

bool UMapData::AddLocation(UMapLocation* MapLocation) {
    return false;
}

UMapData::UMapData() {
    this->Root = NULL;
}

