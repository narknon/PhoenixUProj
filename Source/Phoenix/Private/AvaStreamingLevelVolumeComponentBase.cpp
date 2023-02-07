#include "AvaStreamingLevelVolumeComponentBase.h"

FRotator UAvaStreamingLevelVolumeComponentBase::GetLevelRot() {
    return FRotator{};
}

FVector UAvaStreamingLevelVolumeComponentBase::GetLevelLoc() {
    return FVector{};
}

UAvaStreamingLevelVolumeComponentBase::UAvaStreamingLevelVolumeComponentBase() {
    this->LevelPlacementActor = NULL;
    this->LoadedLevel = NULL;
}

