#include "AvaStreamingVolumeSet.h"
#include "Components/SceneComponent.h"

class UAvaStreamingVolumeComponentBase;

void AAvaStreamingVolumeSet::SetForcedStateStatus(bool bForced) {
}

bool AAvaStreamingVolumeSet::IsStateForced() {
    return false;
}

UAvaStreamingVolumeComponentBase* AAvaStreamingVolumeSet::GetMaster() {
    return NULL;
}

AAvaStreamingVolumeSet::AAvaStreamingVolumeSet() {
    this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->bHidesWithTiles = false;
    this->bShouldAffectTileStreaming = false;
    this->bPauseTileStreaming = false;
    this->TileRenderingMaxLod = 3;
    this->AdditionalBoundsRadius = 0.00f;
    this->bPreventExteriorRendering = false;
    this->bIgnoreShellVolumes = false;
    this->VolumeLoadIdentifier = EVolumeLoadIdentifier::OutsideOnly;
}

