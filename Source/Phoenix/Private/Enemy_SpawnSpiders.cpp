#include "Enemy_SpawnSpiders.h"

bool UEnemy_SpawnSpiders::Update(float InDeltaTime) {
    return false;
}

void UEnemy_SpawnSpiders::Spawn() {
}

void UEnemy_SpawnSpiders::DELETE() {
}

UEnemy_SpawnSpiders::UEnemy_SpawnSpiders() {
    this->ParentActor = NULL;
    this->SpawnCount = 10;
    this->SpawnDeviation = 3;
    this->SpawnInterval = 0.25f;
    this->SpawnAngleFromRange = 90.00f;
    this->SpawnAngleDeviation = 10.00f;
    this->SpawnDist = 50.00f;
    this->SpawnUpDist = -1.00f;
    this->SpawnLandDist = 100.00f;
    this->SpawnLandDistVariance = 20.00f;
    this->SpawnParticleSystem = NULL;
    this->SpawnParticleSystemDeath = NULL;
    this->SpawnParticleSystem2 = NULL;
    this->SpawnParticleSystemDeath2 = NULL;
}

