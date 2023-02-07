#include "AblPlayObjectArchitectVfxTaskBase.h"

UAblPlayObjectArchitectVfxTaskBase::UAblPlayObjectArchitectVfxTaskBase() {
    this->bSpawnSystemAttached = false;
    this->bAutoDestroy = true;
    this->bDeactivateAtTaskEnd = false;
    this->bDestroyAtTaskEnd = false;
    this->bIncludeActorScale = false;
    this->AttachLocation = EAttachLocation::KeepRelativeOffset;
    this->WorldOrLocalSpace = EObjectArchitectVfxWorldLocalType::WorldSpace;
}

