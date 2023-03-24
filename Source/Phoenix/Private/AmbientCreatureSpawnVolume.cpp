#include "AmbientCreatureSpawnVolume.h"

class AActor;

void AAmbientCreatureSpawnVolume::OnEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void AAmbientCreatureSpawnVolume::OnBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

AAmbientCreatureSpawnVolume::AAmbientCreatureSpawnVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VolumeType = EAmbientCreatureSpawnVolumeType::Spawn;
    this->VolumePriority = EAmbientCreatureSpawnVolumePriority::Base;
    this->RangeMultiplier = 1.00f;
    this->bSuppressSpawning = false;
}

