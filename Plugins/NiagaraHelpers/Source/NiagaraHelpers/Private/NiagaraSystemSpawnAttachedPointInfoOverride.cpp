#include "NiagaraSystemSpawnAttachedPointInfoOverride.h"

FNiagaraSystemSpawnAttachedPointInfoOverride::FNiagaraSystemSpawnAttachedPointInfoOverride() {
    this->bOverride_AttachPoint = false;
    this->bOverride_FailOnAttachPointMissing = false;
    this->bOverride_DeepSearchComponents = false;
    this->bFailOnAttachPointMissing = false;
    this->bDeepSearchComponents = false;
}

