#include "OverlandPathFinder.h"

void UOverlandPathFinder::RoadSplineTileLoadedCallback() {
}

void UOverlandPathFinder::MapCreateRoadSplineData() {
}

TArray<FVector> UOverlandPathFinder::GetPath() {
    return TArray<FVector>();
}

UOverlandPathFinder::UOverlandPathFinder() {
    this->ClosestPathToStart = NULL;
    this->ClosestPathToEnd = NULL;
    this->MaxSpliceDistance = 500.00f;
    this->ShowUnknownRoads = true;
    this->AllRoads = NULL;
    this->AllFlights = NULL;
}

