#include "DynamicSpawnerComponent.h"

class AActor;

void UDynamicSpawnerComponent::OnSpawnFinished(const FName& GroupName) {
}

void UDynamicSpawnerComponent::OnActorSpawned(AActor* SpawnedActor, const FName& GroupName) {
}

UDynamicSpawnerComponent::UDynamicSpawnerComponent() {
    this->AllowRealTimeSpawnerGeneration = false;
    this->MyDynamicVolume = NULL;
}

