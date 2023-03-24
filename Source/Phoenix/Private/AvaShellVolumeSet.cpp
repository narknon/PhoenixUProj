#include "AvaShellVolumeSet.h"

AAvaShellVolumeSet::AAvaShellVolumeSet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LevelPlacementActor = NULL;
    this->VolumeToIntersectAgainsStreamingVolumes = NULL;
    this->LoadedLevel = NULL;
}

