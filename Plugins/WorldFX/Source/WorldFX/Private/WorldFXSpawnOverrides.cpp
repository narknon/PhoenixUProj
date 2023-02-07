#include "WorldFXSpawnOverrides.h"

FWorldFXSpawnOverrides::FWorldFXSpawnOverrides() {
    this->AttachLocation = EAttachLocation::KeepRelativeOffset;
    this->bOverride_AttachTo = false;
    this->bOverride_AttachName = false;
    this->bOverride_UniqueAttachTag = false;
    this->bOverride_AttachLocation = false;
}

