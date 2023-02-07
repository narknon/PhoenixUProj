#include "PhoenixTrackingVolume.h"

class AActor;

void APhoenixTrackingVolume::OnEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void APhoenixTrackingVolume::OnBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

APhoenixTrackingVolume::APhoenixTrackingVolume() {
    this->CollisionComponent = NULL;
    this->VolumeType = ETrackingVolumeType::None;
    this->VolumeSearchRadius = 2000.00f;
}

