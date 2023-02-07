#include "SimpleBlobShadowDecalComponentEntry.h"

FSimpleBlobShadowDecalComponentEntry::FSimpleBlobShadowDecalComponentEntry() {
    this->bUseActorClass = false;
    this->bIncludeActorSubclasses = false;
    this->bUseMovementComponentClass = false;
    this->bIncludeMovementComponentSubclasses = false;
    this->BlobShadowDecalComponentClass = NULL;
    this->OverrideDecalMaterial = NULL;
}

