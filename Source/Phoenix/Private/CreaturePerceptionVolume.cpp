#include "CreaturePerceptionVolume.h"

class AActor;

void ACreaturePerceptionVolume::OnEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void ACreaturePerceptionVolume::OnBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

ACreaturePerceptionVolume::ACreaturePerceptionVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VolumeType = ECreaturePerceptionVolumeType::AlwaysPerceiveInside;
}

