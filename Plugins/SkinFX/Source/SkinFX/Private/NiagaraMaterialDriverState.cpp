#include "NiagaraMaterialDriverState.h"

FNiagaraMaterialDriverState::FNiagaraMaterialDriverState() {
    this->NiagaraComponent = NULL;
    this->Age = 0.00f;
    this->bOwnsComponent = false;
    this->bSystemFinished = false;
}

