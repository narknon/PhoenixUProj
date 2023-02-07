#include "Spawn_CameraActor.h"

USpawn_CameraActor::USpawn_CameraActor() {
    this->CameraType = ESpawnCameraActorType::StackCamera;
    this->bFixedAspectRatio = false;
}

