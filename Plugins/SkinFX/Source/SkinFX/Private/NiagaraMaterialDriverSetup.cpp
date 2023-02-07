#include "NiagaraMaterialDriverSetup.h"

FNiagaraMaterialDriverSetup::FNiagaraMaterialDriverSetup() {
    this->NiagaraSystem = NULL;
    this->MaxParameterParticles = 0;
    this->bAutoDestroy = false;
    this->InitialDelay = 0.00f;
}

