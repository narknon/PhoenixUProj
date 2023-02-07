#include "ForegeableSpawnerManager.h"

class AActor;
class AForagable;
class UForegeableSpawnerManager;

void UForegeableSpawnerManager::UnregisterInstance(AActor* Instance) {
}

void UForegeableSpawnerManager::RegisterInstance(AActor* Instance, bool bShouldSetInitialState) {
}

void UForegeableSpawnerManager::OnForageableCollected(AForagable* Actor) {
}

void UForegeableSpawnerManager::OnBreakableDestroyed(AActor* Actor) {
}

bool UForegeableSpawnerManager::InDungeon() {
    return false;
}

UForegeableSpawnerManager* UForegeableSpawnerManager::Get() {
    return NULL;
}

UForegeableSpawnerManager::UForegeableSpawnerManager() {
    this->Pool = NULL;
}

