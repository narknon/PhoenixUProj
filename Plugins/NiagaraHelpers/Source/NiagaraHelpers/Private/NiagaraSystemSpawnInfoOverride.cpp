#include "NiagaraSystemSpawnInfoOverride.h"

FNiagaraSystemSpawnInfoOverride::FNiagaraSystemSpawnInfoOverride() {
    this->bOverride_LocationOrOffset = false;
    this->bOverride_Rotator = false;
    this->bOverride_Scale = false;
    this->bOverride_bAutoActivate = false;
    this->bOverride_bAutoDestroy = false;
    this->bOverride_bPreCullCheck = false;
    this->bOverride_bPooled = false;
    this->bAutoActivate = false;
    this->bAutoDestroy = false;
    this->bPreCullCheck = false;
    this->bPooled = false;
}

