#include "DebugMapVolumeActor.h"

ADebugMapVolumeActor::ADebugMapVolumeActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VolumeDynamicMaterial = NULL;
    this->VolumeMaterial = NULL;
    this->DebugVolumeComponent = NULL;
}

