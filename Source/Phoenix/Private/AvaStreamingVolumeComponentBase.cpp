#include "AvaStreamingVolumeComponentBase.h"

void UAvaStreamingVolumeComponentBase::SetForcedStateStatus(bool bForced) {
}

bool UAvaStreamingVolumeComponentBase::IsStateForced() {
    return false;
}

UAvaStreamingVolumeComponentBase::UAvaStreamingVolumeComponentBase() {
    this->bForcedState = false;
    this->bHidesWithTiles = false;
    this->bShouldAffectTileStreaming = false;
    this->bPauseTileStreaming = false;
    this->bSupportsDitheredLODTransition = true;
    this->TileRenderingMaxLod = 3;
    this->AdditionalBoundsRadius = 0.00f;
    this->bPreventExteriorRendering = false;
    this->bIgnoreShellVolumes = false;
    this->bIsDoorPreloadVolume = false;
    this->bActiveWithFastTravelDoors = false;
    this->VolumeLoadIdentifier = EVolumeLoadIdentifier::OutsideOnly;
}

