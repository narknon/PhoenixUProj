#include "SpawnProperties.h"

FSpawnProperties::FSpawnProperties() {
    this->ActorSelectionMode = ESpawnerActorSelectionMode::Undefined;
    this->MinActorCount = 0;
    this->MaxActorCount = 0;
    this->MinDelayBetweenSpawns = 0.00f;
    this->MaxDelayBetweenSpawns = 0.00f;
    this->bApplyAdditionalDelay = false;
    this->AdditionalDelay = 0.00f;
}

