#include "EncounterVolume.h"

class AActor;
class ADynamicObjectVolume;

void AEncounterVolume::SetEncounterActor(ADynamicObjectVolume* InActor) {
}

void AEncounterVolume::SetAllowAutoActivation(bool bAllowAutoActivate) {
}

void AEncounterVolume::ProcessZoneData(const FString& ObjectName) {
}

void AEncounterVolume::ProcessSpawnerSearch(const FString& ObjectName) {
}

void AEncounterVolume::ProcessEncounterReport(const FString& ObjectName) {
}

bool AEncounterVolume::IsVolumeActive() {
    return false;
}

bool AEncounterVolume::HasSpawned() {
    return false;
}

int32 AEncounterVolume::GetSpawnActorCount() {
    return 0;
}

TArray<AActor*> AEncounterVolume::GetAllActiveSpawnedInstances() {
    return TArray<AActor*>();
}

int32 AEncounterVolume::GetAliveActorCount() {
    return 0;
}

int32 AEncounterVolume::GetActiveActorCount() {
    return 0;
}

void AEncounterVolume::ForceDeactivate() {
}

void AEncounterVolume::ForceActivate() {
}

bool AEncounterVolume::DoneSpawning() {
    return false;
}

AEncounterVolume::AEncounterVolume() {
    this->bShowActivationDistances = false;
    this->bEnableAutoActivation = true;
    this->TriggerDistance = 1000.00f;
    this->CullDistance = 1500.00f;
    this->TriggerCullDiff = 500.00f;
    this->bMaintainTriggerCullDistance = false;
    this->bAutoGeneratePerception = true;
    this->PerceptionRadius = 6000.00f;
    this->SpawnVolumeType = ESpawnVolumeType::Box;
    this->bForceOverrideRestriction = false;
    this->bIsCreatorEncounter = false;
    this->bAllowDataWrite = false;
    this->NumIterationsPerLevel = 1;
    this->StartPlayerLevel = 0;
    this->EndPlayerLevel = 0;
    this->LevelIncrement = 1;
    this->bIsLocationTrigger = false;
    this->VolumeComponent = NULL;
    this->bDestroyOnDeath = false;
    this->bDissolveOnDeath = false;
    this->bFadeOnDeath = false;
    this->bDoDeathCamOnLastDeath = false;
    this->bDoDeathCamBulletTime = false;
    this->bNamedEncounter = false;
    this->pEnemyPerception = NULL;
}

