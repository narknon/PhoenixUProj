#include "NiagaraSystemSpawnBoundsSpawnRate.h"

FNiagaraSystemSpawnBoundsSpawnRate::FNiagaraSystemSpawnBoundsSpawnRate() {
    this->ReferenceMeasure = 0.00f;
    this->LinearPower = 0.00f;
    this->MinSpawnRate = 0.00f;
    this->MaxSpawnRate = 0.00f;
    this->Method = ENiagaraSpawnBoundsMethod::Disabled;
    this->bUseMinSpawnRate = false;
    this->bUseMaxSpawnRate = false;
}

