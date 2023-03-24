#include "SpawnLocation.h"

void ASpawnLocation::StopSpawning(const FName& GroupIn) {
}

void ASpawnLocation::StartSpawningUsingProbability(const FSpawnProperties& SpawnProperiesIn, const FName& GroupIn, float& SpawnProbability, const int32& NumActorsPerClassIn, int32 InFirstActorGroupIndex) {
}

void ASpawnLocation::StartSpawning(const FSpawnProperties& SpawnProperiesIn, const FName& GroupIn) {
}

void ASpawnLocation::SetSpawnCategorySelection(const FString& InSpawnCatType) {
}

bool ASpawnLocation::IsSpawning(const FName& GroupIn) const {
    return false;
}

void ASpawnLocation::InitScatterGrid() {
}

void ASpawnLocation::CacheVolumeBounds() {
}

ASpawnLocation::ASpawnLocation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnVolumeType = ESpawnVolumeType::Point;
    this->SpawnVolume = NULL;
    this->bEnableScatterSampling = false;
    this->bEnableRandomRotation = false;
    this->bSpawnOnNavMesh = false;
    this->bForceSpawnOnFloor = false;
    this->GridCols = 0;
    this->GridRows = 0;
    this->DebugTextVisualizer = NULL;
}

