#include "NiagaraSystemSpawnAttachedInfoOverride.h"

FNiagaraSystemSpawnAttachedInfoOverride::FNiagaraSystemSpawnAttachedInfoOverride() {
    this->bOverride_AttachLocation = false;
    this->AttachLocation = EAttachLocation::KeepRelativeOffset;
}

