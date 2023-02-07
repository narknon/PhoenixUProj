#include "SpawnerComponent.h"

class AActor;

void USpawnerComponent::StopSpawning(const FName& GroupName) {
}

void USpawnerComponent::StartSpawning(const FName& GroupName) {
}

bool USpawnerComponent::IsSpawning(const FName& GroupName) const {
    return false;
}

void USpawnerComponent::EventOnFinishedSpawningAtSpawnLocation(const FName& GroupName) {
}

void USpawnerComponent::EventOnActorSpawnedAtSpawnLocation(AActor* SpawnedActor, const FName& GroupName) {
}

USpawnerComponent::USpawnerComponent() {
}

