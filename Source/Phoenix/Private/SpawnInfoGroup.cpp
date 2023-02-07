#include "SpawnInfoGroup.h"

FSpawnInfoGroup::FSpawnInfoGroup() {
    this->SpawnType = NULL;
    this->MinDelayBetweenSpawns = 0.00f;
    this->MaxDelayBetweenSpawns = 0.00f;
    this->InstanceCount = 0;
    this->TargetCount = 0;
    this->SpawnState = EDynamicObjectSpawnerState::Inactive;
}

